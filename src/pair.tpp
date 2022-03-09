#include "pair.hpp"

namespace s21 {

// INHERITED MEMBER FUNCTIONS

template <class T1, class T2>
pair<T1, T2>::pair() : std::pair<T1, T2>() {}

template <class T1, class T2>
pair<T1, T2>::pair(T1 t1, T2 t2) : std::pair<T1, T2>(t1, t2) {}

template <class T1, class T2>
pair<T1, T2>::pair(const pair<T1, T2>& other) : std::pair<T1, T2>(other) {}

template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& other) {
    return std::pair<T1, T2>::operator=(other);
}

template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(pair<T1, T2>&& other) {
    return std::pair<T1, T2>::operator=(std::move(other));
}

// OVERLOADED COMPARISON OPERATORS

template <class T1, class T2>
bool pair<T1, T2>::operator<(const pair<T1, T2>& other) const {
    return std::pair<T1, T2>::first < other.first;
}

template <class T1, class T2>
bool pair<T1, T2>::operator<=(const pair<T1, T2>& other) const {
    return std::pair<T1, T2>::first <= other.first;
}

template <class T1, class T2>
bool pair<T1, T2>::operator==(const pair<T1, T2>& other) const {
    return std::pair<T1, T2>::first == other.first;
}

template <class T1, class T2>
bool pair<T1, T2>::operator!=(const pair<T1, T2>& other) const {
    return std::pair<T1, T2>::first != other.first;
}

template <class T1, class T2>
bool pair<T1, T2>::operator>=(const pair<T1, T2>& other) const {
    return std::pair<T1, T2>::first >= other.first;
}

template <class T1, class T2>
bool pair<T1, T2>::operator>(const pair<T1, T2>& other) const {
    return std::pair<T1, T2>::first > other.first;
}

}  // namespace s21
