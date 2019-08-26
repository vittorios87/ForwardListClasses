#include "Node.h"




template <class T> Node<T>::Node(T d)    //int k,
{
	_data = d;    
	neXt = nullptr;
}

template <class T> Node<T>::~Node()
{ 
}
