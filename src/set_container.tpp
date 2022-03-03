#include "set_container.h"

namespace s21 {

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer() {
    _tree = new Tree<Key, Traits>;
    _size = 0;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer(const SetContainer& s) {
    _tree = new Tree<Key, Traits>(*s._tree);
    _size = s._size;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer(SetContainer&& s) : _tree(s._tree), _size(s._size) {
    s._tree = nullptr;
}

template <class Key, class Traits>
SetContainer<Key, Traits>& SetContainer<Key, Traits>::operator=(const SetContainer& s) {
    delete _tree;
    _tree = new Tree<Key, Traits>(*s._tree);
    _size = s._size;
    return *this;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::~SetContainer() {
    delete _tree;
}

// ITERATOR

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator_sc::iterator_sc() : _node(nullptr) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator_sc::iterator_sc(Node<Key>* node) : _node(node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator_sc::iterator_sc(const iterator_sc& it) : _node(it._node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator_sc::~iterator_sc() {
    _node = nullptr;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator_sc& SetContainer<Key, Traits>::iterator_sc::operator=(
    const iterator_sc& it) {
    _node = it._node;
    return *this;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::reference SetContainer<Key, Traits>::iterator_sc::operator*() {
    if (_node == nullptr) {
        throw std::invalid_argument("Iterator you try to dereference points at nullptr!");
    }
    return _node->key;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator_sc& SetContainer<Key, Traits>::iterator_sc::operator++() {
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
typename SetContainer<Key, Traits>::iterator_sc& SetContainer<Key, Traits>::iterator_sc::operator--() {
    if (_node == nullptr) {
        Node<Key>* root = _node;
        while (root->parent != nullptr) root = root->parent;
        _node = rightMost(root);
    }
    if (_node->leftThread) {
        _node = _node->left;
    } else {
        _node = rightMost(_node->left);
    }
    return *this;
}

template <class Key, class Traits>
bool SetContainer<Key, Traits>::iterator_sc::operator==(const iterator_sc& it) const {
    if (_node == it._node) return true;
    return false;
}

template <class Key, class Traits>
bool SetContainer<Key, Traits>::iterator_sc::operator!=(const iterator_sc& it) const {
    if (_node != it._node) return true;
    return false;
}

// CONST ITERATOR

template <class Key, class Traits>
SetContainer<Key, Traits>::const_iterator_sc::const_iterator_sc() : _node(nullptr) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::const_iterator_sc::const_iterator_sc(Node<Key>* node) : _node(node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::const_iterator_sc::const_iterator_sc(const const_iterator_sc& it)
    : _node(it._node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::const_iterator_sc::~const_iterator_sc() {
    _node = nullptr;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_iterator_sc&
SetContainer<Key, Traits>::const_iterator_sc::operator=(const const_iterator_sc& it) {
    _node = it._node;
    return *this;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_reference
SetContainer<Key, Traits>::const_iterator_sc::operator*() {
    if (_node == nullptr) {
        throw std::invalid_argument("Iterator you try to dereference points at nullptr!");
    }
    return _node->key;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_iterator_sc&
SetContainer<Key, Traits>::const_iterator_sc::operator++() {
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
typename SetContainer<Key, Traits>::const_iterator_sc&
SetContainer<Key, Traits>::const_iterator_sc::operator--() {
    if (_node == nullptr) {
        Node<Key>* root = _node;
        while (root->parent != nullptr) root = root->parent;
        _node = rightMost(root);
    }
    if (_node->leftThread) {
        _node = _node->left;
    } else {
        _node = rightMost(_node->left);
    }
    return *this;
}

template <class Key, class Traits>
bool SetContainer<Key, Traits>::const_iterator_sc::operator==(const const_iterator_sc& it) const {
    if (_node == it._node) return true;
    return false;
}

template <class Key, class Traits>
bool SetContainer<Key, Traits>::const_iterator_sc::operator!=(const const_iterator_sc& it) const {
    if (_node != it._node) return true;
    return false;
}

// METHODS

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator_sc SetContainer<Key, Traits>::begin() const {
    return iterator_sc(_tree->begin());
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_iterator_sc SetContainer<Key, Traits>::cbegin() const {
    return const_iterator_sc(_tree->begin());
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator_sc SetContainer<Key, Traits>::end() const {
    return iterator_sc();
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::const_iterator_sc SetContainer<Key, Traits>::cend() const {
    return const_iterator_sc();
}

}  // namespace s21
