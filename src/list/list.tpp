#include "list.hpp"

namespace s21 {
template <class Type_list>
list<Type_list>::list() : size_(0), head_(new Node_list<Type_list>(nullptr, nullptr)) {}

template <class Type_list>
list<Type_list>::list(size_type n) : size_(n) {
    head_ = new Node_list<Type_list>(nullptr, nullptr);
    Node_list<Type_list>* current = head_;
    for (size_type i = 1; i <= n; i++) {
        current->next = new Node_list<Type_list>(nullptr, current);
        current = current->next;
    }
}

template <class Type_list>
list<Type_list>::list(std::initializer_list<Type_list> const& items) : size_(items.size()) {
    head_ = new Node_list<Type_list>(nullptr, nullptr, *(items.begin()));
    Node_list<Type_list>* current = head_;
    for (auto i = items.begin(); i != items.end(); ++i) {
        if (i != items.begin()) {
            current->next = new Node_list<Type_list>(nullptr, current, *i);
            current = current->next;
        }
    }
    current->next = new Node_list<Type_list>(nullptr, current);
}

template <class Type_list>
list<Type_list>::list(const list<Type_list>& v) : size_(v.size_){
    head_ = new Node_list<Type_list>(nullptr, nullptr, *(v.begincbegin()));
    Node_list<Type_list>* current_this = head_;
    for (auto i = v.begincbegin(); i != v.endcend(); ++i) {
        if (i != v.begincbegin()) {
            current_this = new Node_list<Type_list>(nullptr, current_this, i->data);
            current_this = current_this->next;
        }
    }
    current_this = new Node_list<Type_list>(nullptr, current_this);
}

template <class Type_list>
list<Type_list>::list(list<Type_list>&& v) {
    head_ = v.head_;
    size_ = v.size_;
    v.size_ = 0;
    v.head_ = NULL;
}

template <class Type_list>
list<Type_list>::~list() {
    while (head_ != nullptr) {
        delete[] head_->data;
        head_->data = nullptr;
        head_ = head_->next;
    }
}

template <class Type_list>
typename s21::list<Type_list>& list<Type_list>::operator=(list&& v) {
    clear();
    head_ = new Node_list<Type_list>(nullptr, nullptr, *(v.begincbegin()));
    Node_list<Type_list>* current_this = head_;
    for (auto i = v.begincbegin(); i != v.endcend(); ++i) {
        if (i != v.begincbegin()) {
            current_this->next = new Node_list<Type_list>(nullptr, current_this, i->data);
            current_this = current_this->next;
        }
    }
    current_this->next = new Node_list<Type_list>(nullptr, current_this);
}

template <class Type_list>
typename s21::list<Type_list>::const_reference list<Type_list>::front() {
    if (head_ == nullptr) throw std::out_of_range("size of list equal 0");
    return *(head_->data);
}

template <class Type_list>
typename s21::list<Type_list>::const_reference list<Type_list>::back() {
    if (head_ == nullptr) throw std::out_of_range("size of list equal 0");
    Node_list<Type_list>* current = head_;
    if (current->next != nullptr) {
        while (current->next->next != nullptr) {
            current = current->next;
        }
    }
    return *(current->data);
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::begincbegin() {
    list<Type_list>::iterator i(head_);
    return i;
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::endcend() {
    Node_list<Type_list>* current=head_;
    if (current != nullptr) {
        while (current->next != nullptr) current = current->next;
    }
    iterator i(current);
    return i;
}

template <class Type_list>
bool list<Type_list>::empty() {
    return (size_ == 0);
}

template <class Type_list>
typename list<Type_list>::size_type list<Type_list>::size() {
    return size_;
}

template <class Type_list>
void list<Type_list>::clear() {
    Node_list<Type_list>* current = head_;
    while (current->next != nullptr) {
        delete current->data;
        current = current->next;
    }
    head_ = current;
    size_ = 0;
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::insert(iterator pos, const_reference value) {
    Node_list<Type_list>* current = head_;
    while (current != pos.get() && current != nullptr) {
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Iterator does not belong to the given list");
    }
    if (current != head_) {
        Node_list<Type_list>* new_node = new Node_list<Type_list>(current, current->prev, value);
        current->prev->next = new_node;
        current->prev = new_node;
    } else {
        Node_list<Type_list>* new_node = new Node_list<Type_list>(head_, nullptr, value);
        head_->prev = new_node;
        head_ = new_node;
        current = head_;
    }
    ++size_;
    return current;
}

template <class Type_list>
void list<Type_list>::push_back(const_reference value) {
    Node_list<Type_list>* current = head_;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->data=value;
    current->next = new Node_list<Type_list>(nullptr, current);
    ++size_;
}

template <class Type_list>
void list<Type_list>::pop_back() {
    if (head_ != nullptr) {
        Node_list<Type_list>* current = head_;
        while (current->next != nullptr) {
            current = current->next;
        }
        delete[] current->data;
        current = current->prev;
        current->next=nullptr;
        --size_;
    }
}

template <class Type_list>
void list<Type_list>::push_front(const_reference value) {
    head_->prev = new Node_list<Type_list>(head_, nullptr, value);
    head_ = head_->prev;
    ++size_;
}

template <class Type_list>
void list<Type_list>::pop_front() {
    delete[] head_->data;
    head_ = head_->next;
}

template <class Type_list>
void list<Type_list>::swap(list& other) {
    Node_list<Type_list>* swap_node = head_;
    size_type swap_size = size_;
    head_ = other.head_;
    size_ = other.size_;
    other.head_ = swap_node;
    other.size_ = swap_size;
}

template <class Type_list>
void list<Type_list>::merge(list& other) {}

template <class Type_list>
void list<Type_list>::splice(const_iterator pos, list& other) {}

template <class Type_list>
void list<Type_list>::reverse() {
    if (head_ != nullptr) {
        Node_list<Type_list>* first = head_;
        Node_list<Type_list>* last = head_;
        Node_list<Type_list>* swap_data = nullptr;
        while (last->next != nullptr) last = last->next;
        while (first->next != last || first != last) {
            swap_data = first->data;
            first->data = last->data;
            last->data = swap_data;
        }
    }
}

template <class Type_list>
void list<Type_list>::unique() {
    if (head_ != nullptr) {
        Node_list<Type_list>* current = head_;
        while (current->next != nullptr) {
            if (*(current->data) == *(current->next->data)) {
                Node_list<Type_list>* swap = current;
                current->next = current->next->next;
                current->next->prev = current;
                delete swap;
            } else {
                current = current->next;
            }
        }
    }
}

template <class Type_list>
void list<Type_list>::sort() {}
}  // namespace s21
