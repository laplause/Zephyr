#include "XmlParseMaster.h"
#include <fstream>
using namespace Core;

const XML_StartElementHandler XmlParseMaster::mStartHandle = &XmlParseMaster::StartElementHandler;
const XML_EndElementHandler XmlParseMaster::mEndHandle = &XmlParseMaster::EndElementHandler;
const XML_CharacterDataHandler XmlParseMaster::mDataHandle = &XmlParseMaster::CharDataHandler;

Core::XmlParseMaster::XmlParseMaster(SharedData* sharedData) : mParser(XML_ParserCreate(NULL)), mHelpers(), mOutput(sharedData), mIsAClone(false), mFileName()
{
	ZEPHYR_ASSERT(mOutput != nullptr, "A non-null shared data object must be provided to successfully construct");
	mOutput->SetXmlParseMaster(this);

	XML_SetElementHandler(mParser, mStartHandle, mEndHandle);
	XML_SetCharacterDataHandler(mParser, mDataHandle);
	XML_SetUserData(mParser, mOutput);
}

XmlParseMaster::~XmlParseMaster()
{
	if(mIsAClone)
	{
		for(std::list<IXmlParseHelper*>::iterator it = mHelpers.begin(); it != mHelpers.end(); it++)
		{
			if((*it))
			{
				delete (*it);
			}
		}
		
		delete mOutput;
	}

	XML_ParserFree(mParser);
}

XmlParseMaster* XmlParseMaster::Clone()
{
	SharedData *output = mOutput->Clone();
	XmlParseMaster *clone = new XmlParseMaster(output);
	clone->SetIsAClone();

	for(std::list<IXmlParseHelper*>::iterator it = mHelpers.begin(); it != mHelpers.end(); it++)
	{
		IXmlParseHelper *helper = (*it)->Clone();
		helper->SetXmlParseMaster(clone);
	}

	return &(*clone);
}

void XmlParseMaster::AddHelper(IXmlParseHelper* helper)
{
	ZEPHYR_ASSERT(helper != nullptr, "Trying to add a null pointer to helper list.");
	mHelpers.push_back(helper);
}

void XmlParseMaster::RemoveHelper(IXmlParseHelper* helper)
{
	mHelpers.remove(helper);
}

void XmlParseMaster::Parse(const char* buffer, unsigned int bufferSize, bool atEnd)
{
	XML_Parse(mParser, buffer, bufferSize, (int)atEnd);
	ResetParser();
}

void XmlParseMaster::ParseFromFile(std::string& fileName)
{
	unsigned int fileSize = 0;
	std::ifstream input(fileName, std::ios::binary);
	mFileName = fileName;

	ZEPHYR_ASSERT(input.good() == true, "Invalid file or path caused bad input stream");
	input.seekg(0, std::ios::end);
	fileSize = (unsigned int)input.tellg();
	input.seekg(0, std::ios::beg);

	char *buffer = new char[fileSize+1];
	input.read(buffer, fileSize);
	buffer[fileSize] = '\0';

	XML_Parse(mParser, buffer, fileSize, (int)true);

	delete buffer;

	ResetParser();
}

std::string XmlParseMaster::GetFileName()
{
	return mFileName;
}

XmlParseMaster::SharedData* XmlParseMaster::GetSharedData()
{
	ZEPHYR_ASSERT(mOutput != nullptr, "Trying to access null shared data.");
	return &(*mOutput);
}

void XmlParseMaster::StartElementHandler(void* userData, const XML_Char *name, const XML_Char **atts)
{
	SharedData *tempUserData = (SharedData*)userData;

	if(tempUserData)
	{
		XmlParseMaster* tempParser = tempUserData->GetXmlParseMaster();
		int numAttributes = XML_GetSpecifiedAttributeCount(tempParser->mParser);
		std::string element;
		std::map<std::string, std::string> attributeMap;

		element.append(name);

		for(int i=0; i<numAttributes; i+=2)
		{
			attributeMap.insert(std::pair<const XML_Char*, const XML_Char*>(atts[i], atts[i+1]));
		}

		for(std::list<IXmlParseHelper*>::iterator it = tempParser->mHelpers.begin(); it != tempParser->mHelpers.end(); it++)
		{
			if((*it)->StartElementHandler(element, attributeMap))
				break;
		}
	}
}

void XmlParseMaster::EndElementHandler(void *userData, const XML_Char *name)
{
	SharedData *tempUserData = (SharedData*)userData;

	if(tempUserData)
	{
		XmlParseMaster* tempParser = tempUserData->GetXmlParseMaster();
		std::string element;

		element.append(name);

		for(std::list<IXmlParseHelper*>::iterator it = tempParser->mHelpers.begin(); it != tempParser->mHelpers.end(); it++)
		{
			if((*it)->EndElementHandler(element))
				break;
		}
	}
}

void XmlParseMaster::CharDataHandler(void *userData, const XML_Char *s, int len)
{
	SharedData *tempUserData = (SharedData*)userData;

	if(tempUserData)
	{
		XmlParseMaster* tempParser = tempUserData->GetXmlParseMaster();

		for(std::list<IXmlParseHelper*>::iterator it = tempParser->mHelpers.begin(); it != tempParser->mHelpers.end(); it++)
		{
			if((*it)->CharDataHandler(s, len))
				break;
		}
	}
}

void XmlParseMaster::SetIsAClone()
{
	mIsAClone = true;
}

void XmlParseMaster::ResetParser()
{
	XML_ParserReset(mParser, NULL);
	XML_SetElementHandler(mParser, mStartHandle, mEndHandle);
	XML_SetCharacterDataHandler(mParser, mDataHandle);
	XML_SetUserData(mParser, mOutput);
}

XmlParseMaster::SharedData::SharedData() : mParentParser(NULL), mNestingDepth(0)
{

}

XmlParseMaster::SharedData::~SharedData()
{

}

XmlParseMaster::SharedData* XmlParseMaster::SharedData::Clone()
{
	SharedData *clone = new SharedData();

	return &(*clone);
}

void XmlParseMaster::SharedData::SetXmlParseMaster(XmlParseMaster* parentParser)
{
	mParentParser = parentParser;
}

XmlParseMaster* XmlParseMaster::SharedData::GetXmlParseMaster() const
{
	ZEPHYR_ASSERT(mParentParser != nullptr, "An associated parser has not yet been set.");
	return &(*mParentParser);
}

void XmlParseMaster::SharedData::IncrementDepth()
{
	mNestingDepth++;
}

void XmlParseMaster::SharedData::DecrementDepth()
{
	mNestingDepth--;
}

unsigned int XmlParseMaster::SharedData::Depth() const
{
	return mNestingDepth;
}