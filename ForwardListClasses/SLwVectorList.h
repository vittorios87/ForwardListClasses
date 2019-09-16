#pragma once
#include <iostream>
#include <ostream>
#include <vector>
//#include <iterator>
#include "Node.h"
template<class T> class SLwVectorList
{
public:

	using T_type = T;

	using Node_type = Node<T_type>;
	using Node_type_ptr = Node_type * ;



	using iterator_t = typename std::vector<Node_type>::iterator;
	using const_iterator_t = typename  std::vector<Node_type>::const_iterator;

public:
	std::vector<Node_type>* listdata;


	explicit  SLwVectorList();  //ok, tested
	explicit  SLwVectorList(size_t); //ok, tested
	explicit  SLwVectorList(size_t, const T_type&);  //ok, tested
	explicit  SLwVectorList(Node_type_ptr);  //ok, tested
	~SLwVectorList();

	SLwVectorList(const SLwVectorList&);  //ok
	SLwVectorList(SLwVectorList&&); //ok

	void push_front(const T_type&);  //ok, tested
	void push_front(T_type&&); //ok, tested
	void pop_front();  //ok, tested

	iterator_t begin(); //ok, tested
	iterator_t end(); //ok, tested

	iterator_t insert_after(iterator_t position, const T_type& value); //ok, tested
	iterator_t insert_after(iterator_t position, T_type&& value); //ok, tested
	iterator_t insert_after(iterator_t position, size_t n, const T_type& value); //ok, tested

	iterator_t erase_after(iterator_t position); //ok, tested
	iterator_t erase_after(iterator_t position, iterator_t last_position); //ok,tested

	void remove(const T_type&);        //ok, tested
	template <typename Predicate> void remove_if(Predicate); //ok, tested

	void reverse();  //ok
	void clear(); //ok

	void appendNode(Node_type_ptr); //ok, tested
	void prependNode(Node_type_ptr); //ok, tested
	void updateNode(iterator_t, const T_type&); //ok, tested
	void printList();  //ok, tested
};


