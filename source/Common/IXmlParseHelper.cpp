#include "IXmlParseHelper.h"
#include "XmlParseMaster.h"
using namespace Core;

IXmlParseHelper::IXmlParseHelper(XmlParseMaster *master) : mParser(master)
{
	mParser->AddHelper(this);
}

IXmlParseHelper::~IXmlParseHelper()
{

}