template <class Type>
void vector<Type>::doublingCapacity() {
    capacity_ *= 2;
    Type* copy = new Type[capacity_]();
    for (int i = 0; i < size; i++) copy[i] = mass_[i];
    delete[] mass_;
    mass_ = copy;
}
//    Основные методы взаиможействия
template <class Type>
vector<Type>::vector() : capacity_(1), size_(0), mass_(new value_type[capacity_]) {}

template <class Type>
vector<Type>::vector(size_type n) : capacity_(n+1), size_(n), mass_(new value_type[capacity_]) {}

template <class Type>
vector<Type>::vector(std::initializer_list<value_type> const& items) : capacity_(items.size()+1), size_(items.size()), mass_(new value_type[capacity_]) {
    for (auto i = items.begin(), int j = 0; i != items.end(); i++, j++) {
        mass_[j] = i;
    }
}

template <class Type>
vector<Type>::vector(const vector& v) {
    if (this != &v) {
        capacity = v.capacity;
        size = v.size;
        mass_ = new Type[capacity_]();
        for (int i = 0; i < size; i++) mass_[i] = v.mass_[i];
    }
}

template <class Type>
vector<Type>::vector(vector&& v) noexcept {
    if (this != &v) {
        capacity = v.capacity;
        size = v.size;
        mass_ = new Type[capacity_]();
        for (int i = 0; i < size; i++) mass_[i] = v.mass_[i];
        v.mass_ = nullptr;
        v.size = v.capacity = 0;
    }
}

template <class Type>
vector<Type>::~vector() {
    delete[] mass_;
}

template <class Type>
Type& vector<Type>::operator=(vector&& v) {
    if (this != &v) {
        this->size_ = v.size_;
        this->capacity_ = v.capacity_;
        delete[] this->mass_;
        this->mass_ = v.mass_;
        v.size_ = 0;
        v.capacity = 0;
        v.mass_ = nullptr;
    }
    return (*this);
}
//    Методы для доступа к элементам класса
template <class Type>
Type& vector<Type>::at(size_type pos){
    if (pos < 0 || pos >= size_) throw std::out_of_range("index<0 or index>=size of vector");
    return mass_[pos];
}

template <class Type>
Type& vector<Type>::operator[](size_type pos){
    return mass_[pos];
}

template <class Type>
const Type& vector<Type>::front(){
    if (size_ == 0) throw std::out_of_range("size==0 of vector");
    return mass_[0];
}

template <class Type>
const Type& vector<Type>::back(){
    if (size_ == 0) throw std::out_of_range("size==0 of vector");
    return mass_[size_ - 1];
}

template <class Type>
Type* vector<Type>::data(){
    return mass_;
}
//    методы для итерирования
template <class Type>
Type* vector<Type>::begincbegin(){
    return mass_;
}

template <class Type>
Type* vector<Type>::endcend(){
    return mass_[size_];
}
//    Методы для определения наполнености контейнера
template <class Type>
bool vector<Type>::empty(){
    return size == 0;
}

template <class Type>
size_t vector<Type>::size() {
    return size_;
}

template <class Type>
size_t vector<Type>::max_size() {
    
}

template <class Type>
void vector<Type>::reserve(size_type new_cap) {
    if (capacity_ < new_cap) {
        capacity_ = new_cap;
        Type* copy = new Type[capacity_]();
        for (int i = 0; i < size; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}

template <class Type>
size_t vector<Type>::capacity() {
    return capacity_;
}

template <class Type>
void vector<Type>::shrink_to_fit() {
    if (capacity_ > (size_ + 1)) {
        capacity = size + 1;
        Type* copy = new Type[capacity_]();
        for (int i = 0; i < size_; i++) copy[i] = mass_[i];
        delete[] mass_;
        mass_ = copy;
    }
}
//    Методы для изменения контейнера
template <class Type>
void vector<Type>::clear(){
    if(capacity_!=0) delete[] mass_;
    size_=0;
    capacity_=1;
    mass_=new Type[capacity_]();
}

template <class Type>
Type* vector<Type>::insert(iterator pos, const_reference value) {
    if (capacity_-1 == size_) doublingCapacity();
    for (auto i = end();; --i) {
        *i = *(i - 1);
        if (i != it) {
            *i = value;
            break;
        }
    }
    size_++;
}

template <class Type>
void vector<Type>::erase(iterator pos) {
    for (auto i = pos; i != end(); i++) {
        *i = *(i + 1);
    }
    --size;
    return pos;
}

template <class Type>
void vector<Type>::push_back(const_reference value) {
    if (capacity_ - 1 == size_) doublingCapacity();
    mass_[size_] = value;
    size_++;
}

template <class Type>
void vector<Type>::pop_back() {
    if (size_ > 0) size_--;
}

template <class Type>
void vector<Type>::swap(vector& other) {
    iterator val = other.mass_;
    size_type si = other.size_;
    size_type cap = other.capacity_;
    (other.mass_ = this->mass_, other.size_ = this->size_, other.capacity_ = this->capacity_);
    (this->mass_ = val, this->size_ = si, this->capacity_ = cap);
}