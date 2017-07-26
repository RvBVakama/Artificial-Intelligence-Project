#pragma once
#include "DynamicArray.h"
#include <string.h>
#include "Resource.h"

template<typename T>
class ResourceManager
{
public:

	//--------------------------------------------------------------------------------------
	// Loads the resource with the specified file location.
	//
	// Param:
	//		szFilename: The location of the texture to be loaded.
	// Return:
	//		Returns the data at a index in the resource list.
	//--------------------------------------------------------------------------------------
	T* LoadResource (char* szFilename)
	{
		// Check if resource is already loaded
		// if so return it
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_Data;
			}
		}

		// Resource is not loaded, so load it
		Resource<T>* pResource = new Resource<T>(szFilename);
		_ASSERT(pResource);
		m_ResourceList.PushBack(pResource);
		return pResource->m_Data;
	}

	//--------------------------------------------------------------------------------------
	// Unloads all resources.
	//--------------------------------------------------------------------------------------
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.Clear();
	}

	//--------------------------------------------------------------------------------------
	// Creates the resource manager.
	//--------------------------------------------------------------------------------------
	static void Create()
	{
		if (!m_pInstance)
			m_pInstance = new ResourceManager<T>();
			_ASSERT(m_pInstance);
	}

	//--------------------------------------------------------------------------------------
	// Destroys / Deletes the resource manager.
	//--------------------------------------------------------------------------------------
	static void Destroy()
	{
		delete m_pInstance;
	}

	//--------------------------------------------------------------------------------------
	// Creates the resource manager.
	// 
	// Return:
	//		Returns m_pInstance which is an instance of the resource manager.
	//--------------------------------------------------------------------------------------
	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

private:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	ResourceManager() {}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~ResourceManager()
	{
		UnloadAllResources();
	}

	DynamicArray<Resource<T>*> m_ResourceList;
	//std::map<std::string, std::shared_ptr<T>> m_map;
	static ResourceManager<T>* m_pInstance;
};

template<typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;