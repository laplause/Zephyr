#include "XmlParseHelperTexture.h"
#include "TextureData.h"
#include "TextureManager.h"
#include "Texture.h"
#include "ZAssert.h"
using namespace Core;
using namespace RenderCore;

XmlParseHelperTexture::XmlParseHelperTexture(XmlParseMaster* master) : IXmlParseHelper(master)
{

}

XmlParseHelperTexture::~XmlParseHelperTexture()
{

}

void XmlParseHelperTexture::Initialize()
{

}

bool XmlParseHelperTexture::StartElementHandler(const std::string& elementName, const std::map<std::string, std::string>& attributes) const
{
	if (elementName.compare("") != 0)
	{
		TextureData* tempData = (TextureData*)(mParser->GetSharedData());
		ZEPHYR_ASSERT(tempData != nullptr, "Texture Shared Data was not initialized in Texture parse helpers master");

		tempData->mTags.push(elementName);
		tempData->IncrementDepth();

		return true;
	}

	return false;
}

bool XmlParseHelperTexture::CharDataHandler(const char* buffer, unsigned int length) const
{
	if (buffer)
	{
		TextureData* tempData = (TextureData*)(mParser->GetSharedData());
		ZEPHYR_ASSERT(tempData != nullptr, "Texture Shared Data was not initialized in Texture parse helpers master");

		std::string data(buffer, length);

		if (data.compare("\n") == 0 || data.compare("\t") == 0)
		{
			return true;
		}
		else if (tempData->mTags.top().compare("Name") == 0)
		{
			tempData->mTextureName = data;
			return true;
		}
		else if (tempData->mTags.top().compare("Path") == 0)
		{
			tempData->mTextureFileName = data;
			return true;
		}
	}

	return false;
}

bool XmlParseHelperTexture::EndElementHandler(const std::string& elementName) const
{
	if (elementName.compare("") != 0)
	{
		TextureData* tempData = (TextureData*)(mParser->GetSharedData());
		ZEPHYR_ASSERT(tempData != nullptr, "Texture Shared Data was not initialized in Texture parse helpers master");

		if (elementName.compare("Texture") == 0)
		{
			if (!tempData->mTextureFileName.empty() && !tempData->mTextureName.empty())
			{
				TextureManager::GetTextureManager()->AddTextureData(tempData->mTextureName, tempData->mTextureFileName);
			}
		}

		tempData->mTags.pop();
		tempData->DecrementDepth();

		return true;
	}

	return false;
}

void XmlParseHelperTexture::SetXmlParseMaster(XmlParseMaster* master)
{
	if (master == mParser || master == nullptr)
		return;

	mParser->RemoveHelper(this);
	mParser = master;
	mParser->AddHelper(this);
}