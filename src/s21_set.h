#pragma once

#include <initializer_list>
#include <vector>

#include "sorted_container.h"

namespace s21 {

template <class Key, class Traits = std::less<Key>>
class set : public SortedContainer<Key, Traits> {
 public:
    // Type definitions
    typedef Key key_type;
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef typename SortedContainer<Key, Traits>::iterator iterator;
    typedef typename SortedContainer<Key, Traits>::const_iterator const_iterator;
    typedef size_t size_type;
    // Member Functions
    set();
    set(std::initializer_list<value_type> const& items);
    set(const set& s);
    set(set&& s);
    ~set();
    set<Key, Traits>& operator=(const set& s);
    set<Key, Traits>& operator=(set&& s);
    // Modifiers
    std::pair<iterator, bool> insert(const value_type& value);
    void merge(const set& other);
    template <class... Args>
    std::vector<std::pair<iterator, bool>> emplace(Args&&... args);
};

/*
    #########################
    # METHODS IMPLEMENTATION
    #########################
*/

// Constructors, destructor and operator=

template <class Key, class Traits>
set<Key, Traits>::set() : SortedContainer<Key, Traits>() {}

template <class Key, class Traits>
set<Key, Traits>::set(std::initializer_list<value_type> const& items) : SortedContainer<Key, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class Traits>
set<Key, Traits>::set(const set& s) : SortedContainer<Key, Traits>(s) {}

template <class Key, class Traits>
set<Key, Traits>::set(set&& s) : SortedContainer<Key, Traits>(std::move(s)) {}

template <class Key, class Traits>
set<Key, Traits>::~set() {}

template <class Key, class Traits>
set<Key, Traits>& set<Key, Traits>::operator=(const set& s) {
    SortedContainer<Key, Traits>::operator=(s);
    return *this;
}

template <class Key, class Traits>
set<Key, Traits>& set<Key, Traits>::operator=(set&& s) {
    SortedContainer<Key, Traits>::operator=(std::move(s));
    return *this;
}

// Modifiers

template <class Key, class Traits>
std::pair<typename set<Key, Traits>::iterator, bool> set<Key, Traits>::insert(const value_type& value) {
    std::pair<Node<Key>*, bool> p = SortedContainer<Key, Traits>::_tree->insert(value, false);
    if (p.second) SortedContainer<Key, Traits>::_size++;
    return std::pair<iterator, bool>(iterator(p.first), p.second);
}

template <class Key, class Traits>
void set<Key, Traits>::merge(const set& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class Traits>
template <class... Args>
std::vector<std::pair<typename set<Key, Traits>::iterator, bool>> set<Key, Traits>::emplace(Args&&... args) {
    std::vector<std::pair<iterator, bool>> out;
    std::vector<value_type> in = {args...};
    for (size_type i = 0; i < in.size(); i++) {
        out.push_back(insert(in[i]));
    }
    return out;
}

}  // namespace s21
