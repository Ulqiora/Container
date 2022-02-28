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
    Tree<Key, Traits> *tree;
    size_type size;

 public:
    // Iterator class
    class iterator {
     private:
        Node<Key>* node;

     public:
        iterator() : node(nullptr){};
        iterator(const iterator& it) : node(it.node){};
        ~iterator(){};
        reference operator*() const;
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const ;
        iterator& operator=(const iterator& rhs);
    };
    // Member functions
    SetContainer();
    SetContainer(const SetContainer& s);
    SetContainer(SetContainer&& s);
    ~SetContainer();
    operator=(SetContainer&& s);
    // Iterators
    iterator begin() const;
    const_iterator cbegin() const;
    iterator end() const;
    const_iterator cend() const;
    // Capacity
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    // Modifiers
    void clear();
    void erase(iterator pos);
    void swap(SetContainer& other);
    void merge(SetContainer& other);
    // Lookup
    iterator find(const Key& key) const;
    bool contains(const Key& key) const;
};

}  // namespace s21

#endif  // SRC_SET_CONTAINER_H_
