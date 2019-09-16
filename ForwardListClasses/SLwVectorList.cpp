#include "SLwVectorList.h"


//using iterator_t = std::vector<Node_type>::iterator;
//using const_iterator_t = std::vector<Node_type>::const_iterator;


//EMPTY LIST CONSTRUCTOR
template<class T> SLwVectorList<T>::SLwVectorList() 
{
	listdata = new typename std::vector<Node_type>();
	std::cout << "empty list constructor" << std::endl;
}

//LIST OF GIVEN LENGTH WITH EMPTY SLOTS CONSTRUCTOR
template<class T> SLwVectorList<T>::SLwVectorList(size_t sz) {
	
	listdata = new typename std::vector<Node_type>(sz);
	
	size_t i = 0;
	while (i < sz-1)
	{
		(listdata->at(i)).setNeXt(&(listdata->at(i + 1)));
		++i;
	}
	(listdata->at(i)).setNeXt(nullptr);

}

//LIST OF GIVEN LENGTH WITH INITIALIZED SLOTS CONSTRUCTOR
template<class T> SLwVectorList<T>::SLwVectorList(size_t sz, const T_type& val) {
	listdata = new typename std::vector<Node_type>(sz);

	size_t i = 0;
	while (i < sz - 1)
	{
		(listdata->at(i)).setData(val);
		(listdata->at(i)).setNeXt(&(listdata->at(i+1)));
		++i;
	}
	(listdata->at(i)).setData(val);
	(listdata->at(i)).setNeXt(nullptr);
	std::cout << "Constructor that specifies size and value has been called." << std::endl;

}


//'BY NODE' LIST CONSTRUCTOR 
template<class T> SLwVectorList<T>::SLwVectorList(Node_type_ptr n)
{
	listdata = new typename std::vector<Node_type>();

	//size_t last_node = 0;
	//listdata->push_back(*n);

	while (n != nullptr)
	{
		appendNode(n);
		//++last_node;
		//listdata->push_back(*(n->neXt));
		//(listdata->at(last_node - 1)).setNeXt(&(listdata->at(last_node)));
		n = n->neXt;
	}
}

//COPY CONSTRUCTOR
template<class T> SLwVectorList<T>::SLwVectorList(const SLwVectorList<T>& SLwVList)
{
	listdata = new typename std::vector<Node_type>(SLwVList.listdata);
	Node_type_ptr next_node;
	for (size_t index = 0; index < listdata.size() - 1; ++index)
	{
		listdata[index].setNeXt(&listdata[index + 1]);
	}
	std::cout << "Copy constructor called." << std::endl;
}

//MOVE CONSTRUCTOR
template<class T> SLwVectorList<T>::SLwVectorList(SLwVectorList&& SLwVList)
{
	listdata = SLwVList.listdata;
	SLwVList.~SLwVectorList();
	std::cout << "Move constructor called." << std::endl;
}

template<class T> void SLwVectorList<T>::appendNode(Node_type_ptr n)
{
	listdata->push_back(*n);
	listdata->back().setNeXt(nullptr);
	if(listdata->size()==1)
	{ 
		std::cout << "Node appended to the head" << std::endl;
	}
	else
	{
		listdata->at(listdata->size() - 2).setNeXt(&listdata->at(listdata->size() - 1));
		std::cout << "Node appended to the tail" << std::endl;
	}
	
}

template<class T> void SLwVectorList<T>::prependNode(Node_type_ptr n)
{
	listdata->insert(listdata->begin(), *n);
	if (listdata->size() > 1)
	{
		//( listdata->front() ).setNeXt( &(listdata->at(1)) );
		size_t i = 0;
	

		while (i < listdata->size() -1 )
		{
			(listdata->at(i)).setNeXt(&(listdata->at(i)));
			++i;
		}

	}
	else {
		listdata->begin()->setNeXt(nullptr);
	}
	std::cout << "Node prepended" << std::endl;
}

template<class T> void SLwVectorList<T>::remove(const T_type& value)
{
	if (listdata->size()==0)
	{
		std::cout << "Singly Linked List already empty. Cant delete." << std::endl;

	}
	else
	{
		iterator_t it = listdata->begin();
		while (it< listdata->end())
		{
			
			if (it->_data == value)
			{
				it = listdata->erase(it);
				
			}
			else if (it != listdata->end())
			{
				++it;

			}
			if (it > listdata->begin() && it <listdata->end())
			{
				(*(it - 1)).setNeXt(&(*it));
			}
		}
		
	}
}

template<class T> template <typename Predicate> void SLwVectorList<T>::remove_if(Predicate pred)
{
	if (listdata->size() == 0)
	{
		std::cout << "Singly Linked List already empty. Cant delete." << std::endl;

	}
	else
	{
		iterator_t it = listdata->begin();
		while (it < listdata->end())
		{

			if (pred(it->_data))
			{
				it = listdata->erase(it);				
			}
			else if (it != listdata->end())
			{
				++it;
				
			}
			if (it > listdata->begin() && it < listdata->end())
			{
				(*(it - 1)).setNeXt(&(*it));
			}
		}

	}
}
template<class T> void SLwVectorList<T>::reverse()
{
	//the assumption is that Node_type_ptr is equal to std::vector<Node_type>::iterator
	Node_type_ptr previous_node = nullptr;
	Node_type_ptr current_node = *(listdata->begin());
	Node_type_ptr next_node = nullptr;
	while (current_node != *(listdata->end()))
	{
		next_node = current_node->neXt;
		current_node->neXt = previous_node;
		previous_node = current_node;
		current_node = next_node;
	}
	iterator_t it = listdata->begin();
	iterator_t end_it = listdata->end()-1;
	if (listdata->size() % 2 == 0)
	{
		/* DISCARDED
		std::vector<Node_type>::iterator offset = listdata->size() / 2;
		size_t i = 0;							
		while (i < offset)
		{
			listdata->swap(*(it+i),*(end_it-i));
		}
		*/
		while (it-1 != end_it)
		{
			listdata->swap(*(it), *(end_it));
			++it;
			--end_it;
		}
	}
	else
	{
		while (it != end_it)
		{
			listdata->swap(*(it), *(end_it));
			++it;
			--end_it;
		}
	}
}


