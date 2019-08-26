#pragma once
#include <iostream>
#include <ostream>
#include "Node.h"
template<class T> class SinglyLinkedList
{
public:

	using T_type = T;

	using Node_type = Node<T_type>;
	using Node_type_ptr = Node_type * ;

	class Iterator
	{
	public:
		Iterator() : currentNodePtr(head) {}
		Iterator(const Node_type_ptr nodePtr) : currentNodePtr(nodePtr){}

		Iterator& operator++() 
		{
			if (currentNodePtr)
			{
				currentNodePtr = currentNodePtr->neXt;
			}
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator outIterator = *this;
			++(*this);
			return outIterator;
		}
		bool operator==(const Iterator& it) const
		{
			return currentNodePtr == it.currentNodePtr;
		}
		bool operator!=(const Iterator& it) const
		{
			return currentNodePtr != it.currentNodePtr;
		}
		Node_type& operator*()
		{
			return *currentNodePtr;
		}
	private:
		Node_type_ptr currentNodePtr;
	};

	
	using iterator_t = Iterator;
	using const_iterator_t = const Iterator;

public:
	Node_type_ptr head;
	//Node_type_ptr tail;
	explicit SinglyLinkedList();
	explicit SinglyLinkedList(size_t);
	explicit SinglyLinkedList(size_t, const T_type&);
	explicit SinglyLinkedList(Node_type_ptr);
	~SinglyLinkedList();

	SinglyLinkedList(const SinglyLinkedList&);
	SinglyLinkedList(SinglyLinkedList&&);

	void push_front(const T_type&);
	void push_front(T_type&&);
	void pop_front();

	iterator_t begin();
	iterator_t end();
	
	iterator_t insert_after(iterator_t position, const T_type& value);
	iterator_t insert_after(iterator_t position, T_type&& value);
	iterator_t insert_after(iterator_t position,size_t n, const T_type& value);

	iterator_t erase_after(iterator_t position);
	iterator_t erase_after(iterator_t position, iterator_t last_position);

	void remove(const T_type&);
	template <typename Predicate> void remove_if(Predicate);

	void reverse();
	void clear();

	void appendNode(Node_type_ptr);
	void prependNode(Node_type_ptr);
	void updateNode(iterator_t, const T_type&);
	void printList();
};

