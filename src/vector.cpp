#include "s21_container.hpp"

template <typename Type>
void s21_vector<Type>::doublingCapacity() {
    capacity *= 2;
    Type* copy = new Type[capacity]();
    for (int i = 0; i < size; i++) copy[i] = mass_[i];
    delete[] mass_;
    mass_ = copy;
}
//    Конструкторы
template <typename Type>
s21_vector<Type>::s21_vector() : capacity_(1), size_(0), mass_(new Type[capacity]()) {}

template <typename Type>
s21_vector<Type>::s21_vector(s21_vector& other) {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        mass_ = new Type[capacity]();
        for (int i = 0; i < size; i++) mass_[i] = other.mass_[i];
    }
}

template <typename Type>
s21_vector<Type>::s21_vector(s21_vector&& other) noexcept {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        mass_ = new Type[capacity]();
        for (int i = 0; i < size; i++) mass_[i] = other.mass_[i];
        other.mass_ = nullptr;
        other.size = other.capacity = 0;
    }
}
//    Деструктор
template <typename Type>
s21_vector<Type>::~s21_vector() {
    delete[] mass_;
}
//    Операторы
template <typename Type>
s21_vector<Type>& s21_vector<Type>::operator=(const s21_vector<Type>& other) {
    if (this != &other) {
        capacity = other.capacity;
        size = other.size;
        mass_ = new Type[capacity]();
        for (int i = 0; i < size; i++) mass_[i] = other.mass_[i];
    }
    return (*this);
}

template <typename Type>
bool s21_vector<Type>::operator==(const s21_vector& other) {
    bool res = true;
    if (size == other.size) {
        for (int i = 0; i < size && res == true; ++i) {
            if (fabs(mass_[i] - other.mass_[i]) >= 1e-6) res = false;
        }
    } else {
        res = false;
    }
    return res;
}
//    Доступ к элементам
template <typename Type>
Type& s21_vector<Type>::at(size_t i) {
    if (i < 0 || i >= size) throw std::out_of_range("index<0 or index>=size of vector");
    return mass_[i];
}

template <typename Type>
Type& s21_vector<Type>::operator[](size_t i) {
    return mass_[i];
}

template <typename Type>
Type& s21_vector<Type>::front() {
    if (size == 0) throw std::out_of_range("size==0 of vector");
    return mass_[0];
}
template <typename Type>
Type& s21_vector<Type>::back() {
    if (size == 0) throw std::out_of_range("size==0 of vector");
    return mass_[size - 1];
}
//    Итераторы

//    Работа с размером вектора
template <typename Type>
inline bool s21_vector<Type>::is_empty() const {
    return size == 0;
}

template <typename Type>
inline int s21_vector<Type>::size() const {
    return size;
}

template <typename Type>
void s21_vector<Type>::reserve(int new_cap) {
    if (capacity < new_cap) {
        capacity = new_cap;
        Type* copy = new Type[capacity]();
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}

template <typename Type>
inline int s21_vector<Type>::capacity() const {
    return capacity;
}

template <typename Type>
void s21_vector<Type>::shrink_to_rit() {
    if (capacity > (size + 1)) {
        capacity = size + 1;
        Type* copy = new Type[capacity]();
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}
//    Модификаторы
template <typename Type>
void s21_vector<Type>::clear() {
    if (size > 0) {
        delete[] mass_;
        size = 0;
        capacity = 1;
        mass_ = new Type[capacity]();
    }
}

template <typename Type>
void s21_vector<Type>::push_back(const Type& value){
    if (size >= capacity) doublingCapacity();
    mass_[size] = value;
    size++;
}
template <typename Type>
void s21_vector<Type>::push_back(Type&& value){
    if (size >= capacity) doublingCapacity();
    mass_[size] = value;
    size++;
}

template <typename Type>
void s21_vector<Type>::pop_back(){
    if (size > 0) size--;
}

template <typename Type>
void s21_vector<Type>::resize( int count ){
    if (size >= count) {
        size = count;
    } else {
        if(count>capacity){
            Type* copy=new Type[count]();
            capacity = count;
            for (int i = 0; i < size; i++) copy[i] = mass_[i];
            delete[] mass_;
            mass_=copy;
        }
        size=count;
    }
}

template <typename Type>
void s21_vector<Type>::resize(int count, const Type& value) {
    if (size >= count) {
        size = count;
    } else {
        if(count>capacity){
            Type* copy=new Type[count](value);
            capacity = count;
            for (int i = 0; i < size; i++) copy[i] = mass_[i];
            delete[] mass_;
            mass_=copy;
        }
        size=count;
    }
}

template <typename Type>
void s21_vector<Type>::swap(s21_vector& other){
    s21_vector* var=&other;
    s21_vector* copy=this;
    this=&other;
    var=copy;
}
//    Другие методы