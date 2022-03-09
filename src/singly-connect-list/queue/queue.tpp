#include "queue.hpp"
namespace s21 {
template <class Type>
queue<Type>::queue() {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
}

template <class Type>
queue<Type>::queue(size_type n) {
    single_linked_list<Type>::size_ = n;
    single_linked_list<Type>::head_ = new Node<Type>(nullptr);
    Node<Type> *current = single_linked_list<Type>::head_;
    for (size_type i = 1; i < single_linked_list<Type>::size_; ++i) {
        current->next_ = new Node<Type>(nullptr);
        current = current->next_;
    }
}

template <class Type>
queue<Type>::queue(std::initializer_list<value_type> const &items) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type>
queue<Type>::queue(const queue &q) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
    if (q.head_ != nullptr) {
        push(q.head_->value_);
        if (q.head_->next_ != nullptr) {
            Node<Type> *current = (q.head_)->next_;
            while (current != nullptr) {
                push(current->value_);
                current = current->next_;
            }
        }
    }
}

template <class Type>
queue<Type>::queue(queue &&q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr,
     q.size_ = 0);
}

template <class Type>
queue<Type>::~queue() {
    while (single_linked_list<Type>::size_ != 0) single_linked_list<Type>::pop();
}

template <class Type>
typename s21::queue<Type>::reference queue<Type>::operator=(queue &&q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr, q.size_ = 0);
}

template <class Type>
void queue<Type>::push(const_reference value) {
    if (single_linked_list<Type>::size_ == 0) {
        single_linked_list<Type>::head_ = new Node<Type>(nullptr, value);
    } else {
        Node<Type> *current = single_linked_list<Type>::head_;
        while (current->next_ != nullptr) current = current->next_;
        current->next_ = new Node<Type>(nullptr, value);
    }
    ++single_linked_list<Type>::size_;
}
}  // namespace s21