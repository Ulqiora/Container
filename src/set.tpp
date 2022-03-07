#include "set.hpp"

namespace s21 {

// Constructors, destructor and operator=

template <class Key, class Traits>
set<Key, Traits>::set() : SetContainer<Key, Traits>() {}

template <class Key, class Traits>
set<Key, Traits>::set(std::initializer_list<value_type> const& items) : SetContainer<Key, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class Traits>
set<Key, Traits>::set(const set& s) : SetContainer<Key, Traits>(s) {}

template <class Key, class Traits>
set<Key, Traits>::set(set&& s) : SetContainer<Key, Traits>(std::move(s)) {}

template <class Key, class Traits>
set<Key, Traits>::~set() {}

template <class Key, class Traits>
set<Key, Traits>& set<Key, Traits>::operator=(const set& s) {
    SetContainer<Key, Traits>::operator=(s);
    return *this;
}

// Modifiers

template <class Key, class Traits>
std::pair<typename set<Key, Traits>::iterator, bool> set<Key, Traits>::insert(const value_type& value) {
    std::pair<Node<Key>*, bool> p = SetContainer<Key, Traits>::_tree->insert(value, false);
    if (p.second) SetContainer<Key, Traits>::_size++;
    return std::pair<iterator, bool>(iterator(p.first), p.second);
}

template <class Key, class Traits>
void set<Key, Traits>::merge(set& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
        insert(*it);
    }
}

}  // namespace s21
