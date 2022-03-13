#pragma once
#include <initializer_list>
#include <exception>
#include <iostream>
// #include "cstddef"
namespace s21 {
template <class Type_node>
class Node_list {
   public:
    Node_list* next;
    Node_list* prev;
    Type_node data;
    Node_list(Node_list* next_new, Node_list* prev_new, Type_node const& data_add = Type_node()) {
        next = next_new;    
        prev = prev_new;
        data = data_add;
    }
    ~Node_list(){}
};

template <class Type_iterator_list>
class iterator_list {
    typename s21::Node_list<Type_iterator_list>* iter;

 public:
    iterator_list(Node_list<Type_iterator_list>* v) { iter = v; }
    Type_iterator_list& operator*() { return iter->data; }
    iterator_list operator++() {
        Node_list<Type_iterator_list>* nxt = this->iter->next;
        iter = nxt;
        return (*this);
    }
    iterator_list operator--() {
        Node_list<Type_iterator_list>* pr = this->iter->prev;
        iter = pr;
        return (*this);
    }
    s21::Node_list<Type_iterator_list>* get() { return iter; }
    bool operator!=(const iterator_list<Type_iterator_list>& v) { return (this->iter) != (v.iter); }
    bool operator==(const iterator_list<Type_iterator_list>& v) { return (this->iter) == (v.iter); }
};

template <class Type_const_iterator_list>
class const_iterator_list {
    typename s21::Node_list<Type_const_iterator_list>* iter;
 public:
    const_iterator_list(Node_list<Type_const_iterator_list>* v) { iter = v; }
    Type_const_iterator_list operator*() { return iter->data; }
    const_iterator_list operator++() {
        Node_list<Type_const_iterator_list>* nxt = this->iter->next;
        iter = nxt;
        return (*this);
    }
    const_iterator_list operator--() {
        Node_list<Type_const_iterator_list>* pr = this->iter->prev;
        iter = pr;
        return (*this);
    }
    s21::Node_list<Type_const_iterator_list>* get() { return iter; }
    bool operator!=(const const_iterator_list<Type_const_iterator_list>& v) { return (this->iter) != (v.iter); }
    bool operator==(const const_iterator_list<Type_const_iterator_list>& v) { return (this->iter) == (v.iter); }
};

template <class Type_list>
class list {
 public:
    typedef Type_list value_type;
    typedef Type_list& reference;
    typedef const Type_list& const_reference;
    typedef size_t size_type;
    typedef iterator_list<Type_list> iterator;
    typedef const_iterator_list<Type_list> const_iterator;

    //    Основные методы взаиможействия
    list();
    list(size_type n);
    list(const std::initializer_list<value_type>& items);
    list(list const& v);
    list(list&& v);
    ~list();
    list& operator=(list&& v);

    //    Методы для доступа к элементам класса
    const_reference front();
    const_reference back();

    //    методы для итерирования
    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();

    //    Методы для определения наполнености контейнера
    bool empty();
    size_type size();
    size_type max_size();

    //    Методы для изменения контейнера
    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other);
    void merge(list& other);
    void splice(const_iterator pos, list& other);
    void reverse();
    void unique();
    void sort();

    void emplace_back(){}
    template<class T,class ...Args>
    void emplace_back(T n,Args... args);

    void emplace_front(){}
    template<class T,class ...Args>
    void emplace_front(T n,Args... args);

    void emplace(iterator it){}
    template<class T,class ...Args>
    void emplace(iterator it,T n,Args... args);
 private:
    size_type size_;
    Node_list<Type_list>* head_;
};

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
    // clear();
    if (this != &v) {
        head_ = new Node_list<Type_list>(nullptr, nullptr);
        Node_list<Type_list>* current = v.head_;
        for (size_type i = 0; i != v.size_; ++i) {
            push_back(current->data);
            current = current->next;
        }
    }
}

template <class Type_list>
list<Type_list>::list(list<Type_list>&& v) : size_(0), head_(new Node_list<Type_list>(nullptr, nullptr)){
    if (this != &v) {
        Node_list<Type_list>* swap_node = head_;
        size_type swap_size = size_;
        head_ = v.head_;
        size_ = v.size_;
        v.size_ = swap_size;
        v.head_ = swap_node;
    }
}

template <class Type_list>
list<Type_list>::~list() {
    while (head_->next != nullptr) {
        head_ = head_->next;
        delete head_->prev;
    }
    delete head_;
}

