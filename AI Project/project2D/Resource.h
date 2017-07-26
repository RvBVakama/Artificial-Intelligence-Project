#pragma once
#include <stdlib.h>

template<typename T>
class Resource
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Resource(char* szFilename)
	{
		int length = strlen(szFilename) + 1;
		m_szFilename = new char[length];
		_ASSERT(m_szFilename);
		strcpy_s(m_szFilename, length, szFilename);
		
		m_Data = new T(szFilename);
		_ASSERT(m_Data);
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Resource()
	{
		delete[] m_szFilename;
		delete m_Data;
	}

	//--------------------------------------------------------------------------------------
	// Currently does nothing.
	//--------------------------------------------------------------------------------------
	void Clear()
	{

	}

	char* m_szFilename;
	T* m_Data;
};