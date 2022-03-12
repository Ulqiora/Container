#include "array.h"

namespace s21 {

// Constructors, operator= & destructor

template <class T, std::size_t N>
array<T, N>::array() {}

template <class T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const& items) {
    if (items.size() > N) {
        throw std::out_of_range("Too many initializers!");
    }
    typename std::initializer_list<value_type>::const_iterator it;
    size_type i = 0;
    for (it = items.begin(); it != items.end(); ++it, ++i) {
        _arr[i] = *it;
    }
}

template <class T, std::size_t N>
array<T, N>::array(const array& a) {
    copyFromArr(a);
}

template <class T, std::size_t N>
array<T, N>::array(array&& a) {
    std::move(a._arr, a._arr + N, _arr);
}

template <class T, std::size_t N>
array<T, N>::~array() {}

template <class T, std::size_t N>
array<T, N>& array<T, N>::operator=(const array& a) {
    copyFromArr(a);
    return *this;
}

template <class T, std::size_t N>
array<T, N>& array<T, N>::operator=(array&& a) {
    std::move(a._arr, a._arr + N, _arr);
    return *this;
}

// Element access

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
    if (pos >= N) {
        throw std::out_of_range("Index out of array bounds!");
    }
    return _arr[pos];
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
    return _arr[pos];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
    return _arr[0];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
    return _arr[N - 1];
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
    return _arr;
}

// Iterators

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
    return _arr;
}

template <class T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cbegin() const {
    return _arr;
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
    return _arr + N;
}

template <class T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cend() const {
    return _arr + N;
}

// Capacity

template <class T, std::size_t N>
bool array<T, N>::empty() const {
    return cbegin() == cend();
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const {
    return N;
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const {
    return static_cast<size_type>(pow(2, sizeof(void*) * 8) / sizeof(T) - 1);
}

// Modifiers

template <class T, std::size_t N>
void array<T, N>::swap(array& other) {
    std::swap_ranges(_arr, _arr + N, other._arr);
}

template <class T, std::size_t N>
void array<T, N>::fill(const_reference value) {
    for (size_type i = 0; i < N; i++) {
        _arr[i] = value;
    }
}

// Other

template <class T, std::size_t N>
inline void array<T, N>::array::copyFromArr(const array& a) {
    for (size_type i = 0; i < N; i++) {
        _arr[i] = a._arr[i];
    }
}

}  // namespace s21
