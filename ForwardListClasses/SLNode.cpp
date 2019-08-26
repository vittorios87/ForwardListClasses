#include "SLNode.h"


template <typename T> SLNode<T>::SLNode(value_t value ) : data(value), next(nullptr) {
};

template <typename T> SLNode<T>::SLNode(value_t value, pointer_t nextpntr) : data(value), next(nextpntr) {

}



template <typename T> SLNode<T>::~SLNode()
{
};

template <typename T>  SLNode<T>* SLNode<T>::get_next() const {
	return this->next;
}

template <typename T> void SLNode<T>::set_next(SLNode<value_t>* node)
{
	this->next = node;
}

template <typename T> T SLNode<T>::get_data() const
{
	return this->data;
}
template<typename T> void SLNode<T>::set_data(value_t value) {
	this-> data = value;
}