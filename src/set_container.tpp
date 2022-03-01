#include "set_container.h"

namespace s21 {

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer() {
    _tree = new Tree<Key, Traits>;
    _size = 0;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::SetContainer(const SetContainer& s) {
    _tree = new Tree<Key, Traits>(s._tree);
    _size = s._size;
}

template <class Key, class Traits>
SetContainer<Key, Traits>::~SetContainer() {
    _tree->~Tree<Key, Traits>();
}

}  // namespace s21
