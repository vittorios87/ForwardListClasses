#pragma once
template <class T> class Node
{
public:
	//int key;
	T _data;
	Node<T>* neXt;


	Node<T>(T d=T()); //int,
	~Node<T>();
};

