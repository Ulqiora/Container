#ifndef SRC_SET_HPP_
#define SRC_SET_HPP_

#include <initializer_list>

#include "sorted_container.tpp"

namespace s21 {

template <class Key, class Traits = std::less<Key> >
class multiset : public SortedContainer<Key, Traits> {
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
    multiset();
    multiset(std::initializer_list<value_type> const& items);
    multiset(const multiset& s);
    multiset(multiset&& s);
    ~multiset();
    multiset<Key, Traits>& operator=(const multiset& s);
    multiset<Key, Traits>& operator=(multiset&& s);
    // Modifiers
    iterator insert(const value_type& value);
    void merge(multiset& other);
    // Lookup
    size_type count(const Key& key);
    iterator lower_bound(const Key& key);
    iterator upper_bound(const Key& key);
    std::pair<iterator, iterator> equal_range(const Key& key);
};

}  // namespace s21

#endif  // SRC_SET_HPP_
