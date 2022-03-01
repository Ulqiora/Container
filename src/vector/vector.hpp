#pragma once
#include <initializer_list>
#include <iostream>

#include "../Sequence_Container.hpp"
namespace s21 {
template <class Type_vector>
class vector : public Sequence<Type> {
 public:
    typedef Type_vector value_type;
    typedef Type_vector& reference;
    typedef const Type_vector& const_reference;
    typedef Type_vector* iterator;
    typedef const Type_vector* const_iterator;
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
    iterator data();

    //    методы для итерирования
    iterator begincbegin();
    iterator endcend();

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