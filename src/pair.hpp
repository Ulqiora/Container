#ifndef SRC_PAIR_HPP_
#define SRC_PAIR_HPP_

#include <utility>

namespace s21 {

template <class T1, class T2>
struct pair : public std::pair<T1, T2> {
    pair();
    pair(T1 t1, T2 t2);
    pair(const pair<T1, T2>& other);
    pair<T1, T2>& operator=(const pair<T1, T2>& other);
    pair<T1, T2>& operator=(pair<T1, T2>&& other);
    bool operator<(const pair<T1, T2>& other) const;
    bool operator<=(const pair<T1, T2>& other) const;
    bool operator==(const pair<T1, T2>& other) const;
    bool operator!=(const pair<T1, T2>& other) const;
    bool operator>=(const pair<T1, T2>& other) const;
    bool operator>(const pair<T1, T2>& other) const;
};

}  // namespace s21

#endif  // SRC_PAIR_HPP_
