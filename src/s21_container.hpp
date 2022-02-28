#ifndef SRC_S21_CONTAINER_HPP_
#define SRC_S21_CONTAINER_HPP_

#include <exception>
#include <iostream>

template <typename Type>
class s21_vector {
   private:
    int capacity_;
    int size_;
    Type* mass_;
    void doublingCapacity();

   public:
    typedef Type* iterator;
    //    Конструкторы
    s21_vector();
    s21_vector(s21_vector& other);
    s21_vector(s21_vector&& other) noexcept;
    //    Деструктор
    ~s21_vector();
    //    Операторы
    s21_vector& operator=(const s21_vector& other);
    bool operator==(const s21_vector& other);
    //    Доступ к элементам
    Type& at(size_t i);
    Type& operator[](size_t i);
    Type& front();
    Type& back();
    //    Итераторы
    inline s21_vector<Type>::iterator begin() { return mass_; }
    inline s21_vector<Type>::iterator end() { return mass_ + size; }
    //    Работа с размером вектора
    inline bool is_empty() const;
    inline int size() const;
    void reserve(int new_cap);
    inline int capacity() const;
    void shrink_to_rit();
    //    Модификаторы
    void clear();
    s21_vector<Type>::iterator insert(s21_vector<Type>::iterator it, const Type& value) {
        if (size >= capacity) doublingCapacity();
        for (auto i = end();; --i) {
            *i = *(i - 1);
            if (i != it) {
                *i = value;
                break;
            }
        }
        size++;
    }

    s21_vector<Type>::iterator erase(s21_vector<Type>::iterator first, s21_vector<Type>::iterator last) {
        int j = 0;
        for (auto i = first, j = 0; (last + j) != end(); i++, j++) {
            *i = (last + j);
        }
        size -= (j - 1);
        return first;
    }
    s21_vector<Type>::iterator erase(s21_vector<Type>::iterator pos) {
        for (auto i = pos; i != end(); i++) {
            *i = *(i + 1);
        }
        --size;
        return pos;
    }

    void push_back(const Type& value);
    void push_back(Type&& value);

    void pop_back();

    void resize(int count);
    void resize(int count, const Type& value);

    void swap(s21_vector& other);
};

#endif  //    SRC_S21_CONTAINER_HPP_
