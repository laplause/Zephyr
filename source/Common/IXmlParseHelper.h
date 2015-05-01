///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This class defines a texture to be used by the engine and managed by the TextureManager.     //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef IXMLPARSHELPER_H
#define IXMLPARSHELPER_H

#include <map>

namespace Core
{
	class XmlParseMaster;

	class IXmlParseHelper
	{
	public:
		IXmlParseHelper(XmlParseMaster *master);
		virtual ~IXmlParseHelper();
		virtual IXmlParseHelper* Clone() = 0;

		virtual void Initialize() = 0;
		virtual bool StartElementHandler(const std::string& elementName, const std::map<std::string, std::string>& attributes) const = 0;
		virtual bool EndElementHandler(const std::string& elementName) const = 0;
		virtual bool CharDataHandler(const char* buffer, unsigned int length) const = 0;
		
		virtual void SetXmlParseMaster(XmlParseMaster* master) = 0;

	protected:
		XmlParseMaster *mParser;
	};
}
#endif