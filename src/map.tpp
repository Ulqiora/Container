#include "map.hpp"

namespace s21 {

// Constructors, destructor and operator=

template <class Key, class T, class Traits>
map<Key, T, Traits>::map() : SortedContainer<value_type, Traits>() {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(std::initializer_list<value_type> const& items)
    : SortedContainer<value_type, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(const map& s) : SortedContainer<value_type, Traits>(s) {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(map&& s) : SortedContainer<value_type, Traits>(std::move(s)) {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::~map() {}

template <class Key, class T, class Traits>
map<Key, T, Traits>& map<Key, T, Traits>::operator=(const map& s) {
    SortedContainer<value_type, Traits>::operator=(s);
    return *this;
}

// Element access
/*
template <class Key, class T, class Traits>
T& map<Key, T, Traits>::at(const Key& key) {}

template <class Key, class T, class Traits>
T& map<Key, T, Traits>::operator[](const Key& key) {}
*/
// Modifiers

template <class Key, class T, class Traits>
std::pair<typename map<Key, T, Traits>::iterator, bool> map<Key, T, Traits>::insert(
    const value_type& value) {
    std::pair<Node<value_type>*, bool> p =
        SortedContainer<value_type, Traits>::_tree->insertPair(value, false);
    if (p.second) SortedContainer<value_type, Traits>::_size++;
    return std::pair<iterator, bool>(iterator(p.first), p.second);
}

template <class Key, class T, class Traits>
std::pair<typename map<Key, T, Traits>::iterator, bool> map<Key, T, Traits>::insert(const Key& key,
                                                                                    const T& obj) {
    std::pair<Key, T> value(key, obj);
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

/*
template <class Key, class T, class Traits>
void map<Key, T, Traits>::merge(map& other) {}
*/
// Lookup

template <class Key, class T, class Traits>
bool map<Key, T, Traits>::contains(const Key& key) {
    std::pair<Key, T> p;
    p.first = key;
    return SortedContainer<value_type, Traits>::_tree->containsPair(p);
}

}  // namespace s21
