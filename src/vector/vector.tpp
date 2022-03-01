#include "vector.hpp"

namespace s21 {
template<class Type_vector>
void s21::vector<Type_vector>::doublingCapacity() {
    capacity_ *= 2;
    Type_vector* copy = new Type_vector[capacity_]();
    for (int i = 0; i < size_; i++) copy[i] = mass_[i];
    delete[] mass_;
    mass_ = copy;
}

template<class Type_vector>
s21::vector<Type_vector>::vector() : capacity_(1), size_(0), mass_(new value_type[capacity_]) {}

template<class Type_vector>
s21::vector<Type_vector>::vector(size_type n) : capacity_(n + 1), size_(n), mass_(new value_type[capacity_]) {}

template<class Type_vector>
s21::vector<Type_vector>::vector(std::initializer_list<value_type> const& items)
    : capacity_(items.size() + 1), size_(items.size()), mass_(new value_type[capacity_]) {
    int j=0;
    for (auto i = items.begin(); i != items.end(); i++) {
        mass_[j] = *i;
        j++;
    }
}

template<class Type_vector>
s21::vector<Type_vector>::vector(const vector& v) {
    if (this != &v) {
        capacity_ = v.capacity_;
        size_ = v.size_;
        mass_ = new Type_vector[capacity_]();
        for (int i = 0; i < size_; i++) mass_[i] = v.mass_[i];
    }
}

template<class Type_vector>
s21::vector<Type_vector>::vector(vector&& v) noexcept {
    if (this != &v) {
        capacity_ = v.capacity_;
        size_ = v.size_;
        mass_ = new Type_vector[capacity_]();
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
        delete[] this->mass_;
        this->mass_ = v.mass_;
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

template<class Type_vector>
Type_vector* s21::vector<Type_vector>::begincbegin() { return mass_; }

template <class Type_vector>
Type_vector* s21::vector<Type_vector>::endcend() {
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
        Type_vector* copy = new Type_vector[capacity_]();
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}

template<class Type_vector>
size_t s21::vector<Type_vector>::capacity() { return capacity_; }

template<class Type_vector>
void s21::vector<Type_vector>::shrink_to_fit() {
    if (capacity_ > (size_ + 1)) {
        capacity = size + 1;
        Type_vector* copy = new Type_vector[capacity_]();
        for (int i = 0; i < size_; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}

//    Методы для изменения контейнера
template<class Type_vector>
void s21::vector<Type_vector>::clear() {
    if (capacity_ != 0) delete[] mass_;
    size_ = 0;
    capacity_ = 1;
    mass_ = new Type_vector[capacity_]();
}

template<class Type_vector>
Type_vector* s21::vector<Type_vector>::insert(iterator pos, const_reference value) {
    if (capacity_ - 1 == size_) doublingCapacity();
    for (auto i = endcend();; --i) {
        *i = *(i - 1);
        if (i != pos) {
            *i = value;
            break;
        }
    }
    size_++;
    return pos;
}

template<class Type_vector>
void s21::vector<Type_vector>::erase(iterator pos) {
    for (auto i = pos; i != endcend(); i++) {
        *i = *(i + 1);
    }
    --size_;
}

template<class Type_vector>
void s21::vector<Type_vector>::push_back(const_reference value) {
    if (capacity_ - 1 == size_) doublingCapacity();
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
}  // namespace s21