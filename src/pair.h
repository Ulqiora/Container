#pragma once

#include <utility>

namespace s21 {

template <class T1, class T2>
struct pair : public std::pair<T1, T2> {
    pair();
    pair(const T1& t1, const T2& t2);
    pair(const pair<T1, T2>& other);
    pair(const std::pair<T1, T2>& other);
    pair<T1, T2>& operator=(const pair<T1, T2>& other);
    pair<T1, T2>& operator=(pair<T1, T2>&& other);
    bool operator<(const pair<T1, T2>& other) const;
    bool operator<=(const pair<T1, T2>& other) const;
    bool operator==(const pair<T1, T2>& other) const;
    bool operator!=(const pair<T1, T2>& other) const;
    bool operator>=(const pair<T1, T2>& other) const;
    bool operator>(const pair<T1, T2>& other) const;
};

/*
    #########################
    # METHODS IMPLEMENTATION
    #########################
*/

// INHERITED MEMBER FUNCTIONS

template <class T1, class T2>
pair<T1, T2>::pair() : std::pair<T1, T2>() {}

template <class T1, class T2>
pair<T1, T2>::pair(const T1& t1, const T2& t2) : std::pair<T1, T2>(t1, t2) {}

template <class T1, class T2>
pair<T1, T2>::pair(const pair<T1, T2>& other) : std::pair<T1, T2>(other) {}

template <class T1, class T2>
pair<T1, T2>::pair(const std::pair<T1, T2>& other) : std::pair<T1, T2>(other) {}

template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& other) {
    std::pair<T1, T2>::operator=(other);
    return *this;
}

template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(pair<T1, T2>&& other) {
    std::pair<T1, T2>::operator=(std::move(other));
    return *this;
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
