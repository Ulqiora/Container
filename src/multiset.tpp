#include "multiset.hpp"

namespace s21 {

// Constructors, destructor and operator=

template <class Key, class Traits>
multiset<Key, Traits>::multiset() : SetContainer<Key, Traits>() {}

template <class Key, class Traits>
multiset<Key, Traits>::multiset(std::initializer_list<value_type> const& items)
    : SetContainer<Key, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class Traits>
multiset<Key, Traits>::multiset(const multiset& s) : SetContainer<Key, Traits>(s) {}

template <class Key, class Traits>
multiset<Key, Traits>::multiset(multiset&& s) : SetContainer<Key, Traits>(std::move(s)) {}

template <class Key, class Traits>
multiset<Key, Traits>::~multiset() {}

template <class Key, class Traits>
multiset<Key, Traits>& multiset<Key, Traits>::operator=(const multiset& s) {
    SetContainer<Key, Traits>::operator=(s);
    return *this;
}

// Modifiers

template <class Key, class Traits>
typename multiset<Key, Traits>::iterator multiset<Key, Traits>::insert(const value_type& value) {
    std::pair<Node<Key>*, bool> p = SetContainer<Key, Traits>::_tree->insert(value, true);
    SetContainer<Key, Traits>::_size++;
    return iterator(p.first);
}

template <class Key, class Traits>
void multiset<Key, Traits>::merge(multiset& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
        insert(*it);
    }
}

// Lookup

template <class Key, class Traits>
typename multiset<Key, Traits>::size_type multiset<Key, Traits>::count(const Key& key) {
    size_type cnt = 0;
    Node<Key>* node = SetContainer<Key, Traits>::_tree->find(key);
    while (node != nullptr) {
        cnt++;
        if (!node->rightThread) {
            node = SetContainer<Key, Traits>::_tree->findFrom(key, node->right);
        } else {
            break;
        }
    }
    return cnt;
}

}  // namespace s21
