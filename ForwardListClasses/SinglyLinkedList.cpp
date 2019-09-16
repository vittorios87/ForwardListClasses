
#include "SinglyLinkedList.h"


//EMPTY LIST CONSTRUCTOR
template<class T> SinglyLinkedList<T>::SinglyLinkedList()
{
	head = nullptr;
}

//LIST OF GIVEN LENGTH WITH EMPTY SLOTS CONSTRUCTOR
template<class T> SinglyLinkedList<T>::SinglyLinkedList(size_t sz) {
	/*
	head = myallocator.allocate(1);
	myallocator.construct(head);
	Node_type_ptr temp = head;
	Node_type_ptr temp_neXt;
	size_t count = 1;
	while (count < sz)
	{
		temp_neXt= myallocator.allocate(1);
		myallocator.construct(temp_neXt);
		temp->neXt = temp_neXt;
		temp= temp_neXt;
		++count;
	}
	temp-> neXt = nullptr;
	*/
	size_t count=0;
	head = new Node<T_type>();
	Node_type_ptr temp=head;
	count++;
	while (count< sz)
	{
		temp->neXt = new Node<T_type>();
		temp = temp->neXt;
		count++;
	}
	
}

//LIST OF GIVEN LENGTH WITH INITIALIZED SLOTS CONSTRUCTOR
template<class T> SinglyLinkedList<T>::SinglyLinkedList(size_t sz, const T_type& val) {
	size_t count = 0;
	head = new Node<T_type>(val);
	Node_type_ptr temp = head;
	count++;
	while (count < sz)
	{
		temp->neXt = new Node<T_type>(val);
		temp = temp->neXt;
		count++;
	}
	std::cout << "Constructor that specifies size and value has been called." << std::endl;

}


//'BY NODE' LIST CONSTRUCTOR 
template<class T> SinglyLinkedList<T>::SinglyLinkedList(Node_type_ptr n)
{
	head = n;
}

//COPY CONSTRUCTOR
template<class T> SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& SLList)
{
	Node_type_ptr temp;
	Node_type_ptr tempOther =SLList.head;
	while (tempOther!=nullptr)
	{
		temp= new Node<T_type>(tempOther->_data);
		appendNode(temp);
		tempOther = tempOther->neXt;
		std::cout << "one node has been copied" << std::endl;
    }
	std::cout << "Copy constructor called." << std::endl;
}

//MOVE CONSTRUCTOR
template<class T> SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList&& SLList)
{
	head = SLList.head;
	SLList.~SinglyLinkedList();
	//delete &SLList;
	std::cout <<"address of rvalue ref: "<< &SLList << std::endl;
	std::cout << "Move constructor called." << std::endl;
}

template<class T> void SinglyLinkedList<T>::appendNode(Node_type_ptr n)
{
	if (head == nullptr)
	{
		head = n;
		std::cout << "Node appended to the head" << std::endl;

	}
	else
	{
		Node_type_ptr ptr = head;
		while (ptr->neXt != nullptr)
		{
			ptr = ptr->neXt;
		}
		ptr->neXt = n;
		std::cout << "Node appended to the tail" << std::endl;

	}
}

template<class T> void SinglyLinkedList<T>::prependNode(Node_type_ptr n)
{

	n->neXt = head;
	head = n;
	std::cout << "Node prepended" << std::endl;
}

template<class T> void SinglyLinkedList<T>::remove(const T_type& value)
{
	if (head == nullptr) 
	{
		std::cout << "Singly Linked List already empty. Cant delete." << std::endl;

	}
	else
	{
		Node_type_ptr temp = head;
		Node_type_ptr temp_previous = nullptr;
		Node_type_ptr toRemove = nullptr;
		bool isOnHead = true;
		while (temp != nullptr) 
		{
			if (temp->_data == value) 
			{
				toRemove = temp;
			}
			if (toRemove != nullptr) 
			{
				temp = toRemove->neXt;
				if (isOnHead)
				{
					head = temp;
				}
				else
				{
					temp_previous->neXt = temp;
				}
				delete toRemove;
				toRemove = nullptr;

			}
			else
			{
				temp_previous = temp;
				temp = temp->neXt;
				isOnHead = false;
			}

		}
	}
}

template<class T> template <typename Predicate> void SinglyLinkedList<T>::remove_if(Predicate pred)
{
	if (head == nullptr)
	{
		std::cout << "Singly Linked List already empty. Cant delete." << std::endl;

	}
	else
	{
		Node_type_ptr temp = head;
		Node_type_ptr temp_previous = nullptr;
		Node_type_ptr toRemove = nullptr;
		bool isOnHead = true;
		while (temp != nullptr)
		{
			if (pred(temp->_data))
			{
				toRemove = temp;
			}
			if (toRemove != nullptr)
			{
				temp = toRemove->neXt;
				if (isOnHead)
				{
					head = temp;
				}
				else
				{
					temp_previous->neXt = temp;
				}
				delete toRemove;
				toRemove = nullptr;

			}
			else
			{
				temp_previous = temp;
				temp = temp->neXt;
				isOnHead = false;
			}

		}
	}
}
template<class T> void SinglyLinkedList<T>::reverse()
{
	Node_type_ptr previous_node = nullptr;
	Node_type_ptr current_node = head;
	Node_type_ptr next_node = nullptr;
	while (current_node != nullptr)
	{
		next_node = current_node->neXt;
		current_node->neXt = previous_node;
		previous_node = current_node;
		current_node = next_node;
	}

	head = previous_node;
}


