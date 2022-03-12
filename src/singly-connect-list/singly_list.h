#pragma once

#include <initializer_list>
#include <iostream>

#include "Node.h"

namespace s21 {
template <class Type>
class single_linked_list {
 public:
    typedef size_t size_type;
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    bool empty() { return size_ == 0; }
    size_type size() { return size_; }

    const_reference front() {
        if (size_ == 0) throw std::invalid_argument("Invalid argument, stack size equal 0");
        return (head_->value_);
    }

    const_reference back() {
        if (size_ == 0) throw std::invalid_argument("Invalid argument, stack size equal 0");
        Node_<Type>* current = head_;
        while (current->next_ != nullptr) current = current->next_;
        return (current->value_);
    }

    virtual void push(const_reference value) = 0;
    void pop(){
        if (size_ > 0) {
            Node_<Type>* current = head_;
            head_ = head_->next_;
            delete current;
            --size_;
        }
    }
    void swap(single_linked_list &other) noexcept{
        Node_<Type>* swap_hade = other.head_;
        size_type swap_size = other.size_;
        (other.head_ = head_, head_ = swap_hade);
        (other.size_ = size_, size_ = swap_size);
    }
 protected:
    Node_<Type>* head_;
    size_type size_;
};
}  // namespace s21