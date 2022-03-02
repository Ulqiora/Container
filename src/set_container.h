#ifndef SRC_SET_CONTAINER_H_
#define SRC_SET_CONTAINER_H_

#include "tree.tpp"

namespace s21 {

template <class Key, class Traits>
class SetContainer {
    // Type definitions
    typedef Key key_type;
    typedef Key value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    // typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef size_t size_type;

 public:    // *** should be protected
    Tree<Key, Traits> *_tree;
    size_type _size;

 public:
    // Iterator class
    class iterator_sc {
     private:
        Node<Key>* _node;

     public:
        iterator_sc();
        iterator_sc(const iterator_sc& it);
        ~iterator_sc();
        reference operator*() const;
        iterator_sc& operator++();
        iterator_sc& operator--();
        bool operator==(const iterator_sc& rhs) const;
        bool operator!=(const iterator_sc& rhs) const ;
        iterator_sc& operator=(const iterator_sc& rhs);
    };
    // Member functions
    SetContainer();
    SetContainer(const SetContainer& s);
    SetContainer(SetContainer&& s);
    ~SetContainer();
    SetContainer<Key, Traits>& operator=(const SetContainer& s);
    // Iterators
    iterator_sc begin() const;
    const iterator_sc cbegin() const;
    iterator_sc end() const;
    const iterator_sc cend() const;
    // Capacity
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    // Modifiers
    void clear();
    void erase(iterator_sc pos);
    void swap(SetContainer& other);
    void merge(SetContainer& other);
    // Lookup
    iterator_sc find(const Key& key) const;
    bool contains(const Key& key) const;
};

}  // namespace s21

#endif  // SRC_SET_CONTAINER_H_
