#ifndef SRC_TREE_HPP_
#define SRC_TREE_HPP_

#include <functional>
#include <iomanip>   // *** DEBUG
#include <iostream>  // *** DEBUG

namespace s21 {

template <class Key>
struct Node {
    Key key;
    Node<Key> *left;
    Node<Key> *right;
    Node<Key> *parent;
    bool leftThread, rightThread;
    Node();
    Node(Key k);
};

template <class Key, class Traits>
class Tree {
 private:
    Node<Key> *_root;
    Node<Key> *_end;

 public:
    // Constructors & destructor
    Tree<Key, Traits>();
    Tree(const Tree &t);
    ~Tree();
    // Modifiers
    std::pair<Node<Key> *, bool> insert(Key key, bool allowCopy);
    std::pair<Node<Key> *, bool> insertPair(Key p, bool allowCopy);
    void erase(Node<Key> *node);
    void destroy(Node<Key> *node);
    void clear();
    void merge(Tree &other);
    // Lookup
    void display();  // *** DEBUG
    Node<Key> *begin() const;
    Node<Key> *end() const;
    bool empty() const;
    Node<Key> *find(const Key &key) const;
    Node<Key> *findFrom(const Key &key, Node<Key> *node) const;
    bool containsPair(const Key &key) const;

 private:
    void prefixBypassCopy(Node<Key> *node);
    void nodeOut(Node<Key> *node);  // *** DEBUG
    inline void appendEndToNode(Node<Key> *node);
    inline void appendToLeft(Node<Key> *node, Key key);
    inline void appendToRight(Node<Key> *node, Key key);
    inline void initialize();
};

template <class Key>
Node<Key> *leftMost(Node<Key> *node);

template <class Key>
Node<Key> *rightMost(Node<Key> *node);

}  // namespace s21

#endif  // SRC_TREE_HPP_
