#include "s21_vector.hpp"

template <class Type>
void vector<Type>::doublingCapacity() {
    capacity_ *= 2;
    Type* copy = new Type[capacity_]();
    for (int i = 0; i < size; i++) copy[i] = mass_[i];
    delete[] mass_;
    mass_ = copy;
}
//    Конструкторы
template <class Type>
vector<Type>::vector() : capacity_(1), size_(0), mass_(new Type[capacity_]) {}

template <class Type>
vector<Type>::vector(const vector& other) {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        mass_ = new Type[capacity_]();
        for (int i = 0; i < size; i++) mass_[i] = other.mass_[i];
    }
}

template <class Type>
vector<Type>::vector(vector&& other) noexcept {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        mass_ = new Type[capacity_]();
        for (int i = 0; i < size; i++) mass_[i] = other.mass_[i];
        other.mass_ = nullptr;
        other.size = other.capacity = 0;
    }
}
//    Деструктор
template <class Type>
vector<Type>::~vector() {
    delete[] mass_;
}
//    Операторы
template <class Type>
vector<Type>& vector<Type>::operator=(const vector<Type> & other) {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        mass_ = new Type[capacity]();
        for (int i = 0; i < size; i++) mass_[i] = other.mass_[i];
    }
    return (*this);
}

//    Доступ к элементам
template <class Type>
Type& vector<Type>::at(size_t i) {
    if (i < 0 || i >= size) throw std::out_of_range("index<0 or index>=size of vector");
    return mass_[i];
}

template <class Type>
Type& vector<Type>::operator[](size_t i) {
    return mass_[i];
}

template <class Type>
Type& vector<Type>::front() {
    if (size == 0) throw std::out_of_range("size==0 of vector");
    return mass_[0];
}
template <class Type>
Type& vector<Type>::back() {
    if (size == 0) throw std::out_of_range("size==0 of vector");
    return mass_[size - 1];
}
//    Итераторы

//    Работа с размером вектора
template <class Type>
inline bool vector<Type>::is_empty() const {
    return size == 0;
}

template <class Type>
inline vector<Type>::size_type vector<Type>::size() const {
    return size;
}

template <class Type>
void vector<Type>::reserve(int new_cap) {
    if (capacity < new_cap) {
        capacity = new_cap;
        Type* copy = new Type[capacity]();
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}

template <class Type>
inline int vector<Type>::capacity() const {
    return capacity;
}

template <class Type>
void vector<Type>::shrink_to_rit() {
    if (capacity > (size + 1)) {
        capacity = size + 1;
        Type* copy = new Type[capacity]();
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}
//    Модификаторы
template <class Type>
void vector<Type>::clear() {
    if (size > 0) {
        delete[] mass_;
        size = 0;
        capacity = 1;
        mass_ = new Type[capacity]();
    }
}

template <class Type>
void vector<Type>::push_back(const Type& value) {
    if (size >= capacity) doublingCapacity();
    mass_[size] = value;
    size++;
}
template <class Type>
void vector<Type>::push_back(Type&& value) {
    if (size >= capacity) doublingCapacity();
    mass_[size] = value;
    size++;
}

template <class Type>
void vector<Type>::pop_back() {
    if (size > 0) size--;
}

template <class Type>
void vector<Type>::resize(int count) {
    if (size >= count) {
        size = count;
    } else {
        if (count > capacity) {
            Type* copy = new Type[count]();
            capacity = count;
            for (int i = 0; i < size; i++) copy[i] = mass_[i];
            delete[] mass_;
            mass_ = copy;
        }
        size = count;
    }
}

template <class Type>
void vector<Type>::resize(int count, const Type& value) {
    if (size >= count) {
        size = count;
    } else {
        if (count > capacity) {
            Type* copy = new Type[count](value);
            capacity = count;
            for (int i = 0; i < size; i++) copy[i] = mass_[i];
            delete[] mass_;
            mass_ = copy;
        }
        size = count;
    }
}

template <class Type>
void vector<Type>::swap(vector& other) {
    vector* var = &other;
    vector* copy = this;
    this = &other;
    var = copy;
}
//    Другие методы