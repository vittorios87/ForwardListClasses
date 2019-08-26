#pragma once
template <typename T> class SLNode
{
public:
	using value_t = T;
	using pointer_t = T * ;
	using reference_t = T & ;
	SLNode(value_t value=0);
	SLNode(value_t value, pointer_t next);

	~SLNode();

	SLNode<value_t>* get_next() const;
	void set_next(SLNode<value_t>*);
	value_t get_data() const; 
	void set_data(value_t);

private:
	value_t  data;
	SLNode<value_t>* next;

};

