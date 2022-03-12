#include "map.h"

namespace s21 {

// Constructors, destructor and operator=

template <class Key, class T, class Traits>
map<Key, T, Traits>::map() : SortedContainer<s21_value_type, Traits>() {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(std::initializer_list<value_type> const& items)
    : SortedContainer<s21_value_type, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(const map& s) : SortedContainer<s21_value_type, Traits>(s) {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(map&& s) : SortedContainer<s21_value_type, Traits>(std::move(s)) {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::~map() {}

template <class Key, class T, class Traits>
map<Key, T, Traits>& map<Key, T, Traits>::operator=(const map& s) {
    SortedContainer<s21_value_type, Traits>::operator=(s);
    return *this;
}

template <class Key, class T, class Traits>
map<Key, T, Traits>& map<Key, T, Traits>::operator=(map&& s) {
    SortedContainer<s21_value_type, Traits>::operator=(std::move(s));
    return *this;
}

// Element access

template <class Key, class T, class Traits>
T& map<Key, T, Traits>::at(const Key& key) {
    s21_value_type p(key, T());
    Node<s21_value_type>* node = SortedContainer<s21_value_type, Traits>::_tree->find(p);
    if (!node) {
        throw std::out_of_range("There is no such element in map!");
    }
    return node->key.second;
}

template <class Key, class T, class Traits>
T& map<Key, T, Traits>::operator[](const Key& key) {
    s21_value_type p(key, T());
    std::pair<iterator, bool> ret = insert(p);
    return ret.first._node->key.second;
}

// Modifiers

template <class Key, class T, class Traits>
std::pair<typename map<Key, T, Traits>::iterator, bool> map<Key, T, Traits>::insert(
    const value_type& value) {
    s21_value_type s21_val = value;
    std::pair<Node<s21_value_type>*, bool> p =
        SortedContainer<s21_value_type, Traits>::_tree->insert(s21_val, false);
    if (p.second) SortedContainer<s21_value_type, Traits>::_size++;
    return std::pair<iterator, bool>(iterator(p.first), p.second);
}

template <class Key, class T, class Traits>
std::pair<typename map<Key, T, Traits>::iterator, bool> map<Key, T, Traits>::insert(const Key& key,
                                                                                    const T& obj) {
    value_type value(key, obj);
    return insert(value);
}

template <class Key, class T, class Traits>
std::pair<typename map<Key, T, Traits>::iterator, bool> map<Key, T, Traits>::insert_or_assign(const Key& key,
                                                                                              const T& obj) {
    std::pair<iterator, bool> p = insert(key, obj);
    if (!p.second) {
        p.first._node->key.second = obj;
    }
    return p;
}

template <class Key, class T, class Traits>
void map<Key, T, Traits>::merge(const map& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
        insert(*it);
    }
}

// Lookup

template <class Key, class T, class Traits>
bool map<Key, T, Traits>::contains(const Key& key) {
    value_type p(key, T());
    Node<s21_value_type>* node = SortedContainer<s21_value_type, Traits>::_tree->find(p);
    if (!node) {
        return false;
    }
    return true;
}

}  // namespace s21
