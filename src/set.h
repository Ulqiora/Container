#ifndef SRC_SET_H_
#define SRC_SET_H_

#include "set_container.tpp"

namespace s21 {

template <class Key, class Traits>
class set : public SetContainer {
 public:
    class iterator : public iterator_sc {};
    class const_iterator : public const_iterator_sc {};
    // Member Functions
    set() : SetContainer<Key, Traits>();
    set(std::initializer_list<value_type> const& items);
    set(const set& s) : SetContainer<Key, Traits>(s);
    set(set&& s) : SetContainer<Key, Traits>(s);
    ~set() : ~SetContainer<Key, Traits>();
    operator=(set&& s);
    // Modifiers
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const Key& key, const T& obj);
    std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
    void swap(set& other);
    void merge(set& other);
};

}  // namespace s21

#endif  // SRC_SET_H_
