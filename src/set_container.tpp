#include "set_container.hpp"

namespace s21 {

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer() : _size(0) {
    _tree = new Tree<Key, Traits>;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer(const SetContainer& s) : _size(s._size) {
    _tree = new Tree<Key, Traits>(*s._tree);
}

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer(SetContainer&& s) : _tree(s._tree), _size(s._size) {
    s._tree = nullptr;
}

template <class Key, class Traits>
SetContainer<Key, Traits>& SetContainer<Key, Traits>::operator=(const SetContainer& s) {
    if (this != &s) {
        delete _tree;
        _tree = new Tree<Key, Traits>(*s._tree);
        _size = s._size;
    }
    return *this;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::~SetContainer() {
    if (_tree) {
        delete _tree;
        _tree = nullptr;
    }
}

// ITERATOR

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::iterator() : _node(nullptr) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::iterator(Node<Key>* node) : _node(node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::iterator(const iterator& it) : _node(it._node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::~iterator() {
    _node = nullptr;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator& SetContainer<Key, Traits>::iterator::operator=(
    const iterator& it) {
    _node = it._node;
    return *this;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_reference SetContainer<Key, Traits>::iterator::operator*() {
    if (_node == nullptr) {
        throw std::invalid_argument("Iterator you try to dereference points at nullptr!");
    }
    return _node->key;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator& SetContainer<Key, Traits>::iterator::operator++() {
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
typename SetContainer<Key, Traits>::iterator& SetContainer<Key, Traits>::iterator::operator--() {
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
bool SetContainer<Key, Traits>::iterator::operator==(const iterator& it) const {
    if (_node == it._node) return true;
    return false;
}

template <class Key, class Traits>
bool SetContainer<Key, Traits>::iterator::operator!=(const iterator& it) const {
    if (_node != it._node) return true;
    return false;
}

// METHODS

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator SetContainer<Key, Traits>::begin() const {
    return iterator(_tree->begin());
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_iterator SetContainer<Key, Traits>::cbegin() const {
    return const_iterator(_tree->begin());
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator SetContainer<Key, Traits>::end() const {
    return iterator(_tree->end());
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_iterator SetContainer<Key, Traits>::cend() const {
    return const_iterator(_tree->end());
}

// Capacity

template <class Key, class Traits>
bool SetContainer<Key, Traits>::empty() const {
    return _tree->empty();
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::size_type SetContainer<Key, Traits>::size() const {
    return _size;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::size_type SetContainer<Key, Traits>::max_size() const {
    return static_cast<size_t>(
        pow(2, sizeof(void*) * 8) / (sizeof(Key) + 3 * sizeof(Node<Key>*) + 2 * sizeof(bool)) - 1);
}

// Modifiers

template <class Key, class Traits>
void SetContainer<Key, Traits>::clear() {
    _tree->clear();
    _size = 0;
}

template <class Key, class Traits>
void SetContainer<Key, Traits>::erase(iterator pos) {
    _tree->erase(pos._node);
    _size--;
}

template <class Key, class Traits>
void SetContainer<Key, Traits>::swap(SetContainer& other) {
    SetContainer<Key, Traits> buf = *this;
    *this = other;
    other = buf;
}

// Lookup

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator SetContainer<Key, Traits>::find(const Key& key) const {
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
bool SetContainer<Key, Traits>::contains(const Key& key) const {
    if (_tree->find(key) == nullptr) {
        return false;
    }
    return true;
}

// *** DEBUG
template <class Key, class Traits>
void SetContainer<Key, Traits>::treeDisplay() {
    _tree->display();
}

}  // namespace s21
