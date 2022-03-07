#ifndef SRC_SET_CONTAINER_HPP_
#define SRC_SET_CONTAINER_HPP_

#include <cmath>

#include "tree.tpp"

namespace s21 {

template <class Key, class Traits = std::less<Key> >
class SetContainer {
 public:
    // Type definitions
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    class iterator {
     public:
        Node<Key>* _node;

        iterator();
        iterator(Node<Key>* node);
        iterator(const iterator& it);
        ~iterator();
        iterator& operator=(const iterator& it);
        const_reference operator*();
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
    };
    typedef iterator const_iterator;

 protected:
    Tree<Key, Traits>* _tree;
    size_type _size;

 public:
    // Member functions
    SetContainer();
    SetContainer(const SetContainer& s);
    SetContainer(SetContainer&& s);
    ~SetContainer();
    SetContainer<Key, Traits>& operator=(const SetContainer& s);
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
    // Lookup
    iterator find(const Key& key) const;
    bool contains(const Key& key) const;
    void treeDisplay();  // *** DEBUG
};

}  // namespace s21

#endif  // SRC_SET_CONTAINER_HPP_
