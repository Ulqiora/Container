#pragma once
#include "Node_list.hpp"

namespace s21 {
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
}  // namespace s21