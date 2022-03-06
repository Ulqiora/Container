#ifndef SRC_TREE_H_
#define SRC_TREE_H_

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
    void insert(Key key);
    void insertNoCopy(Key key);
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

 private:
    Node<Key> *createNode(Key key);
    void insertAfterNode(Node<Key> *node, Key key);
    void insertAfterNode_noCopy(Node<Key> *node, Key key);
    void prefixBypassCopy(Node<Key> *node);
    void nodeOut(Node<Key> *node);  // *** DEBUG
    inline void appendEndToNode(Node<Key> *node);
    inline void initialize();
};

template <class Key>
Node<Key> *leftMost(Node<Key> *node);

template <class Key>
Node<Key> *rightMost(Node<Key> *node);

}  // namespace s21

#endif  // SRC_TREE_H_
