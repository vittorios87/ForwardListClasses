#pragma once
#include <allocators>

template<typename T, class Allocator =std::allocator<T>> class SLList
{

	struct SLNode
	{
	public:
		
		SLNode(value_t value = 0) : data(value), next(nullptr) 
		{
		};
		SLNode(value_t value, node_pointer_t next_node_pntr) : data(value), next(next_node_pntr) 
		{
		};

		~SLNode();

		pointer_t get_next() const 
		{
			return next;
		};
		void set_next(node_pointer_t node_pntr)
		{
			next = node_pntr;

		};
		value_t get_data() const 
		{
			return data;
		}
		void set_data(value_t value) 
		{		
			data = value;
		};

	private:
		value_t  data;
		node_pointer_t next;

	};
public:
	using value_t = T;
	using pointer_t = T* ;
	using reference_t = T& ;
	using const_reference_t = const T&;

	using allocator_t = Allocator;
	//using all_pntr = std::allocator_traits<allocator_t>::pointer;
	//using all_const_pntr = std::allocator_traits<allocator_t>::const_pointer;

	using node_t = SLNode;
	using node_pointer_t = node_t* ;

	SLList();
	explicit SLList(size_t n);

	explicit SLList(const allocator_t& alloc = allocator_t());
	explicit SLList(size_t n, const allocator_t& alloc = allocator_t());

	//SLList( size_t n, const reference_t value, const Allocator& alloc = Allocator() );



	~SLList();

	void push_front(const value_t&);
	void push_front(value_t&&);
	void pop_front();

private :
	node_pointer_t head, tail;
};

