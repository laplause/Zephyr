///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This class defines a texture to be used by the engine and managed by the TextureManager.     //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef XMLPARSEHELPERTEXTURE_H
#define XMLPARSEHELPERTEXTURE_H

#include "IXmlParseHelper.h"
#include "XmlParseMaster.h"

namespace Core
{
	class XmlParseHelperTexture : public IXmlParseHelper
	{
	public:
		XmlParseHelperTexture(XmlParseMaster* master);
		virtual ~XmlParseHelperTexture();

		virtual void Initialize();

		virtual bool StartElementHandler(const std::string& elementName, const std::map<std::string, std::string>& attributes) const;
		virtual bool EndElementHandler(const std::string& elementName) const;
		virtual bool CharDataHandler(const char* buffer, unsigned int length) const;
		
		virtual void SetXmlParseMaster(XmlParseMaster* master);
	};
}
#endif