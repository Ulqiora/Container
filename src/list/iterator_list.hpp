#pragma once
#include "Node_list.hpp"

namespace s21 {
template <class Type_iterator_list>
class iterator_list {
   public:
    typename Node_list<Type_iterator_list>* iter;
    iterator(Node_list<Type_iterator_list>* v) {}
    Type_iterator_list& operator*() { return this->iter->data; }
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
}  // namespace s21