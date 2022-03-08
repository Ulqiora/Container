#ifndef SRC_MAP_HPP_
#define SRC_MAP_HPP_

#include <initializer_list>

#include "sorted_container.tpp"

namespace s21 {

template <class Key, class T, class Traits = std::less<Key> >
class map : public SortedContainer<std::pair<const Key, T>, Traits> {
 public:
    // Type definitions
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::pair<const key_type, mapped_type> value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef typename SortedContainer<value_type, Traits>::iterator iterator;
    typedef typename SortedContainer<value_type, Traits>::const_iterator const_iterator;
    typedef size_t size_type;
    // Member Functions
    map();
    map(std::initializer_list<value_type> const& items);
    map(const map& m);
    map(map&& m);
    ~map();
    map<Key, T, Traits>& operator=(const map& m);
    // Element access
    T& at(const Key& key);
    T& operator[](const Key& key);
    // Modifiers
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const Key& key, const T& obj);
    std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
    void merge(map& other);
    // Lookup
    bool contains(const Key& key);
};

}  // namespace s21

#endif  // SRC_MAP_HPP_
