#pragma once
#include <initializer_list>
#include <exception>
#include <iostream>
#include "cstddef"
#include "iterator_list.hpp"
// #include <list>
namespace s21 {

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

 private:
    size_type size_;
    Node_list<Type_list>* head_;
};
}  // namespace s21