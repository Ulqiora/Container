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
    class iterator {
     private:
        Node<Key>* _node;

     public:
        iterator();
        iterator(const iterator& it);
        ~iterator();
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
    SetContainer<Key, Traits>& operator=(const SetContainer& s);
    // Iterators
    iterator begin() const;
    const iterator cbegin() const;
    iterator end() const;
    const iterator cend() const;
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
