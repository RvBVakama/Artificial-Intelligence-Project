#pragma once
#include "ListNode.h"
#include <crtdbg.h>

template <typename T>
class Iter
{
public:
	ListNode<T>* current;


	//=
	Iter& operator=(ListNode<T>* other)
	{
		//LinkedList<int> other1;
		current = other;
		return *this;
	}

	//!=
	bool operator!=(ListNode<T>* other)
	{
		if (current != other)
			return true;
		else
			return false;
	}

	//==
	bool operator==(ListNode<T>* other)
	{
		if (current == other)
			return true;
		else
			return false;
	}

	//->
	T value()
	{
		return current->data;
	}

	//++
	void operator++()
	{
		current = current->next;
	}

	//--
	void operator--()
	{
		current = current->prev;
	}
};

template <typename T>
class LinkedList
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	LinkedList()
	{
		start = new ListNode<T>();
		_ASSERT(start);
		end = new ListNode<T>();
		_ASSERT(end);

		start->next = end;
		end->prev = start;

		start->prev = nullptr;
		end->next = nullptr;
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~LinkedList()
	{
		delete end;
		delete start;
	}

	//--------------------------------------------------------------------------------------
	// Creates a node with the passed in data and an pushes it to the front of the array.
	//
	// Param:
	//		data: Data to be assigned to a new node to be pushed to the front of the array.
	//--------------------------------------------------------------------------------------
	void PushFront(T data)
	{
		ListNode<T>* node = new ListNode<T>();
		_ASSERT(node);
		node->data = data;
		node->next = start->next;
		start->next->prev = node;
		start->next = node;
		node->prev = start;
	}

	//--------------------------------------------------------------------------------------
	// Creates a node with the passed in data and an pushes it to the back of the array.
	//
	// Param:
	//		data: Data to be assigned to a new node to be pushed to the back of the array.
	//--------------------------------------------------------------------------------------
	void PushBack(T data)
	{
		ListNode<T>* node = new ListNode<T>();
		_ASSERT(node);
		node->data = data;
		node->prev = end->prev;
		end->prev->next = node;
		end->prev = node;
		node->next = end;
	}

	//--------------------------------------------------------------------------------------
	// Creates a node with the passed in data and an based on the index inserts the node 
	// into the array.
	//
	// Param:
	//		data: Data to be assigned to a new node to be inserted at the specified index 
	//			  in the array.
	//		index: Spot to insert the value.
	//--------------------------------------------------------------------------------------
	void Insert(T data, int index)
	{
		Iter<int> iter;

		iter = Begin(); //=

		for (int i = 0; i < index - 1; ++i)
		{
			++iter;
		}

		ListNode<T>* node = new ListNode<T>();
		_ASSERT(node);

		node->data = data;
		node->next = iter.current->next;
		iter.current->next->prev = node;
		iter.current->next = node;
		node->prev = iter.current;
	}

	//--------------------------------------------------------------------------------------
	// Inserts a passed in node into the array at a given idex.
	//
	// Param:
	//		newNode: Node to be inserted at the specified index in the array.
	//		index: Spot to insert the value.
	//--------------------------------------------------------------------------------------
	void Insert(ListNode<T>* newNode, int index)
	{
		Iter<int> iter;

		iter = Begin(); //=

		for (int i = 0; i < index - 1; ++i)
		{
			++iter;
		}

		ListNode<T>* node = new ListNode<T>();
		_ASSERT(node);

		node = newNode;
		node->next = iter.current->next;
		iter.current->next->prev = node;
		iter.current->next = node;
		node->prev = iter.current;
	}

	//--------------------------------------------------------------------------------------
	// Returns the start of a linked list array.
	//
	// Return:
	//		Returns the start's next node which is where linked list arrays start.
	//--------------------------------------------------------------------------------------
	ListNode<T>* Begin()
	{
		return start->next;
	}

	//--------------------------------------------------------------------------------------
	// Returns the end of a linked list array.
	//
	// Return:
	//		Returns the end node which is where linked list arrays end.
	//--------------------------------------------------------------------------------------
	ListNode<T>* End()
	{
		return end;
	}
	
	//--------------------------------------------------------------------------------------
	// Returns the first node in a linked list array.
	//
	// Return:
	//		Returns the start's next node which is where linked list arrays first value is.
	//--------------------------------------------------------------------------------------
	ListNode<T>* First()
	{
		_ASSERT(start->next != end);
		return start->next;
	}

	//--------------------------------------------------------------------------------------
	// Returns the end of a linked list array.
	//
	// Return:
	//		Returns the end's previous node which is where linked list arrays end value is.
	//--------------------------------------------------------------------------------------
	ListNode<T>* Last()
	{
		_ASSERT(end->prev != start);
		return end->prev;
	}

	//--------------------------------------------------------------------------------------
	// Returns number of nodes in the array.
	//
	// Return:
	//		Returns an int of how many nodes are currently in the array.
	//--------------------------------------------------------------------------------------
	int Count()
	{
		Iter<int> iter;

		iter = Begin(); //=

		int m_count = 0;

		while (iter != End()) // != ==
		{
			++m_count;
			++iter; //++ --
		}

		return m_count;
	}

	//--------------------------------------------------------------------------------------
	// Deletes a node in the array.
	//
	// Param:
	//		node: The node to be deleted.
	// Return:
	//		Returns the next node in the array which is now in the spot of the deleted node.
	//--------------------------------------------------------------------------------------
	ListNode<T>* Delete(ListNode<T>* node)
	{
		ListNode<T>* prevNode = node->prev;
		ListNode<T>* nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

	//--------------------------------------------------------------------------------------
	// Erases a node in the array.
	//
	// Param:
	//		target: The iter is passed in here to allow the array to be iterated along.
	//		index: The index at which the node is to be erased.
	//--------------------------------------------------------------------------------------
	void Erase(Iter<T> & target, int index)
	{
		Iter<int> iter;

		iter = Begin(); //=

		for (int i = 0; i < index - 1; ++i)
		{
			++iter;
		}

		target = iter;

		target.current = Delete(target.current);
	}

	//--------------------------------------------------------------------------------------
	// Removes/Erases all node in the array with the specified value.
	//
	// Param:
	//		value: The value of the node/s which are to be removed/erased.
	//--------------------------------------------------------------------------------------
	void Remove(T value)
	{
		ListNode<T>* current = start->next;

		Iter<int> iter;

		iter = Begin(); //=

		while (current != end)
		{
			if (current->data == value)
			{
				current = Delete(current);
				++iter;
			}
			else
			{
				++current;
			}
		}
	}

	//--------------------------------------------------------------------------------------
	// Pops off the last node in the array.
	//--------------------------------------------------------------------------------------
	void PopBack()
	{
		_ASSERT(end->prev != start);
		Delete(end->prev);
	}

	//--------------------------------------------------------------------------------------
	// Pops off the first node in the array.
	//--------------------------------------------------------------------------------------
	void PopFront()
	{
		_ASSERT(start->next != end);
		Delete(start->next);
	}

	//--------------------------------------------------------------------------------------
	// Pops off / erases / deletes / removes all nodes in the array..
	//--------------------------------------------------------------------------------------
	void Clear()
	{
		ListNode<T>* current = start->next;

		while (current != end)
		{
			current = Delete(current);
		}
	}

private:
	ListNode<T>* start;
	ListNode<T>* end;
	int m_Iterator;
};