template<class T> void SinglyLinkedList<T>::updateNode(iterator_t position, const T_type& d)
{
	Node_type_ptr toUpdate = nullptr;
	Node_type_ptr temp = head;
	while (temp != nullptr)
	{
		if (temp == position)
		{
			toUpdate = temp;
			break;
		}
		temp = temp->neXt;
	}

	if (toUpdate != nullptr)
	{
		toUpdate->_data = d;
		std::cout << "Node data updated successfully." << std::endl;
	}
	else
	{
		std::cout << "Node does not exist. "<< std::endl;
	}
}
template<class T> void SinglyLinkedList<T>::printList()
{
	if (head == nullptr) 
	{
		std::cout << "No nodes existing in this singly linked list " << std::endl;
	}
	else
	{
		std::cout << "Singly linked list values:" << std::endl;
		Node<T_type>* temp = head;
		while (temp != nullptr)
		{
			std::cout << " ( " << temp->_data << " ) ";
			temp = temp->neXt;
			if (temp != nullptr)
			{
				std::cout << "-->"; 
			}
			else
			{
				std::cout << std::endl;
			}
		}
	}
}


template<class T> void  SinglyLinkedList<T>::push_front(const T_type& value)
{
	//int key = getLowestFreeKey();
	Node_type_ptr toPushFront = new Node<T_type>(value);
	prependNode(toPushFront);
}
template<class T> void  SinglyLinkedList<T>::push_front(T_type&& value)
{
	//int key = getLowestFreeKey();
	Node_type_ptr toPushFront = new Node<T_type>(std::move(value));
	prependNode(toPushFront);
}
template<class T> void SinglyLinkedList<T>::pop_front()
{
	Node_type_ptr temp = head->neXt;
	delete head;
	head = temp;
}
template<class T> void SinglyLinkedList<T>::clear()
{
	Node_type_ptr temp = head;
	Node_type_ptr temp2 = nullptr;
	while (temp != nullptr) 
	{
		temp2 = temp->neXt;
		delete temp;
		temp = temp2;
	}
	head = nullptr;
}

template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::insert_after(iterator_t position, const T_type& value)
{
	if (head != nullptr)
	{
		if (position != nullptr)
		{
			Node_type_ptr toInsertAfter = new Node<T_type>( value);
			toInsertAfter->neXt = (*position).neXt;
			(*position).neXt = toInsertAfter;  //non è necessario verificare se il nodo dopo cui inserire esiste, e neanche se la chiave è già usata
			return Iterator(toInsertAfter);
		}
		return position;
	}
	else 
	{
		head = new Node<T_type>(value);
		std::cout << "List was empty. Inserted as first node"<< std::endl;
		return Iterator(head);
	}
}
template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::insert_after(iterator_t position, T_type&& value) {
	if (head != nullptr)
	{
		if (position != nullptr)
		{			
			Node_type_ptr toInsertAfter = new Node<T_type>(std::move(value));
			toInsertAfter->neXt = (*position).neXt;
			(*position).neXt = toInsertAfter;
			return Iterator(toInsertAfter);

		}
		return position;
	}
	else
	{
		head = new Node<T_type>(std::move(value));
		std::cout << "List was empty. Inserted as first node" << std::endl;
		return Iterator(head);
	}
	
}
template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::insert_after(iterator_t position, size_t n, const T_type& value)
{
	if (head != nullptr)
	{
		if (position != nullptr)
		{			
			Node_type_ptr toAppend = (*position).neXt;
			Node_type_ptr toReturn= toAppend;
			while (n>0)
			{
				Node_type_ptr toInsertAfter = new Node<T_type>(value);
				toInsertAfter->neXt = toAppend;
				toAppend = toInsertAfter;
				--n;
		    }
			(*position).neXt = toAppend;
			std::cout << "Insertion in the middle" << std::endl;
			return toReturn;
		}
		std::cout << "Insertion was impossible" << std::endl;
		return position;
	}
	else
	{
		size_t i = 0;
		head = new Node<T_type>(value);
		++i;
		Node_type_ptr toContinue = head;
		while (i < n)
		{
			toContinue->neXt = new Node<T_type>( value);
			toContinue = toContinue->neXt;
			++i;
		}
		std::cout << "Insertion at the beginning" << std::endl;
		return toContinue->neXt;
	}
}

template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::begin()
{
	return Iterator(head);
}

template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::end()
{
	Node_type_ptr ptr = head;
	while (ptr->neXt != nullptr)
	{
		ptr = ptr->neXt;
	}
	return Iterator(ptr);

}

template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::erase_after(iterator_t position)
{
	if (position != nullptr && position != end())
	{
		Node_type_ptr toErase = (*position).neXt;
		Node_type_ptr toAppend = toErase->neXt;
		(*position).neXt = toAppend;
		delete toErase;
		return Iterator(toAppend);
		/*if (toErase != nullptr){}
		std::cout << "Nothing to erase after" << std::endl;
		return Iterator(toErase);*/
	}
	else
	{
		std::cout << "Null or end pointer (in the last case nothing to erase after)" << std::endl;
		return nullptr;
	}
}
template<class T> typename SinglyLinkedList<T>::iterator_t SinglyLinkedList<T>::erase_after(iterator_t position, iterator_t last_position)
{

	if (position != nullptr && position!= end() && position!= last_position)
	{
		Node_type_ptr temp = nullptr;
		Node_type_ptr toErase = (*position).neXt;
		//la seconda condizione del while rende possibile usare questo metodo anche se l'iteratore position viene dopo last_position
		//in questo caso elimina tutti gli elementi a partire da quello che segue position, fermandosi alla fine.
		while (toErase != &(*last_position) && toErase!= nullptr) 
		{
			temp = toErase->neXt;
			delete toErase;
			toErase = temp;
		}
		(*position).neXt = toErase;
		return toErase;
	}
	return last_position;

}


template<class T> SinglyLinkedList<T>::~SinglyLinkedList()
{
	std::cout << "Singly Linked List destructor called" << std::endl;
}
