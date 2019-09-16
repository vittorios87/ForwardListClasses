#include "Node.h"
#include <cstdlib>


template <class T> void*  Node<T>::operator new (size_t size) {
	std::cout << "node operator new called, size = " << size << std::endl;
	//std::printf("node operator new called, size %z\n", size)
	void* ptr = malloc(size);
	if (ptr)
		return ptr;
	else
		throw std::bad_alloc{};
}

template <class T> void  Node<T>::operator delete(void* p) {
	std::cout << "node operator delete called, size = " << sizeof(Node<T>) << std::endl;
	free(p);
}

template <class T> void* Node<T>::operator new[](size_t size)
{
	std::cout << "node operator new[] called, size = " << size << std::endl;
	void* ptr = malloc(size);
	if (ptr)
		return ptr;
	else
		throw std::bad_alloc{};
}
template <class T> void Node<T>::operator delete[](void* p) {
	std::cout << "node operator delete[] called, array size = " << (* (int*)p) << std::endl;
	free(p);
}

template <class T> Node<T>::Node(T d)    //int k,
{
	_data = d;    
	neXt = nullptr;
}

template <class T> Node<T>::~Node()
{ 
}

template <class T> void Node<T>::setNeXt(Node<T>* neXt_val)
{
	neXt = neXt_val;
}
template <class T> void Node<T>::setData(T _data_val)
{
	_data = _data_val;
}