template <class Type_list>
typename s21::list<Type_list>& list<Type_list>::operator=(list&& v) {
    if (this != &v) {
        Node_list<Type_list>* swap_node = head_;
        size_type swap_size = size_;
        head_ = v.head_;
        size_ = v.size_;
        v.head_ = swap_node;
        v.size_ = swap_size;
    }
    return *this;
}

template <class Type_list>
typename s21::list<Type_list>::const_reference list<Type_list>::front() {
    if (size_ == 0) throw std::out_of_range("size of list equal 0");
    return head_->data;
}

template <class Type_list>
typename s21::list<Type_list>::const_reference list<Type_list>::back() {
    if (size_ == 0) throw std::out_of_range("size of list 0");
    Node_list<Type_list>* current = head_;
    if (current->next != nullptr) {
        while (current->next->next != nullptr) {
            current = current->next;
        }
    }
    return current->data;
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::begin() {
    list<Type_list>::iterator i(head_);
    return i;
}

template <class Type_list>
typename list<Type_list>::iterator list<Type_list>::end() {
    Node_list<Type_list>* current = head_;
    while (current->next != nullptr) current = current->next;
    iterator i(current);
    return i;
}

template <class Type_list>
typename list<Type_list>::const_iterator list<Type_list>::cbegin() {
    const_iterator i(head_);
    return i;
}

template <class Type_list>
typename list<Type_list>::const_iterator list<Type_list>::cend() {
    Node_list<Type_list>* current = head_;
    while (current->next != nullptr) current = current->next;
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
        current = current->next;
        delete current->prev;
        current->prev = nullptr;
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
        current = current->prev;
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
    if (pos == end()) throw std::out_of_range("Out of range in erase");
    if (pos == begin()&&size_>0) {
        Node_list<Type_list>* del = head_;
        head_=head_->next;
        delete del;
        --size_;
    } else if (pos != nullptr) {
        for (iterator i = begin(); i != end(); ++i) {
            if (i == pos) {
                Node_list<Type_list>* del = i.get();
                Node_list<Type_list>* nt = del->next;
                Node_list<Type_list>* pr = del->prev;
                (pr->next = nt, nt->prev = pr);
                delete del;
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
    current->data = value;
    current->next = new Node_list<Type_list>(nullptr, current);
    ++size_;
}

template <class Type_list>
void list<Type_list>::pop_back() {
    if (size_ == 0) throw std::invalid_argument("Invalid argument, list size equal 0.");
    Node_list<Type_list>* current = head_;
    while (current->next->next != nullptr) current = current->next;
    if (current == head_) {
        delete head_;
        head_ = current;
    } else {
        Node_list<Type_list>* nt = current->next;
        Node_list<Type_list>* pr = current->prev;
        (pr->next = nt, nt->prev = pr);
        delete current;
    }
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
    head_ = head_->next;
    delete head_->prev;
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
        if (first->data >= second->data) {
            iterator iter(first);
            insert(iter, second->data);
            second = second->next;
        } else {
            first = first->next;
        }
    }
    while (second->next != nullptr) {
        push_back(second->data);
        second = second->next;
    }
}

template <class Type_list>
void list<Type_list>::splice(const_iterator pos, list& other) {
    iterator a(pos.get());
    iterator b = other.begin();
    for (size_type i = 0; i < other.size_; ++i) {
        insert(a, *b);
        ++b;
    }
}

template <class Type_list>
void list<Type_list>::reverse() {
    if (size_ > 1) {
        Node_list<Type_list>* first = head_;
        Node_list<Type_list>* last = head_;
        Type_list swap_data = Type_list();
        while (last->next->next != nullptr) last = last->next;
        int num_i = size_ / 2;
        for (int i = 0; i < num_i; i++) {
            swap_data = first->data;
            first->data = last->data;
            last->data = swap_data;
            first = first->next;
            last = last->prev;
        }
    }
}

template <class Type_list>
void list<Type_list>::unique() {
    if (size_ > 1) {
        Node_list<Type_list>* current = head_;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
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
                if (second->data < first->data) {
                    Type_list swap = second->data;
                    second->data = first->data;
                    first->data = swap;
                }
            }
        }
    }
}

template <class Type_list>
template<class T,class ...Args>
void list<Type_list>::emplace_back(T n,Args... args) {
    push_back(n);
    emplace_back(args...);
}

template <class Type_list>
template<class T,class ...Args>
void list<Type_list>::emplace_front(T n,Args... args) {
    push_front(n);
    emplace_front(args...);
}

template <class Type_list>
template<class T,class ...Args>
void list<Type_list>::emplace(iterator it,T n,Args... args) {
    it=insert(it,n);
    emplace(it, args...);
}
}  // namespace s21