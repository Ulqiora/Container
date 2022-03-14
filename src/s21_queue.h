#pragma once

#include "singly_list.h"

namespace s21 {

template <class Type>
class queue : public single_linked_list<Type> {
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
    void push(const_reference value) override;

    void emplace_back() {}
    template <class T, class... Args>
    void emplace_back(T n, Args... args);
};

template <class Type>
queue<Type>::queue() : single_linked_list<Type>::single_linked_list() {}

template <class Type>
queue<Type>::queue(size_type n) : single_linked_list<Type>::single_linked_list(new Node_<Type>(nullptr), n) {
    Node_<Type>* current = single_linked_list<Type>::head_;
    for (size_type i = 1; i < single_linked_list<Type>::size_; ++i) {
        current->next_ = new Node_<Type>(nullptr);
        current = current->next_;
    }
}

template <class Type>
queue<Type>::queue(std::initializer_list<value_type> const& items)
    : single_linked_list<Type>::single_linked_list() {
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type>
queue<Type>::queue(const queue& q) : single_linked_list<Type>::single_linked_list() {
    if (q.head_ != nullptr) {
        push(q.head_->value_);
        if (q.head_->next_ != nullptr) {
            Node_<Type>* current = (q.head_)->next_;
            while (current != nullptr) {
                push(current->value_);
                current = current->next_;
            }
        }
    }
}

template <class Type>
queue<Type>::queue(queue&& q) : single_linked_list<Type>::single_linked_list(q.head_, q.size_) {
    q.head_ = nullptr;
    q.size_ = 0;
}

template <class Type>
queue<Type>::~queue() {
    while (single_linked_list<Type>::size_ != 0) single_linked_list<Type>::pop();
}

template <class Type>
typename s21::queue<Type>::reference queue<Type>::operator=(queue&& q) {
    single_linked_list<Type>::head_ = q.head_;
    single_linked_list<Type>::size_ = q.size_;
    q.head_ = nullptr;
    q.size_ = 0;
    return *this;
}

template <class Type>
void queue<Type>::push(const_reference value) {
    if (single_linked_list<Type>::size_ == 0) {
        single_linked_list<Type>::head_ = new Node_<Type>(nullptr, value);
    } else {
        Node_<Type>* current = single_linked_list<Type>::head_;
        while (current->next_ != nullptr) current = current->next_;
        current->next_ = new Node_<Type>(nullptr, value);
    }
    ++single_linked_list<Type>::size_;
}

template <class Type>
template <class T, class... Args>
void queue<Type>::emplace_back(T n, Args... args) {
    push(n);
    emplace_back(args...);
}

}  // namespace s21
