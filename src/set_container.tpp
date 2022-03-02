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

/*
template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::iterator() : _node(nullptr) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::iterator(const iterator& it) : _node(it._node) {}

template <class Key, class Traits>
SetContainer<Key, Traits>::iterator::~iterator() {}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::reference SetContainer<Key, Traits>::iterator::operator*() const {
    return _node->key;
}

template <class Key, class Traits>
typename SetContainer<Key, Traits>::iterator& SetContainer<Key, Traits>::iterator::operator++() {

}
*/

}  // namespace s21
