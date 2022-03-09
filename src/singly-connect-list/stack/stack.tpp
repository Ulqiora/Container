#include "stack.hpp"
namespace s21 {
template <class Type>
stack<Type>::stack() {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
}

template <class Type>
stack<Type>::stack(size_type n) {
    single_linked_list<Type>::size_=n;
    single_linked_list<Type>::head_ = new Node<Type>(nullptr);
    Node<Type> *current = single_linked_list<Type>::head_;
    for (size_type i = 1; i < single_linked_list<Type>::size_; ++i) {
        current->next_ = new Node<Type>(nullptr);
        current = current->next_;
    }
}

template <class Type>
stack<Type>::stack(std::initializer_list<value_type> const &items) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type>
stack<Type>::stack(const stack &q) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
    stack<Type> a;
    Node<Type> *current = q.head_;
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
stack<Type>::stack(stack &&q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr,
     q.size_ = 0);
}

template <class Type>
stack<Type>::~stack() {
    while (single_linked_list<Type>::size_ != 0) single_linked_list<Type>::pop();
}

template <class Type>
typename s21::stack<Type>::reference stack<Type>::operator=(stack &&q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr, q.size_ = 0);
    return *this;
}

template <class Type>
void stack<Type>::push(const_reference value) {
    if (single_linked_list<Type>::size_ == 0) {
        single_linked_list<Type>::head_ = new Node<Type>(nullptr, value);
    } else {
        Node<Type> *current = new Node<Type>(single_linked_list<Type>::head_, value);;
        single_linked_list<Type>::head_ = current;
    }
    ++single_linked_list<Type>::size_;
}
}  // namespace s21