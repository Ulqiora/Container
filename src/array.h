#pragma once

#include <cmath>
#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <class T, std::size_t N>
class array {
 private:
    T _arr[N];

 public:
    // Type definitions
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::size_t size_type;
    // Member Functions
    array();
    array(std::initializer_list<value_type> const& items);
    array(const array& a);
    array(array&& a);
    ~array();
    array<T, N>& operator=(const array& a);
    array<T, N>& operator=(array&& a);
    // Element access
    reference at(size_type pos);
    reference operator[](size_type pos);
    const_reference front() const;
    const_reference back() const;
    iterator data();
    // Iterators
    iterator begin();
    const_iterator cbegin() const;
    iterator end();
    const_iterator cend() const;
    // Capacity
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    // Modifiers
    void swap(array& other);
    void fill(const_reference value);
    // Other
 private:
    inline void copyFromArr(const array& a);
};

}  // namespace s21
