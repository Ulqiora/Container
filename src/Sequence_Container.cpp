#include "Sequence_Container.hpp"


template<typename Type>
Sequence<Type> Sequence<Type>::operator=(Sequence<Type> const& other) {
    if (this != &other) {
        size_ = other.size_;
    }
    return (*this)
}


template<typename Type>
inline Sequence<Type>::size_type Sequence<Type>::size() {
    if (this != &other) {
        size_ = other.size_;
    }
    return (*this);
}