#pragma once

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <class Node_type>
struct Node_ {
    Node_type value_;
    Node_* next_;
    Node_(Node_* next, Node_type const& data_add = Node_type());
};

template <class Node_type>
Node_<Node_type>::Node_(Node_* next, Node_type const& data_add) : next_(next), value_(data_add) {}

template <class Type>
class single_linked_list {
    // type definitions
 public:
    typedef size_t size_type;
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

 protected:
    Node_<Type>* head_;
    size_type size_;

 public:
    single_linked_list(Node_<Type>* head = nullptr, size_type size = 0);

    bool empty();
    size_type size();
    const_reference front();
    const_reference back();

    virtual void push(const_reference value) = 0;

    void pop();

    void swap(single_linked_list& other);
};

template <class Type>
single_linked_list<Type>::single_linked_list(Node_<Type>* head, size_type size) : head_(head), size_(size) {}

template <class Type>
bool single_linked_list<Type>::empty() {
    return size_ == 0;
}

template <class Type>
typename single_linked_list<Type>::size_type single_linked_list<Type>::size() {
    return size_;
}

template <class Type>
typename single_linked_list<Type>::const_reference single_linked_list<Type>::front() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, stack size equal 0");
    return (head_->value_);
}

template <class Type>
typename single_linked_list<Type>::const_reference single_linked_list<Type>::back() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, stack size equal 0");
    Node_<Type>* current = head_;
    while (current->next_ != nullptr) current = current->next_;
    return (current->value_);
}

template <class Type>
void single_linked_list<Type>::pop() {
    if (size_ > 0) {
        Node_<Type>* current = head_;
        head_ = head_->next_;
        delete current;
        --size_;
    }
}

template <class Type>
void single_linked_list<Type>::swap(single_linked_list& other) {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
}

}  // namespace s21
