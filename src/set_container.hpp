#ifndef SRC_SET_CONTAINER_HPP_
#define SRC_SET_CONTAINER_HPP_

#include "tree.tpp"

namespace s21 {

template <class Key, class Traits>
class SetContainer {
 public:
    // Type definitions
    typedef Key key_type;
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    // typedef value_type* iterator_sc;
    // typedef const value_type* const_iterator_sc;
    typedef size_t size_type;

 public:  // *** should be protected
    Tree<Key, Traits>* _tree;
    size_type _size;

 public:
    class iterator_sc {
     public:
        Node<Key>* _node;

        iterator_sc();
        iterator_sc(Node<Key>* node);
        iterator_sc(const iterator_sc& it);
        ~iterator_sc();
        iterator_sc& operator=(const iterator_sc& it);
        reference operator*();
        iterator_sc& operator++();
        iterator_sc& operator--();
        bool operator==(const iterator_sc& it) const;
        bool operator!=(const iterator_sc& it) const;
    };
    class const_iterator_sc {  // *** NEED INHERITANCE!
     public:
        Node<Key>* _node;

        const_iterator_sc();
        const_iterator_sc(Node<Key>* node);
        const_iterator_sc(const const_iterator_sc& it);
        ~const_iterator_sc();
        const_iterator_sc& operator=(const const_iterator_sc& it);
        const_reference operator*();
        const_iterator_sc& operator++();
        const_iterator_sc& operator--();
        bool operator==(const const_iterator_sc& it) const;
        bool operator!=(const const_iterator_sc& it) const;
    };
    // Member functions
    SetContainer();
    SetContainer(const SetContainer& s);
    SetContainer(SetContainer&& s);
    ~SetContainer();
    SetContainer<Key, Traits>& operator=(const SetContainer& s);
    // Iterators
    iterator_sc begin() const;
    const_iterator_sc cbegin() const;
    iterator_sc end() const;
    const_iterator_sc cend() const;
    // Capacity
    bool empty() const;
    size_type size() const;
    size_type max_size() const;  // *** ???
    // Modifiers
    void clear();
    void erase(iterator_sc pos);
    void swap(SetContainer& other);
    // Lookup
    iterator_sc find(const Key& key) const;
    bool contains(const Key& key) const;
};

}  // namespace s21

#endif  // SRC_SET_CONTAINER_HPP_
