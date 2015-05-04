///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This class defines a texture to be used by the engine and managed by the TextureManager.     //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef XMLPARSEMASTER_H
#define XMLPARSEMASTER_H

#include "ZAssert.h"
#include "IXmlParseHelper.h"
#include "expat.h"
#include <list>

namespace Core
{
	class XmlParseMaster
	{
	public:
		class SharedData
		{
		public:
			SharedData();
			virtual ~SharedData();
			
			void SetXmlParseMaster(XmlParseMaster* parentParser);
			XmlParseMaster* GetXmlParseMaster() const;
			
			void IncrementDepth();
			void DecrementDepth();
			unsigned int Depth() const;

		protected:
			XmlParseMaster* mParentParser;
			unsigned int mNestingDepth;
		};

		XmlParseMaster(SharedData* sharedData);
		~XmlParseMaster();
		
		void AddHelper(IXmlParseHelper* helper);
		void RemoveHelper(IXmlParseHelper* helper);
		
		void Parse(const char* buffer, unsigned int bufferSize, bool atEnd);
		void ParseFromFile(std::string& fileName);
		
		std::string GetFileName();
		SharedData* GetSharedData();

	private:
		static void StartElementHandler(void* userData, const XML_Char *name, const XML_Char **atts);
		static void EndElementHandler(void *userData, const XML_Char *name);
		static void CharDataHandler(void *userData, const XML_Char *s, int len);
		
		void SetIsAClone();
		void ResetParser();

		// Function Pointers to the Handler functions.
		static const XML_StartElementHandler mStartHandle;
		static const  XML_EndElementHandler mEndHandle;
		static const  XML_CharacterDataHandler mDataHandle;

		XML_Parser mParser;
		bool mIsAClone;
		SharedData* mOutput;
		std::string mFileName;
		std::list<IXmlParseHelper*> mHelpers;
	};
}
#endif