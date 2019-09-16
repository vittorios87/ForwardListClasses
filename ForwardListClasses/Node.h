#pragma once
template <class T> class Node
{
public:

	void* operator new (size_t size);
	void  operator delete(void* p);

	void* operator new[](size_t size);
	void  operator delete[](void* p);

	//int key;
	T _data;
	Node<T>* neXt;


	Node<T>(T d=T()); //int,
	~Node<T>();

	void setNeXt(Node<T>* neXt_val);
	void setData(T _data_val);

};

