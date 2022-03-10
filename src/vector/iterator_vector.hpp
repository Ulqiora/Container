#pragma once

namespace s21 {
template <class Type>
class iterator_vector {
    Type* iter;

 public:
    iterator_vector(Type* v) { iter = v; }
    Type& operator*() { return *iter; }
    iterator_vector operator++() {
        ++iter;
        return (*this);
    }
    iterator_vector operator--() {
        --iter;
        return (*this);
    }
    Type* get() { return iter; }
    bool operator!=(const iterator_vector<Type>& v) { return (this->iter) != (v.iter); }
    bool operator==(const iterator_vector<Type>& v) { return (this->iter) == (v.iter); }
};

template <class Type>
class const_iterator_vector {
    Type* iter;

 public:
    const_iterator_vector(Type* v) { iter = v; }
    Type operator*() { return iter->data; }
    const_iterator_vector operator++() {
        ++iter;
        return (*this);
    }
    const_iterator_vector operator--() {
        --iter;
        return (*this);
    }
    Type* get() { return iter; }
    bool operator!=(const const_iterator_vector<Type>& v) { return (this->iter) != (v.iter); }
    bool operator==(const const_iterator_vector<Type>& v) { return (this->iter) == (v.iter); }
};
}  // namespace s21