#include "set_container.h"

using namespace s21;

template<class Key, class Traits>
SetContainer<Key, Traits>::SetContainer() {
    tree = new Tree<Key, Traits>;
    size = 0;
}

// template<class Key, class Traits>
// SetContainer<Key, Traits>::SetContainer(const SetContainer& s) {
    
// }

