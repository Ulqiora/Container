#include "stack.hpp"
namespace s21 {
template <class Type_stack>
stack<Type_stack>::stack() : size_(0), head_(nullptr) {}

template <class Type_stack>
stack<Type_stack>::stack(size_type n) : size_(n) {
    head_ = new Node<Type_stack>(nullptr);
    Node<Type_stack> *current = head_;
    for (size_type i = 1; i < size_; ++i) {
        current->next_ = new Node<Type_stack>(nullptr);
        current = current->next_;
    }
}

template <class Type_stack>
stack<Type_stack>::stack(std::initializer_list<value_type> const &items) : size_(0), head_(nullptr) {
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type_stack>
stack<Type_stack>::stack(const stack &q) : size_(0), head_(nullptr) {
    stack<Type_stack> a;
    Node<Type_stack> *current = q.head_;
    while (current != nullptr) {
        a.push(current->value_);
        current = current->next_;
    }
    while (a.head_ != nullptr) {
        push(a.head_->value_);
        a.pop();
    }
}

template <class Type_stack>
stack<Type_stack>::stack(stack &&q) {
    (head_ = q.head_, size_ = q.size_, q.head_ = nullptr, q.size_ = 0);
}

template <class Type_stack>
stack<Type_stack>::~stack() {
    while (size_ != 0) pop();
}

template <class Type_stack>
typename s21::stack<Type_stack>::reference stack<Type_stack>::operator=(stack &&q) {
    (head_ = q.head_, size_ = q.size_, q.head_ = nullptr, q.size_ = 0);
    return *this;
}

template <class Type_stack>
typename s21::stack<Type_stack>::const_reference stack<Type_stack>::front() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, stack size equal 0");
    return (head_->value_);
}

template <class Type_stack>
typename s21::stack<Type_stack>::const_reference stack<Type_stack>::back() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, stack size equal 0");
    Node<Type_stack> *current = head_;
    while (current->next_ != nullptr) current = current->next_;
    return (current->value_);
}

template <class Type_stack>
bool stack<Type_stack>::empty() {
    return size_ == 0;
}

template <class Type_stack>
typename s21::stack<Type_stack>::size_type stack<Type_stack>::size() {
    return size_;
}

template <class Type_stack>
void stack<Type_stack>::push(const_reference value) {
    if (size_ == 0) {
        head_ = new Node<Type_stack>(nullptr, value);
    } else {
        Node<Type_stack> *current = new Node<Type_stack>(head_, value);;
        head_ = current;
    }
    ++size_;
}

template <class Type_stack>
void stack<Type_stack>::pop() {
    if (size_ > 0) {
        Node<Type_stack> *current = head_;
        head_ = head_->next_;
        delete current;
        --size_;
    }
}

template <class Type_stack>
void stack<Type_stack>::swap(stack &other) noexcept {
    Node<Type_stack> *swap_hade = other.head_;
    size_type swap_size = other.size_;
    (other.head_ = head_, head_ = swap_hade);
    (other.size_ = size_, size_ = swap_size);
}
}  // namespace s21