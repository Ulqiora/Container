#pragma once

#include <initializer_list>
#include <iostream>

namespace s21 {

template <class Node_type>
class Node_ {
 public:
    Node_type value_;
    Node_* next_;
    Node_(Node_* next, Node_type const& data_add = Node_type()) : next_(next), value_(data_add) {}
    ~Node_() {}
};

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
    void pop() {
        if (size_ > 0) {
            Node_<Type>* current = head_;
            head_ = head_->next_;
            delete current;
            --size_;
        }
    }
    void swap(single_linked_list& other) noexcept {
        Node_<Type>* swap_hade = other.head_;
        size_type swap_size = other.size_;
        (other.head_ = head_, head_ = swap_hade);
        (other.size_ = size_, size_ = swap_size);
    }

 protected:
    Node_<Type>* head_;
    size_type size_;
};

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
    void push(const_reference value);

    void emplace_front() {}
    template <class T, class... Args>
    void emplace_front(T n, Args... args);
};

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
    void push(const_reference value);

    void emplace_back() {}
    template <class T, class... Args>
    void emplace_back(T n, Args... args);
};

template <class Type>
queue<Type>::queue() {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
}

template <class Type>
queue<Type>::queue(size_type n) {
    single_linked_list<Type>::size_ = n;
    single_linked_list<Type>::head_ = new Node_<Type>(nullptr);
    Node_<Type>* current = single_linked_list<Type>::head_;
    for (size_type i = 1; i < single_linked_list<Type>::size_; ++i) {
        current->next_ = new Node_<Type>(nullptr);
        current = current->next_;
    }
}

template <class Type>
queue<Type>::queue(std::initializer_list<value_type> const& items) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type>
queue<Type>::queue(const queue& q) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
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
queue<Type>::queue(queue&& q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr,
     q.size_ = 0);
}

template <class Type>
queue<Type>::~queue() {
    while (single_linked_list<Type>::size_ != 0) single_linked_list<Type>::pop();
}

template <class Type>
typename s21::queue<Type>::reference queue<Type>::operator=(queue&& q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr,
     q.size_ = 0);
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

template <class Type>
stack<Type>::stack() {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
}

template <class Type>
stack<Type>::stack(size_type n) {
    single_linked_list<Type>::size_ = n;
    single_linked_list<Type>::head_ = new Node_<Type>(nullptr);
    Node_<Type>* current = single_linked_list<Type>::head_;
    for (size_type i = 1; i < single_linked_list<Type>::size_; ++i) {
        current->next_ = new Node_<Type>(nullptr);
        current = current->next_;
    }
}

template <class Type>
stack<Type>::stack(std::initializer_list<value_type> const& items) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
    for (auto i = items.begin(); i != items.end(); ++i) push(*i);
}

template <class Type>
stack<Type>::stack(const stack& q) {
    single_linked_list<Type>::size_ = 0;
    single_linked_list<Type>::head_ = nullptr;
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
stack<Type>::stack(stack&& q) {
    (single_linked_list<Type>::head_ = q.head_, single_linked_list<Type>::size_ = q.size_, q.head_ = nullptr,
     q.size_ = 0);
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