///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This class defines a texture to be used by the engine and managed by the TextureManager.     //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TEXTUREDATA_H
#define TEXTUREDATA_H

#include "XmlParseMaster.h"
#include <stack>
#include <string>

namespace Core
{
	class TextureData : public XmlParseMaster::SharedData
	{
	public:
		TextureData();
		virtual ~TextureData();

		std::string mTextureFileName;
		std::string mTextureName;
		std::stack<std::string> mTags;
	};
}
#endif
