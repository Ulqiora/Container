#ifndef SRC_SET_HPP_
#define SRC_SET_HPP_

#include <initializer_list>

#include "sorted_container.tpp"

namespace s21 {

template <class Key, class Traits = std::less<Key> >
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
    // Modifiers
    std::pair<iterator, bool> insert(const value_type& value);
    void merge(set& other);
};

}  // namespace s21

#endif  // SRC_SET_HPP_
