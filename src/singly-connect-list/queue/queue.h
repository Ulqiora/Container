#pragma once
#include <initializer_list>
#include <iostream>
#include "../singly_list.h"

namespace s21 {
template <class Type>
class queue : public single_linked_list<Type>{
   public:
    typedef size_t size_type;
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    queue();
    queue(size_type n);
    queue(std::initializer_list<value_type> const& items);
    queue(const queue& q);
    queue(queue&& q);
    ~queue();
    reference operator=(queue&& q);
    void push(const_reference value);

    void emplace_back(){}
    template<class T,class ...Args>
    void emplace_back(T n,Args... args);
};
}  // namespace s21