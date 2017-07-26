#pragma once
#include <memory.h>
#include <crtdbg.h>
#include "Define.h"

template <typename T>
class DynamicArray
{
public:

	//---------------------------------------------------------------------------------------
	// Default Constructor, Sets the initial size of the dynamic array based on a 
	// passed in int value, then if the capacity is lower or equal to 0 it sets it to 1.
	// Next it creates a pointer to the specified data type variable and it set to size of
	// the capacity. Then it allocates some memory based on the size of the data type.
	// 
	// Param:
	//		initialSize: The preferred initial size of the dynamic array.
	//---------------------------------------------------------------------------------------
	DynamicArray(int initialSize = 0)
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		_ASSERT(m_pData);
		m_nCapacity = nCapacity;
		m_nUsed = 0;
		memset(&m_NullValue, 0, sizeof(T));
	}

	//---------------------------------------------------------------------------------------
	// Default Destructor / Deletes the data.
	//---------------------------------------------------------------------------------------
	~DynamicArray()
	{
		delete m_pData;
		//delete newData;
	}

	//---------------------------------------------------------------------------------------
	// Alternative Constructor, copies an existing dynamic arrays values to this array.
	// 
	// Param:
	//		other: A dynamic array.
	//---------------------------------------------------------------------------------------
	DynamicArray(const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		_ASSERT(m_pData);
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}

	//---------------------------------------------------------------------------------------
	// Pushes a value onto the back of the array.
	// 
	// Param:
	//		value: The value to be pushed onto the back of the array.
	//---------------------------------------------------------------------------------------
	void PushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();
		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	//---------------------------------------------------------------------------------------
	// Pushes a value onto the front of the array.
	// 
	// Param:
	//		value: The value to be pushed onto the front of the array.
	//---------------------------------------------------------------------------------------
	void PushFront(T value)
	{
		Insert(0, value);
	}

	//---------------------------------------------------------------------------------------
	// Inserts a value into an index in the array.
	// 
	// Param:
	//		index: The index of which the value will be inserted.
	//		value: The value to be inserted.
	// Return:
	//		Returns SUCCESS if the function executed successfully and returns OUT_OF_BOUNDS
	//				if the insert index was specified out of the bounds of the array.
	//---------------------------------------------------------------------------------------
	int Insert(int index, T value)
	{
		_ASSERT(index <= m_nUsed);

		if (index > m_nUsed)
			return OUT_OF_BOUNDS;

		if (m_nUsed >= m_nCapacity)
			Resize();

		//memcpy(m_pData + index + 1, m_pData + index, sizeof(T) * (m_nUsed - index));

		for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}

		m_pData[index] = value;
		++m_nUsed;

		return SUCCESS;
	}

	//---------------------------------------------------------------------------------------
	// Pops off the back element in the array.
	// 
	// Return:
	//		Returns 0 if the used size if under or equal to 0, 
	//				else returns m_pData[m_nUsed].
	//---------------------------------------------------------------------------------------
	T PopBack()
	{
		_ASSERT(m_nUsed > 0);

		if (m_nUsed <= 0)
			return 0;

		--m_nUsed;
		return m_pData[m_nUsed];
	}

	//---------------------------------------------------------------------------------------
	// Removes an element in the array at a specified index.
	// 
	// Param:
	//		index: The index of the element to remove.
	// Return:
	//		Returns 0 if the used size if under or equal to 0, else returns value.
	//---------------------------------------------------------------------------------------
	T Remove(int index)
	{
		_ASSERT(index <= m_nUsed);

		if (index >= m_nUsed)
			return 0;
		//Back value that we are removing from array
		T value = m_pData[index];

		//shuffle all other values across to fill removed space
		for (int i = index; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		//return removed value
		return value;
	}

	//---------------------------------------------------------------------------------------
	// Pops off the front element in the array.
	// 
	// Return:
	//		Returns the Remove function passing in 0.
	//---------------------------------------------------------------------------------------
	T PopFront()
	{
		return Remove(0);
	}

	//---------------------------------------------------------------------------------------
	// Clears all elements in the array by setting m_nUsed to 0.
	//---------------------------------------------------------------------------------------
	void Clear()
	{
		m_nUsed = 0;
	}

	//---------------------------------------------------------------------------------------
	// Shrinks the array to the size of how many elements exist.
	//---------------------------------------------------------------------------------------
	void Shrink()
	{
		int nCapacity = m_nUsed;
		_ASSERT(nCapacity > 0);
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[m_nUsed];
		_ASSERT(newData);
		memcpy(newData, m_pData, sizeof(T) * m_nUsed);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = m_nUsed;
	}

	//---------------------------------------------------------------------------------------
	// Overloading the subscript operator.
	// 
	// Param:
	//		index: Takes an const int that represents the index.
	// Return:
	//		Returns m_NullValue or m_pData[index] based on if the index is lower than m_nUsed
	//---------------------------------------------------------------------------------------
	T& operator[](const int index)
	{
		_ASSERT(index < m_nUsed);
		if (index >= m_nUsed)
			return m_NullValue;

		return m_pData[index];
	}
	
	//---------------------------------------------------------------------------------------
	// Returns the size of the array.
	// 
	// Return:
	//		Returns m_nUsed which is the size of the array.
	//---------------------------------------------------------------------------------------
	int Size()
	{
		return m_nUsed;
	}

	//---------------------------------------------------------------------------------------
	// Returns the capacity of the array.
	// 
	// Return:
	//		Returns m_nCapacity which is the capacity of the array.
	//---------------------------------------------------------------------------------------
	int Capacity()
	{
		return m_nCapacity;
	}

private:

	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;


	//---------------------------------------------------------------------------------------
	// Resized the array based on the current capacity.
	//---------------------------------------------------------------------------------------
	void Resize()
	{
		//Creates new array that is twice as big
		T* newData = new T[m_nCapacity * 2];
		_ASSERT(newData);
		//copy old data acriss ubit new attay
		memcpy(newData, m_pData, sizeof(T) * m_nCapacity);

		//Delete old array
		delete m_pData;

		//Make sure our pointers still work
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	}

	int m_nCapacity;
	int m_nUsed;
	T* m_pData;
	T m_NullValue;
};