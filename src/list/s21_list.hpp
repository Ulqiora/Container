#pragma once
#include "../Sequence_Container.hpp"
#include <initializer_list>
template <class Type>
class list : public Sequence<Type> {
   private:
    size_type size_;
    iterator head_;
    iterator tail_;
   public:\
    //    Основные методы взаиможействия
    list();
    list(size_type n);
    list(std::initializer_list<value_type> const& items);
    list(const list &v);
    list(list &&v);
    ~list();
    operator=(list &&v);
    //    Методы для доступа к элементам класса
    const_reference front();
    const_reference back();
    //    методы для итерирования
    iterator begincbegin();
    iterator endcend();
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
};