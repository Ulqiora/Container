#include "queue.hpp"
namespace s21 {
template <class Type_queue>
queue<Type_queue>::queue() : size_(0), head_(nullptr) {}

template <class Type_queue>
queue<Type_queue>::queue(size_type n) : size_(n) {
    head_ = new Node<Type_queue>(nullptr);
    Node<Type_queue> *current = head_;
    for (size_type i = 1; i < size_; ++i) {
        current->next_ = new Node<Type_queue>(nullptr);
        current = current->next_;
    }
}

template <class Type_queue>
queue<Type_queue>::queue(std::initializer_list<value_type> const &items) : size_(0), head_(nullptr) {
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type_queue>
queue<Type_queue>::queue(const queue &q) : size_(0), head_(nullptr) {
    if (q.head_ != nullptr) {
        head_ = new Node<Type_queue>(nullptr, q.head_->value_);
        if (q.head_->next_ != nullptr) {
            Node<Type_queue> *current = q.head_->next_;
            while (current != nullptr) push(current->value_);
        }
    }
}

template <class Type_queue>
queue<Type_queue>::queue(queue &&q) {
    (head_ = q.head_, size_ = q.size_, q.head_ = nullptr, q.size_ = 0);
}

template <class Type_queue>
queue<Type_queue>::~queue() {
    while (size_ != 0) pop();
}

template <class Type_queue>
typename s21::queue<Type_queue>::reference queue<Type_queue>::operator=(queue &&q) {
    (head_ = q.head_, size_ = q.size_, q.head_ = nullptr, q.size_ = 0);
}

template <class Type_queue>
typename s21::queue<Type_queue>::const_reference queue<Type_queue>::front() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, queue size equal 0");
    return (head_->value_);
}

template <class Type_queue>
typename s21::queue<Type_queue>::const_reference queue<Type_queue>::back() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, queue size equal 0");
    Node<Type_queue> *current = head_;
    while (current->next_ != nullptr) current = current->next_;
    return (current->value_);
}

template <class Type_queue>
bool queue<Type_queue>::empty() {
    return size_ == 0;
}

template <class Type_queue>
typename s21::queue<Type_queue>::size_type queue<Type_queue>::size() {
    return size_;
}

template <class Type_queue>
void queue<Type_queue>::push(const_reference value) {
    if (size_ == 0) {
        head_ = new Node<Type_queue>(nullptr, value);
    } else {
        Node<Type_queue> *current = head_;
        while (current->next_ != nullptr) current = current->next_;
        current->next_ = new Node<Type_queue>(nullptr, value);
    }
    ++size_;
}

template <class Type_queue>
void queue<Type_queue>::pop() {
    if (size_ > 0) {
        Node<Type_queue> *current = head_;
        head_ = head_->next_;
        delete current;
        --size_;
    }
}

template <class Type_queue>
void queue<Type_queue>::swap(queue &other) noexcept {
    Node<Type_queue> *swap_hade = other.head_;
    size_type swap_size = other.size_;
    (other.head_ = head_, head_ = swap_hade);
    (other.size_ = size_, size_ = swap_hade);
}
}  // namespace s21