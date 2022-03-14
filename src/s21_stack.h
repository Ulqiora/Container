#pragma once

#include "singly_list.h"

namespace s21 {

template <class Type>
class stack : public single_linked_list<Type> {
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
    void push(const_reference value) override;

    void emplace_front() {}
    template <class T, class... Args>
    void emplace_front(T n, Args... args);
};

template <class Type>
stack<Type>::stack() : single_linked_list<Type>::single_linked_list() {}

template <class Type>
stack<Type>::stack(size_type n) : single_linked_list<Type>::single_linked_list(new Node_<Type>(nullptr), n) {
    Node_<Type>* current = single_linked_list<Type>::head_;
    for (size_type i = 1; i < single_linked_list<Type>::size_; ++i) {
        current->next_ = new Node_<Type>(nullptr);
        current = current->next_;
    }
}

template <class Type>
stack<Type>::stack(std::initializer_list<value_type> const& items)
    : single_linked_list<Type>::single_linked_list() {
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type>
stack<Type>::stack(const stack& q) : single_linked_list<Type>::single_linked_list() {
    stack<Type> a;
    Node_<Type>* current = q.head_;
    while (current != nullptr) {
        a.push(current->value_);
        current = current->next_;
    }
    while (a.head_ != nullptr) {
        push(a.head_->value_);
        a.pop();
    }
}

template <class Type>
stack<Type>::stack(stack&& q) : single_linked_list<Type>::single_linked_list(q.head_, q.size_) {
    q.head_ = nullptr;
    q.size_ = 0;
}

template <class Type>
stack<Type>::~stack() {
    while (single_linked_list<Type>::size_ != 0) single_linked_list<Type>::pop();
}

template <class Type>
typename s21::stack<Type>::reference stack<Type>::operator=(stack&& q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr,
     q.size_ = 0);
    return *this;
}

template <class Type>
void stack<Type>::push(const_reference value) {
    if (single_linked_list<Type>::size_ == 0) {
        single_linked_list<Type>::head_ = new Node_<Type>(nullptr, value);
    } else {
        Node_<Type>* current = new Node_<Type>(single_linked_list<Type>::head_, value);
        single_linked_list<Type>::head_ = current;
    }
    ++single_linked_list<Type>::size_;
}

template <class Type>
template <class T, class... Args>
void stack<Type>::emplace_front(T n, Args... args) {
    push(n);
    emplace_front(args...);
}

}  // namespace s21
