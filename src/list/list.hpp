#pragma once
#include <initializer_list>
#include "cstddef"
// #include <list>
namespace s21 {
template <class Type_node>
class Node {
 public:
    Node* next;
    Node* prev;
    Type_node data;
    Node(Node* next_new, Node* prev_new, Type_node& data_add = Type_node()) {
        next = next_new;
        prev = prev_new;
        data = data_add;
    }
    ~Node();
};

template <class Type_node>
class iterator_list {
    typename s21::Node<Type_list>* iter;
    iterator(s21::Node<Type_list>* v) iter(v);
    Type_list& operator*() { return this->iter->data; }
    iterator_list operator++() {
        this = this->iter->next;
        return (*this);
    }
    iterator_list operator--() {
        this = this->iter->prev;
        return (*this);
    }
    bool operator!=(iterator_list& v) { return (this) != (&v); }
    bool operator==(iterator_list& v) { return (this) == (&v); }
};

template <class Type_list>
class list {
 public:
    typedef Type_list value_type;
    typedef Type_list& reference;
    typedef const Type_list& const_reference;
    typedef size_t size_type;
    typedef iterator_list<Type_list> iterator;
    //    Основные методы взаиможействия
    list();
    list(size_type n);
    list(std::initializer_list<value_type> const& items);
    list(const list& v);
    list(list&& v);
    ~list();
    operator=(list&& v);
    //    Методы для доступа к элементам класса
    const_reference front();
    const_reference back() {}
    //    методы для итерирования
    iterator begincbegin() {}
    iterator endcend() {}
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

 private:
    size_type size_;
    Node<Type_list>* head_;
};
}  // namespace s21