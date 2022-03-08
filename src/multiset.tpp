#include "multiset.hpp"

namespace s21 {

// Constructors, destructor and operator=

template <class Key, class Traits>
multiset<Key, Traits>::multiset() : SortedContainer<Key, Traits>() {}

template <class Key, class Traits>
multiset<Key, Traits>::multiset(std::initializer_list<value_type> const& items)
    : SortedContainer<Key, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class Traits>
multiset<Key, Traits>::multiset(const multiset& s) : SortedContainer<Key, Traits>(s) {}

template <class Key, class Traits>
multiset<Key, Traits>::multiset(multiset&& s) : SortedContainer<Key, Traits>(std::move(s)) {}

template <class Key, class Traits>
multiset<Key, Traits>::~multiset() {}

template <class Key, class Traits>
multiset<Key, Traits>& multiset<Key, Traits>::operator=(const multiset& s) {
    SortedContainer<Key, Traits>::operator=(s);
    return *this;
}

// Modifiers

template <class Key, class Traits>
typename multiset<Key, Traits>::iterator multiset<Key, Traits>::insert(const value_type& value) {
    std::pair<Node<Key>*, bool> p = SortedContainer<Key, Traits>::_tree->insert(value, true);
    SortedContainer<Key, Traits>::_size++;
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
    Node<Key>* node = SortedContainer<Key, Traits>::_tree->find(key);
    while (node != nullptr) {
        cnt++;
        if (!node->rightThread) {
            node = SortedContainer<Key, Traits>::_tree->findFrom(key, node->right);
        } else {
            break;
        }
    }
    return cnt;
}

template <class Key, class Traits>
typename multiset<Key, Traits>::iterator multiset<Key, Traits>::lower_bound(const Key& key) {
    iterator it = SortedContainer<Key, Traits>::begin();
    while (it != SortedContainer<Key, Traits>::end() && *it < key) {
        ++it;
    }
    return it;
}

template <class Key, class Traits>
typename multiset<Key, Traits>::iterator multiset<Key, Traits>::upper_bound(const Key& key) {
    iterator it = SortedContainer<Key, Traits>::begin();
    while (it != SortedContainer<Key, Traits>::end() && *it <= key) {
        ++it;
    }
    return it;
}

template <class Key, class Traits>
std::pair<typename multiset<Key, Traits>::iterator, typename multiset<Key, Traits>::iterator>
multiset<Key, Traits>::equal_range(const Key& key) {
    return std::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

}  // namespace s21
