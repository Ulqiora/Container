#include "map.hpp"

namespace s21 {

// Constructors, destructor and operator=

template <class Key, class T, class Traits>
map<Key, T, Traits>::map() : SortedContainer<std::pair<const Key, T>, Traits>() {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(std::initializer_list<value_type> const& items)
    : SortedContainer<std::pair<const Key, T>, Traits>() {
    typename std::initializer_list<value_type>::const_iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        insert(*it);
    }
}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(const map& s) : SortedContainer<std::pair<const Key, T>, Traits>(s) {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::map(map&& s) : SortedContainer<std::pair<const Key, T>, Traits>(std::move(s)) {}

template <class Key, class T, class Traits>
map<Key, T, Traits>::~map() {}

template <class Key, class T, class Traits>
map<Key, T, Traits>& map<Key, T, Traits>::operator=(const map& s) {
    SortedContainer<std::pair<const Key, T>, Traits>::operator=(s);
    return *this;
}

}  // namespace s21
