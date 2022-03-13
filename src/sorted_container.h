#pragma once

#include <cmath>

#include "tree.h"

namespace s21 {

template <class Key, class Traits>
class SortedContainer {
 public:
    // Type definitions
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    class iterator {
     public:
        Node<Key>* _node;

        iterator();
        explicit iterator(Node<Key>* node);
        iterator(const iterator& it);
        ~iterator();
        iterator& operator=(const iterator& it);
        const_reference operator*();
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
    };
    typedef iterator const_iterator;

 protected:
    Tree<Key, Traits>* _tree;
    size_type _size;

 public:
    // Member functions
    SortedContainer();
    SortedContainer(const SortedContainer& s);
    SortedContainer(SortedContainer&& s);
    ~SortedContainer();
    SortedContainer<Key, Traits>& operator=(const SortedContainer& s);
    SortedContainer<Key, Traits>& operator=(SortedContainer&& s);
    // Iterators
    iterator begin() const;
    const_iterator cbegin() const;
    iterator end() const;
    const_iterator cend() const;
    // Capacity
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    // Modifiers
    void clear();
    void erase(iterator pos);
    void swap(SortedContainer& other);
    // Lookup
    iterator find(const Key& key) const;
    bool contains(const Key& key) const;
};

/*
    #########################
    # METHODS IMPLEMENTATION
    #########################
*/

template <class Key, class Traits>
SortedContainer<Key, Traits>::SortedContainer() : _size(0) {
    _tree = new Tree<Key, Traits>;
}

template <class Key, class Traits>
SortedContainer<Key, Traits>::SortedContainer(const SortedContainer& s) : _size(s._size) {
    _tree = new Tree<Key, Traits>(*s._tree);
}

template <class Key, class Traits>
SortedContainer<Key, Traits>::SortedContainer(SortedContainer&& s) : _tree(s._tree), _size(s._size) {
    s._tree = nullptr;
}

template <class Key, class Traits>
SortedContainer<Key, Traits>& SortedContainer<Key, Traits>::operator=(const SortedContainer& s) {
    if (this != &s) {
        delete _tree;
        _tree = new Tree<Key, Traits>(*s._tree);
        _size = s._size;
    }
    return *this;
}

template <class Key, class Traits>
SortedContainer<Key, Traits>& SortedContainer<Key, Traits>::operator=(SortedContainer&& s) {
    if (this != &s) {
        delete _tree;
        _tree = s._tree;
        s._tree = nullptr;
        _size = s._size;
    } else {
        // STL-like behavior
        clear();
    }
    return *this;
}

template <class Key, class Traits>
SortedContainer<Key, Traits>::~SortedContainer() {
    if (_tree) {
        delete _tree;
        _tree = nullptr;
    }
}

// ITERATOR

template <class Key, class Traits>
SortedContainer<Key, Traits>::iterator::iterator() : _node(nullptr) {}

template <class Key, class Traits>
SortedContainer<Key, Traits>::iterator::iterator(Node<Key>* node) : _node(node) {}

template <class Key, class Traits>
SortedContainer<Key, Traits>::iterator::iterator(const iterator& it) : _node(it._node) {}

template <class Key, class Traits>
SortedContainer<Key, Traits>::iterator::~iterator() {
    _node = nullptr;
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::iterator& SortedContainer<Key, Traits>::iterator::operator=(
    const iterator& it) {
    _node = it._node;
    return *this;
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::const_reference SortedContainer<Key, Traits>::iterator::operator*() {
    if (_node == nullptr) {
        throw std::invalid_argument("Iterator you try to dereference points at nullptr!");
    }
    return _node->key;
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::iterator& SortedContainer<Key, Traits>::iterator::operator++() {
    if (_node == nullptr) {
        throw std::out_of_range("Iterator is out of container bounds!");
    }
    if (_node->rightThread) {
        _node = _node->right;
    } else {
        _node = leftMost(_node->right);
    }
    return *this;
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::iterator& SortedContainer<Key, Traits>::iterator::operator--() {
    if (_node == nullptr) {
        throw std::out_of_range("Iterator is out of container bounds!");
    }
    if (_node->leftThread) {
        _node = _node->left;
    } else {
        _node = rightMost(_node->left);
    }
    return *this;
}

template <class Key, class Traits>
bool SortedContainer<Key, Traits>::iterator::operator==(const iterator& it) const {
    if (_node == it._node) return true;
    return false;
}

template <class Key, class Traits>
bool SortedContainer<Key, Traits>::iterator::operator!=(const iterator& it) const {
    if (_node != it._node) return true;
    return false;
}

// METHODS

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::iterator SortedContainer<Key, Traits>::begin() const {
    return iterator(_tree->begin());
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::const_iterator SortedContainer<Key, Traits>::cbegin() const {
    return const_iterator(_tree->begin());
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::iterator SortedContainer<Key, Traits>::end() const {
    return iterator(_tree->end());
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::const_iterator SortedContainer<Key, Traits>::cend() const {
    return const_iterator(_tree->end());
}

// Capacity

template <class Key, class Traits>
bool SortedContainer<Key, Traits>::empty() const {
    return _tree->empty();
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::size_type SortedContainer<Key, Traits>::size() const {
    return _size;
}

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::size_type SortedContainer<Key, Traits>::max_size() const {
    return static_cast<size_t>(
        pow(2, sizeof(void*) * 8) / (sizeof(Key) + 3 * sizeof(Node<Key>*) + 2 * sizeof(bool)) - 1);
}

// Modifiers

template <class Key, class Traits>
void SortedContainer<Key, Traits>::clear() {
    _tree->clear();
    _size = 0;
}

template <class Key, class Traits>
void SortedContainer<Key, Traits>::erase(iterator pos) {
    _tree->erase(pos._node);
    _size--;
}

template <class Key, class Traits>
void SortedContainer<Key, Traits>::swap(SortedContainer& other) {
    std::swap(_tree, other._tree);
    std::swap(_size, other._size);
}

// Lookup

template <class Key, class Traits>
typename SortedContainer<Key, Traits>::iterator SortedContainer<Key, Traits>::find(const Key& key) const {
    Node<Key>* node = _tree->find(key);
    iterator it;
    if (node) {
        it = iterator(node);
    } else {
        it = end();
    }
    return it;
}

template <class Key, class Traits>
bool SortedContainer<Key, Traits>::contains(const Key& key) const {
    if (_tree->find(key) == nullptr) {
        return false;
    }
    return true;
}

}  // namespace s21
