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
list<Type_list>::list(const std::initializer_list<Type_list>& items) : size_(0) {
    head_ = new Node_list<Type_list>(nullptr, nullptr);
    for (auto i = items.begin(); i != items.end(); ++i) {
        push_back(*i);
    }
}

template <class Type_list>
list<Type_list>::list(list<Type_list> const& v) : size_(0) {
    head_=new Node_list<Type_list>(nullptr,nullptr);
    Node_list<Type_list>* current=v.head_;
    for (size_type i = 0; i != v.size_; ++i) {
        push_back(*(current->data));
        current=current->next;
    }
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
    head_ = new Node_list<Type_list>(nullptr, nullptr);
    Node_list<Type_list>* current_this = head_;
    for (auto i = v.begin(); i != v.end(); ++i) {
        push_back(*i);
    }
    v.clear();
}

template <class Type_list>
typename s21::list<Type_list>::const_reference list<Type_list>::front() {
    if (head_ == nullptr) throw std::out_of_range("size of list equal 0");
    return *(head_->data);
}

template <class Type_list>
typename s21::list<Type_list>::const_reference list<Type_list>::back() {
    if (head_ == nullptr) throw std::out_of_range("size of list 0");
    Node_list<Type_list>* current = head_;
    if (current->next != nullptr) {
        while (current->next->next != nullptr) {
            current = current->next;
        }
    }
    return *(current->data);
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::begin() {
    list<Type_list>::iterator i(head_);
    return i;
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::end() {
    Node_list<Type_list>* current = head_;
    if (current != nullptr) {
        while (current->next != nullptr) current = current->next;
    }
    iterator i(current);
    return i;
}

template <class Type_list>
typename list<Type_list>::const_iterator list<Type_list>::cbegin() {
    list<Type_list>::const_iterator i(head_);
    return i;
}

template <class Type_list>
typename list<Type_list>::const_iterator list<Type_list>::cend() {
    Node_list<Type_list>* current = head_;
    if (current != nullptr) {
        while (current->next != nullptr) current = current->next;
    }
    const_iterator i(current);
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
typename list<Type_list>::size_type list<Type_list>::max_size() {
    // return std::numeric_limits<Type_list>::max();
    return 0;
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
        current=current->prev;
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
void list<Type_list>::erase(iterator pos) {
    if(pos==end()) throw std::out_of_range("Out of range in erase");
    if (pos == begin()) {
        return;
    } else if (pos != nullptr) {
        for (iterator i = begin(); i != end(); ++i) {
            if (i == pos) {
                Node_list<Type_list>* del = i.get();
                del->prev->next = del->next;
                del->next->prev = del->prev;
                break;
            }
        }
        --size_;
    }
}

template <class Type_list>
void list<Type_list>::push_back(const_reference value) {
    Node_list<Type_list>* current = head_;
    while (current->next != nullptr) {
        current = current->next;
    }
    *(current->data) = value;
    current->next = new Node_list<Type_list>(nullptr, current);
    ++size_;
}

template <class Type_list>
void list<Type_list>::pop_back() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, list size equal 0.");
    Node_list<Type_list>* current = head_;
    while (current->next != nullptr) {
        current = current->next;
    }
    delete[] current->data;
    current = current->prev;
    current->next = nullptr;
    --size_;
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
void list<Type_list>::merge(list& other) {
    Node_list<Type_list>* first = head_;
    Node_list<Type_list>* second = other.head_;
    while (first->next != nullptr && second->next != nullptr) {
        if (*(first->data) >= *(second->data)) {
            iterator iter(first);
            insert(iter, *(second->data));
            second = second->next;
        } else {
            first = first->next;
        }
    }
    while(second->next != nullptr){
        push_back(*(second->data));
        second=second->next;
    }
}

template <class Type_list>
void list<Type_list>::splice(const_iterator pos, list& other) {
    iterator a(pos.get());
    iterator b=other.begin();
    for(size_type i=0;i<other.size_;++i){
        insert(a,*b);
        ++b;
    }
}

template <class Type_list>
void list<Type_list>::reverse() {
    if (size_ > 1) {
        Node_list<Type_list>* first = head_;
        Node_list<Type_list>* last = head_;
        Type_list* swap_data = nullptr;
        while (last->next->next != nullptr) last = last->next;
        int num_i=size_/2;
        for(int i=0;i<num_i;i++){
            swap_data=first->data;
            first->data=last->data;
            last->data=swap_data;
            first=first->next;
            last=last->prev;
        }
    }
}

template <class Type_list>
void list<Type_list>::unique() {
    if (size_ > 1) {
        Node_list<Type_list>* current = head_;
        while (current->next != nullptr) {
            if (*(current->data) == *(current->next->data)) {
                iterator del(current);
                current = current->next;
                erase(del);
            } else {
                current = current->next;
            }
        }
    }
}

template <class Type_list>
void list<Type_list>::sort() {
    if (size_ > 1) {
        for (iterator i = begin(); i != end(); ++i) {
            Node_list<Type_list>* first = i.get();
            for (iterator j = i; j != end(); ++j) {
                Node_list<Type_list>* second = j.get();
                if (*(second->data) < *(first->data)) {
                    Type_list swap = *(second->data);
                    *(second->data) = *(first->data);
                    *(first->data) = swap;
                }
            }
        }
    }
}
}  // namespace s21