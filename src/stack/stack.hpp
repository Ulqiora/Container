#pragma once
#include <initializer_list>

#include "../Node.hpp"
namespace s21 {
    template<class Type_stack>
class stack {
   public:
    typedef size_t size_type;
    typedef Type_stack value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    stack();
    stack(size_type n);
    stack(std::initializer_list<value_type> const& items);
    stack(const stack& q);
    stack(stack&& q);
    ~stack();
    reference operator=(stack&& q);

    const_reference front();
    const_reference back();

    bool empty();
    size_type size();

    void push(const_reference value);
    void pop();
    void swap(stack& other);

   private:
    Node<Type_stack>* head_;
    size_type size_;
};
}  // namespace s21