#pragma once
#include <initializer_list>
#include <iostream>

#include "iterator_vector.hpp"

namespace s21 {
template <class Type_vector>
class vector {
 public:
    typedef Type_vector value_type;
    typedef Type_vector& reference;
    typedef const Type_vector& const_reference;
    typedef iterator_vector<Type_vector> iterator;
    typedef const_iterator_vector<Type_vector> const_iterator;
    typedef size_t size_type;
    //    Основные методы взаиможействия
    vector();
    vector(size_type n);
    vector(std::initializer_list<value_type> const& items);
    vector(const vector& v);
    vector(vector&& v) noexcept;
    ~vector();
    vector operator=(vector&& v);

    //    Методы для доступа к элементам класса
    reference at(size_type pos);
    reference operator[](size_type pos);
    const_reference front();
    const_reference back();
    Type_vector* data();

    //    методы для итерирования
    iterator_vector<Type_vector> begin();
    iterator_vector<Type_vector> end();
    const_iterator cbegin();
    const_iterator cend();

    //    Методы для определения наполнености контейнера
    bool empty();
    size_type size();
    size_type max_size();
    void reserve(size_type new_cap);
    size_type capacity();
    void shrink_to_fit();

    //    Методы для изменения контейнера
    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void swap(vector& other);

 private:
    size_type size_;
    size_type capacity_;
    Type_vector* mass_;
    void doublingCapacity();
};
}  // namespace s21