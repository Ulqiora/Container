#pragma once
#include <initializer_list>
#include <iostream>
#include "../Node.hpp"
namespace s21 {
template <class Type_queue>
class queue {
   public:
    typedef size_t size_type;
    typedef Type_queue value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    queue();
    queue(size_type n);
    queue(std::initializer_list<value_type> const& items);
    queue(const queue& q);
    queue(queue&& q);
    ~queue();
    reference operator=(queue&& q);

    const_reference front();
    const_reference back();

    bool empty();
    size_type size();

    void push(const_reference value);
    void pop();
    void swap(queue& other)noexcept;

   private:
    Node<Type_queue>* head_;
    size_type size_;
};
}  // namespace s21