#ifndef SRC_TREE_H_
#define SRC_TREE_H_

#include <functional>
#include <iostream>  // *** DEBUG

namespace s21 {

template <class Key>
struct Node {
    Key key;            // value
    Node<Key> *left;    // left child
    Node<Key> *right;   // right child
    bool rightThread;   // is right child a thread?
};

template <class Key, class Traits>
class Tree {
 private:
    Node<Key> *_root;

 public:
    // Constructors & destructor
    Tree<Key, Traits>();
    Tree(const Tree &t);
    ~Tree();
    // Methods
    void insert(Key key);
    void insertNoCopy(Key key);
    void display();  // *** DEBUG

 private:
    Node<Key> *createNode(Key key);
    void insertAfterNode(Node<Key> *node, Key key);
    void insertAfterNode_noCopy(Node<Key> *node, Key key);
    void destroy(Node<Key> *node);
    Node<Key> *leftMost(Node<Key> *node);
    void prefixBypassCopy(Node<Key> *node);
};

}  // namespace s21

#endif  // SRC_TREE_H_
