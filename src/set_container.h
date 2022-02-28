#ifndef SRC_SET_CONTAINER_H_
#define SRC_SET_CONTAINER_H_

#include "tree.h"

namespace s21 {

template <class Key, class Traits>
class SetContainer {
    // Type definitions
    typedef Key key_type;
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef size_t size_type;

 private:
    Tree<Key, Traits> tree;
    size_type size;

 public:
    // Iterator class
    class iterator {
     private:
        Node<Key> *node;
     public:
        
    }
    // Member functions
    SetContainer();
    SetContainer(const SetContainer& s);
    SetContainer(SetContainer&& s);
    ~SetContainer();
    operator=(SetContainer&& s);
    // Iterators
    iterator begin();
    const_iterator cbegin();
    iterator end();
    const_iterator cend();
    // Capacity
    bool empty();
    size_type size();
    size_type max_size();
    // Modifiers
    void clear();
    void erase(iterator pos);
    void swap(SetContainer& other);
    void merge(SetContainer& other);
    // Lookup
    iterator find(const Key& key);
    bool contains(const Key& key);
};

}  // namespace s21

#endif  // SRC_SET_CONTAINER_H_
