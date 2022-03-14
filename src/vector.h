#pragma once

#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <stdexcept>

namespace s21 {
template <class Type_vector>
class vector {
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
    vector(vector&& v);
    ~vector();
    vector operator=(vector&& v);

    //    Методы для доступа к элементам класса
    reference at(size_type pos);
    reference operator[](size_type pos);
    const_reference front();
    const_reference back();
    Type_vector* data();

    //    методы для итерирования
    iterator begin();
    iterator end();
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

    void emplace_back() {}
    template <class T, class... Args>
    void emplace_back(T n, Args... args);

    void emplace(iterator it) {}
    template <class T, class... Args>
    void emplace(iterator it, T n, Args... args);

 private:
    size_type size_;
    size_type capacity_;
    Type_vector* mass_;

    inline void deleteMass();
    inline void reallocMass();
};

// METHODS IMPLEMENTATION

template <class Type_vector>
inline void s21::vector<Type_vector>::deleteMass() {
    if (mass_) {
        delete[] mass_;
        mass_ = nullptr;
    }
}

template <class Type_vector>
inline void s21::vector<Type_vector>::reallocMass() {
    if (capacity_) {
        Type_vector* temp = new Type_vector[capacity_]();
        std::move(mass_, mass_ + size_, temp);
        deleteMass();
        std::swap(mass_, temp);
    } else {
        deleteMass();
    }
}

template <class Type_vector>
s21::vector<Type_vector>::vector() : capacity_(0), size_(0), mass_(nullptr) {}

template <class Type_vector>
s21::vector<Type_vector>::vector(size_type n) : capacity_(n), size_(n) {
    mass_ = new Type_vector[capacity_]();
}

template <class Type_vector>
s21::vector<Type_vector>::vector(std::initializer_list<value_type> const& items)
    : capacity_(items.size()), size_(items.size()) {
    mass_ = new Type_vector[capacity_]();
    int j = 0;
    for (auto i = items.begin(); i != items.end(); ++i, ++j) {
        mass_[j] = *i;
    }
}

template <class Type_vector>
s21::vector<Type_vector>::vector(const vector& v) : capacity_(v.capacity_), size_(v.size_) {
    mass_ = new Type_vector[capacity_]();
    std::copy(v.mass_, v.mass_ + v.size_, mass_);
}

template <class Type_vector>
s21::vector<Type_vector>::vector(vector&& v) : capacity_(v.capacity_), size_(v.size_) {
    mass_ = nullptr;
    std::swap(mass_, v.mass_);
}

template <class Type_vector>
s21::vector<Type_vector>::~vector() {
    deleteMass();
}

template <class Type_vector>
s21::vector<Type_vector> s21::vector<Type_vector>::operator=(vector&& v) {
    if (this != &v) {
        deleteMass();
        capacity_ = v.capacity_;
        size_ = v.size_;
        mass_ = nullptr;
        std::swap(mass_, v.mass_);
    }
    return *this;
}

//    Методы для доступа к элементам класса
template <class Type_vector>
Type_vector& s21::vector<Type_vector>::at(size_type pos) {
    if (pos >= size_) throw std::out_of_range("index is out of container bounds!");
    return mass_[pos];
}

template <class Type_vector>
Type_vector& s21::vector<Type_vector>::operator[](size_type pos) {
    return mass_[pos];
}

template <class Type_vector>
const Type_vector& s21::vector<Type_vector>::front() {
    if (size_ == 0) throw std::out_of_range("vector has zero elements!");
    return mass_[0];
}

template <class Type_vector>
const Type_vector& s21::vector<Type_vector>::back() {
    if (size_ == 0) throw std::out_of_range("vector has zero elements!");
    return mass_[size_ - 1];
}

template <class Type_vector>
Type_vector* s21::vector<Type_vector>::data() {
    return mass_;
}

//    методы для итерирования

template <class Type_vector>
typename s21::vector<Type_vector>::iterator s21::vector<Type_vector>::begin() {
    return mass_;
}

template <class Type_vector>
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
template <class Type_vector>
bool s21::vector<Type_vector>::empty() {
    return size_ == 0;
}

template <class Type_vector>
size_t s21::vector<Type_vector>::size() {
    return size_;
}

template <class Type_vector>
size_t s21::vector<Type_vector>::max_size() {
    return static_cast<size_type>(pow(2, sizeof(void*) * 8) / sizeof(Type_vector) - 1);
}

template <class Type_vector>
void s21::vector<Type_vector>::reserve(size_type new_cap) {
    if (capacity_ < new_cap) {
        capacity_ = new_cap;
        reallocMass();
    }
}

template <class Type_vector>
size_t s21::vector<Type_vector>::capacity() {
    return capacity_;
}

template <class Type_vector>
void s21::vector<Type_vector>::shrink_to_fit() {
    if (capacity_ > size_) {
        capacity_ = size_;
        reallocMass();
    }
}

//    Методы для изменения контейнера
template <class Type_vector>
void s21::vector<Type_vector>::clear() {
    deleteMass();
    size_ = 0;
    capacity_ = 0;
}

template <class Type_vector>
typename s21::vector<Type_vector>::iterator s21::vector<Type_vector>::insert(iterator pos,
                                                                             const_reference value) {
    if (capacity_ <= size_) {
        size_type delta = pos - mass_;
        ++capacity_;
        reallocMass();
        pos = mass_ + delta;
    }
    iterator ret = mass_;
    if (size_) {
        std::move_backward(pos, mass_ + size_, mass_ + size_ + 1);
        *pos = value;
        ret = pos;
    } else {
        *mass_ = value;
    }
    ++size_;
    return ret;
}

template <class Type_vector>
void s21::vector<Type_vector>::erase(iterator pos) {
    if (size_) {
        std::move(pos + 1, mass_ + size_, pos);
        --size_;
    }
}

template <class Type_vector>
void s21::vector<Type_vector>::push_back(const_reference value) {
    insert(mass_ + size_, value);
}

template <class Type_vector>
void s21::vector<Type_vector>::pop_back() {
    if (size_) --size_;
}

template <class Type_vector>
void s21::vector<Type_vector>::swap(vector& other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(mass_, other.mass_);
}

template <class Type_vector>
template <class T, class... Args>
void vector<Type_vector>::emplace_back(T n, Args... args) {
    push_back(n);
    emplace_back(args...);
}

template <class Type_vector>
template <class T, class... Args>
void vector<Type_vector>::emplace(iterator it, T n, Args... args) {
    it = insert(it, n);
    emplace(it, args...);
}

}  // namespace s21
