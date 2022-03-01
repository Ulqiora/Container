#pragma once
#include "cstddef"
template <class Type>
class Sequence {
 public:
    typedef Type value_type;
    typedef Type& reference;
    typedef const Type& reference;
    typedef Type* iterator;
    typedef const Type* const_iterator;
    typedef size_t size_type;

    virtual reference at(size_type pos) = 0;
    virtual const_reference back() = 0;
    virtual iterator begincbegin() = 0;
    virtual iterator endcend() = 0;
    virtual bool empty() = 0;
    virtual size_type size() = 0;
    virtual size_type max_size() = 0;
    virtual void clear() = 0;
    virtual iterator insert(iterator pos, const_reference value);
    virtual void erase(iterator pos) = 0;
    virtual void push_back(const_reference value);
    virtual void pop_back() = 0;
    virtual void swap(vector& other);

    virtual ~Sequence();
};
