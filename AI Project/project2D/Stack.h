#pragma once
#include "DynamicArray.h"

template <typename T>
class Stack
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Stack(int initialsize = 0)
	{
		//m_pData = new DynamicArray<T>(initialiseSize);
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Stack()
	{
		//delete m_pData;
	}

	//--------------------------------------------------------------------------------------
	// Checks if the stack is empty.
	//
	// Return:
	//		Returns true if the the stack size is equal to 0.
	//--------------------------------------------------------------------------------------
	bool IsEmpty()
	{
		return (m_pData.Size() == 0);
	}

	//--------------------------------------------------------------------------------------
	// Checks the stacks size.
	//
	// Return:
	//		Returns the stack size as an int.
	//--------------------------------------------------------------------------------------
	int Size()
	{
		return m_pData.Size();
	}

	//--------------------------------------------------------------------------------------
	// Pushes a value onto the back of the stack.
	//
	// Param:
	//		value: Pushes the passed in value onto the back of the stack.
	//--------------------------------------------------------------------------------------
	void Push(T value)
	{
		m_pData.PushBack(value);
	}

	//--------------------------------------------------------------------------------------
	// Pops the back of the stack.
	//
	// Return:
	//		Returns m_pData running the PopBack function.
	//--------------------------------------------------------------------------------------
	T Pop()
	{
		return m_pData.PopBack();
	}

	//--------------------------------------------------------------------------------------
	// Returns the top of the stack.
	//
	// Return:
	//		Returns m_pData indexed at the nTop value which is the stacks size minus 1.
	//--------------------------------------------------------------------------------------
	T Top()
	{
		int nTop = m_pData.Size() - 1;
		return m_pData[nTop];
	}

	//--------------------------------------------------------------------------------------
	// Returns the second top of the stack.
	//
	// Return:
	//		Returns m_pData indexed at the nTop value which is the stacks size minus 2.
	//--------------------------------------------------------------------------------------
	T SecondFromTop()
	{
		int nTop2 = m_pData.Size() - 2;
		return m_pData[nTop2];
	}

	DynamicArray<T> m_pData;
};
