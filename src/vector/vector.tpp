#pragma once
#include "vector.h"

namespace s21 {
template<class Type_vector>
void s21::vector<Type_vector>::doublingCapacity() {
    capacity_*=2;
    mass_=(Type_vector*)realloc(mass_,capacity_*sizeof(Type_vector));
}

template<class Type_vector>
s21::vector<Type_vector>::vector() : capacity_(1), size_(0), mass_(new value_type[capacity_]()) {}

template<class Type_vector>
s21::vector<Type_vector>::vector(size_type n) : capacity_(n + 1), size_(n), mass_(new value_type[capacity_]()) {}

template<class Type_vector>
s21::vector<Type_vector>::vector(std::initializer_list<value_type> const& items)
    : capacity_(items.size() + 1), size_(items.size()), mass_(new value_type[capacity_]()) {
    int j=0;
    for (auto i = items.begin(); i != items.end(); i++) {
        mass_[j] = *i;
        j++;
    }
}

template<class Type_vector>
s21::vector<Type_vector>::vector(const vector& v) {
    if (this != &v) {
        capacity_ = v.size_+1;
        size_ = v.size_;
        mass_ = new value_type[capacity_]();
        for (int i = 0; i < size_; i++) mass_[i] = v.mass_[i];
    }
}

template<class Type_vector>
s21::vector<Type_vector>::vector(vector&& v) noexcept {
    if (this != &v) {
        capacity_ = v.capacity_;
        size_ = v.size_;
        mass_ = new value_type[capacity_]();
        for (int i = 0; i < size_; i++) mass_[i] = v.mass_[i];
        v.mass_ = nullptr;
        v.size_ = v.capacity_ = 0;
    }
}

template<class Type_vector>
s21::vector<Type_vector>::~vector() { delete[] mass_; }

template<class Type_vector>
s21::vector<Type_vector> s21::vector<Type_vector>::operator=(vector&& v) {
    if (this != &v) {
        (this->size_ = v.size_, this->capacity_ = v.capacity_);
        free(mass_);
        mass_ = v.mass_;
        v.size_ = v.capacity_ = 0;
        v.mass_ = nullptr;
    }
    return (*this);
}

//    Методы для доступа к элементам класса
template<class Type_vector>
Type_vector& s21::vector<Type_vector>::at(size_type pos) {
    if (pos < 0 || pos >= size_) throw std::out_of_range("index<0 or index>=size of vector");
    return mass_[pos];
}

template<class Type_vector>
Type_vector& s21::vector<Type_vector>::operator[](size_type pos) { return mass_[pos]; }

template<class Type_vector>
const Type_vector& s21::vector<Type_vector>::front() {
    if (size_ == 0) throw std::out_of_range("size==0 of vector");
    return mass_[0];
}

template<class Type_vector>
const Type_vector& s21::vector<Type_vector>::back() {
    if (size_ == 0) throw std::out_of_range("size==0 of vector");
    return mass_[size_ - 1];
}

template<class Type_vector>
Type_vector* s21::vector<Type_vector>::data() { return mass_; }

//    методы для итерирования

template <class Type_vector>
typename s21::vector<Type_vector>::iterator s21::vector<Type_vector>::begin() {
    iterator ret(mass_);
    return mass_;
}

template<class Type_vector>
typename s21::vector<Type_vector>::const_iterator s21::vector<Type_vector>::cbegin() {
    return mass_;
}

template <class Type_vector>
typename s21::vector<Type_vector>::iterator s21::vector<Type_vector>::end() {
    return mass_ + size_;
}

template <class Type_vector>
typename s21::vector<Type_vector>::const_iterator s21::vector<Type_vector>::cend() {
    return mass_ + size_;
}

//    Методы для определения наполнености контейнера
template<class Type_vector>
bool s21::vector<Type_vector>::empty() { return size_ == 0; }

template<class Type_vector>
size_t s21::vector<Type_vector>::size() { return size_; }

template<class Type_vector>
size_t s21::vector<Type_vector>::max_size(){
    return size_;
}

template<class Type_vector>
void s21::vector<Type_vector>::reserve(size_type new_cap) {
    if (capacity_ < new_cap) {
        capacity_ = new_cap;
        Type_vector* copy = (Type_vector*)realloc(mass_,capacity_*sizeof(Type_vector));
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        free(mass_);
        mass_ = copy;
    }
}

template<class Type_vector>
size_t s21::vector<Type_vector>::capacity() { return capacity_; }

template<class Type_vector>
void s21::vector<Type_vector>::shrink_to_fit() {
    if (capacity_ > (size_ + 1)) {
        capacity = size + 1;
        Type_vector* copy = (Type_vector*)realloc(mass_,capacity_*sizeof(Type_vector));
        for (int i = 0; i < size_; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}

//    Методы для изменения контейнера
template<class Type_vector>
void s21::vector<Type_vector>::clear() {
    if (capacity_ != 0) free(mass_);
    size_ = 0;
    capacity_ = 1;
    mass_ = new value_type[capacity_]();
}

template <class Type_vector>
typename s21::vector<Type_vector>::iterator s21::vector<Type_vector>::insert(s21::vector<Type_vector>::iterator pos, const_reference value) {
    iterator i = end();
    if (pos != nullptr) {
        while (i != pos && i != begin()) --i;
        if (i != pos) throw std::out_of_range("Out of range, invalid argument");
        if (capacity_ == size_ + 1) doublingCapacity();
        i = begin();
        for (i = end(); i != pos; --i) {
            *i = *(i - 1);
        }
        *i = value;
        size_++;
    }
    return i;
}

template<class Type_vector>
void s21::vector<Type_vector>::erase(iterator pos) {
    for (auto i = pos; i != end(); i++) {
        *i = *(i + 1);
    }
    --size_;
}

template<class Type_vector>
void s21::vector<Type_vector>::push_back(const_reference value) {
    if (capacity_ == size_ + 1) doublingCapacity();
    mass_[size_] = value;
    size_++;
}

template<class Type_vector>
void s21::vector<Type_vector>::pop_back() {
    if (size_ > 0) size_--;
}

template<class Type_vector>
void s21::vector<Type_vector>::swap(vector& other) {
    iterator val = other.mass_;
    size_type si = other.size_;
    size_type cap = other.capacity_;
    (other.mass_ = this->mass_, other.size_ = this->size_, other.capacity_ = this->capacity_);
    (this->mass_ = val, this->size_ = si, this->capacity_ = cap);
}

template <class Type_vector>
template<class T,class ...Args>
void vector<Type_vector>::emplace_back(T n,Args... args) {
    push_back(n);
    emplace_back(args...);
}

template <class Type_vector>
template<class T,class ...Args>
void vector<Type_vector>::emplace(iterator it,T n,Args... args) {
    insert(it,n);
    emplace(it, args...);
}
}  // namespace s21