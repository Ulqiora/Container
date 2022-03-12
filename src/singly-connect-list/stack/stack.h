#pragma once
#include <initializer_list>

#include "../singly_list.h"
namespace s21 {
    template<class Type>
class stack : public single_linked_list<Type>{
   public:
    typedef size_t size_type;
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    stack();
    stack(size_type n);
    stack(std::initializer_list<value_type> const& items);
    stack(const stack& q);
    stack(stack&& q);
    ~stack();
    reference operator=(stack&& q);
    void push(const_reference value);

    void emplace_front(){}
    template<class T,class ...Args>
    void emplace_front(T n,Args... args);
};
}  // namespace s21