template<class T> void SLwVectorList<T>::updateNode(iterator_t position, const T_type& d)
{


	if (position >= listdata->begin() &&position < listdata->end())
	{
		position->_data = d;
		std::cout << "Node data updated successfully." << std::endl;
	}
	else
	{
		std::cout << "Node does not exist. " << std::endl;
	}
}
template<class T> void SLwVectorList<T>::printList()
{
	if (listdata->size()==0)
	{
		std::cout << "No nodes existing in this singly linked list " << std::endl;
	}
	else
	{
		std::cout << "Singly linked list values:" << std::endl;
		iterator_t temp = listdata->begin();
		auto endIt = listdata->end();
		while (temp != endIt)
		{
			std::cout << " ( " << temp->_data << " ) ";
			++temp;
			if (temp != endIt)
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


template<class T> void  SLwVectorList<T>::push_front(const T_type& value)
{
	//int key = getLowestFreeKey();
	Node_type_ptr toPushFront = new Node<T_type>(value);
	prependNode(toPushFront);
}
template<class T> void  SLwVectorList<T>::push_front(T_type&& value)
{
	//int key = getLowestFreeKey();
	Node_type_ptr toPushFront = new Node<T_type>(std::move(value));
	prependNode(toPushFront);
}
template<class T> void SLwVectorList<T>::pop_front()
{
	listdata->erase(listdata->begin());
}
template<class T> void SLwVectorList<T>::clear()
{
	listdata->clear();
}

template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::insert_after(iterator_t position, const T_type& value)
{

	std::cout << "insert_after with L value ref called" << std::endl;

	if (position < listdata->end())
	{
		Node_type_ptr toInsertAfter = new Node<T_type>(value);
		++position;
		listdata->insert(position, *toInsertAfter);
		size_t i = 0;
		for (size_t i = 0; i < listdata->size() - 1; ++i)
		{
			(listdata->at(i)).setNeXt(&(listdata->at(i + 1)));
		}
	}
	return position;
}
template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::insert_after(iterator_t position, T_type&& value) {
	std::cout << "insert_after with R value ref called" << std::endl;
	if (position  < listdata->end())
	{
		Node_type_ptr toInsertAfter = new Node<T_type>(std::move(value));
		++position;
		listdata->insert(position, *toInsertAfter);
		size_t i = 0;
		for (size_t i = 0; i < listdata->size()-1; ++i)
		{
			(listdata->at(i)).setNeXt(&(listdata->at(i + 1)));
		}
	}
	return position;
}
template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::insert_after(iterator_t position, size_t n, const T_type& value)
{

	std::cout << "insert_after (multiple times) with L value ref called" << std::endl;


	iterator_t toReturnPosition = position;

	if (position < listdata->end())
	{
		++position;
		while (n > 0)
		{
			Node_type_ptr toInsertAfter = new Node<T_type>(value);
			position=listdata->insert(position, *toInsertAfter);
			--n;
		}
		for (size_t i = 0; i < listdata->size() - 1; ++i)
		{
			(listdata->at(i)).setNeXt(&(listdata->at(i + 1)));
		}
	}
	return position;

}

template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::begin()
{
	return listdata->begin();
}

template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::end()
{
	return listdata->end();
}

template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::erase_after(iterator_t position)
{
	if (position >= listdata->begin() && position < listdata->end()-1)
	{
		position=listdata->erase(position + 1);
		for (size_t i = 0; i < listdata->size() - 1; ++i)
		{
			(listdata->at(i)).setNeXt(&(listdata->at(i + 1)));
		}
	}
	return position;

}
template<class T> typename SLwVectorList<T>::iterator_t SLwVectorList<T>::erase_after(iterator_t position, iterator_t last_position)
{
	if (last_position > position)
	{
		size_t countElemsToRemove = last_position - position - 1;

		++position;

		while (countElemsToRemove >0)
		{
			position=listdata->erase(position);
			--countElemsToRemove;
		}
		return position;

	}
	else if (last_position<position)
	{
		++position;
		while (position != end())
		{
			position = listdata->erase(position);
		}
		return position;
	}
	return position;

	/* COMPLETAMENTE INUTILEEEE
	if (position >= listdata->begin() && position < end() - 1)
	{
		if (last_position >= begin() && last_position<=end())
		{}
		else
		{
			while (position < end() - 1)
			{
				listdata->erase(end() - 1);
			}
			return position;

		}
	}
	*/
	return position;

}


template<class T> SLwVectorList<T>::~SLwVectorList()
{
}
