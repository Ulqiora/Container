#ifndef SRC_SET_HPP_
#define SRC_SET_HPP_

#include <initializer_list>

#include "set_container.tpp"

namespace s21 {

template <class Key, class Traits>
class multiset : public SetContainer<Key, Traits> {
 public:
    // Type definitions
    typedef Key key_type;
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef typename SetContainer<Key, Traits>::iterator_sc iterator;
    typedef typename SetContainer<Key, Traits>::const_iterator_sc const_iterator;
    typedef size_t size_type;
    // Member Functions
    multiset();
    multiset(std::initializer_list<value_type> const& items);
    multiset(const multiset& s);
    multiset(multiset&& s);
    ~multiset();
    multiset<Key, Traits>& operator=(const multiset& s);
    // Modifiers
    iterator insert(const value_type& value);
    void merge(multiset& other);
    // Lookup
    
};

}  // namespace s21

#endif  // SRC_SET_HPP_
