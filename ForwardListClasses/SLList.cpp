#include "SLList.h"

template<typename T, class Allocator> SLList<T, Allocator>::SLList()
{
	pointer_t headElementPntr = allocator_traits<Allocator>.allocate(1);
	pointer_t tailElementPntr = allocator_traits<Allocator>.allocate(1);
	allocator_traits<Allocator>.construct(headElementPntr, 0);
	allocator_traits<Allocator>.construct(tailElementPntr, 0);

	head = allocator_traits<std::allocator<SLNode>>.allocate(1) ;
	tail = allocator_traits<std::allocator<SLNode>>.allocate(1);
	allocator_traits<std::allocator<SLNode>>.construct(head, 0, tail);
	allocator_traits<std::allocator<SLNode>>.construct(tail, 0, head);

}

template<typename T, class Allocator> SLList<T, Allocator>::SLList(const allocator_t& alloc)
{
	pointer_t headElementPntr = allocator_traits<Allocator>.allocate(1);
	pointer_t tailElementPntr = allocator_traits<Allocator>.allocate(1);
	allocator_traits<Allocator>.construct(headElementPntr, 0);
	allocator_traits<Allocator>.construct(tailElementPntr, 0);

	head = allocator_traits<std::allocator<SLNode>>.allocate(1);
	tail = allocator_traits<std::allocator<SLNode>>.allocate(1);
	allocator_traits<std::allocator<SLNode>>.construct(head, 0, tail);
	allocator_traits<std::allocator<SLNode>>.construct(tail, 0, head);
	
}
template<typename T, class Allocator> SLList<T, Allocator>::SLList(size_t n) 
{
	pointer_t headElement = allocator_traits<allocator_t>.allocate(1);
	pointer_t tailElement = allocator_traits<allocator_t>.allocate(1);
	allocator_traits<allocator_t>.construct(headElement);
	allocator_traits<allocator_t>.construct(tailElement);
	head = new SLNode(headElement);
	tail = new SLNode(tailElement);
	head->set_next(tail);
	tail->set_next(head);
	size_t i=0;
	node_pointer temp;
	node_pointer temp2 = head;
	while (i < n) {
		pointer_t tempElement = allocator_traits<allocator_t>.allocate(1);
		allocator_traits<allocator_t>.construct(tempElement);
		temp = new SLNode(tempElement,);
		temp2->set_next(temp);
		temp2 = temp;
		i++;
	}
	temp2->set_next(tail);
}
/*
template<typename T, class Allocator>  SLList<T, Allocator>::SLList():head()
{
	
}


SLList::~SLList()
{
}
*/
template<typename T, class Allocator> void  SLList<T, Allocator>::push_front(const value_t& value)
{
	SLNode newnode = SLNode(value);
	newnode->set_next(head->get_next());
	head->set_next(&newnode);
}
template<typename T, class Allocator> void  SLList<T, Allocator>::push_front(value_t&& value)
{
	SLNode newnode = SLNode(value);
	newnode->set_next(head);
	head = &newnode;
}
template<typename T, class Allocator> void  SLList<T, Allocator>::pop_front()
{

}
