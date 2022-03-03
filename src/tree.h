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

 public:
    // Constructors & destructor
    Tree<Key, Traits>();
    Tree(const Tree &t);
    ~Tree();
    // Methods
    void insert(Key key);
    void insertNoCopy(Key key);
    void display();  // *** DEBUG
    void erase(Node<Key> *node);

 private:
    Node<Key> *createNode(Key key);
    void insertAfterNode(Node<Key> *node, Key key);
    void insertAfterNode_noCopy(Node<Key> *node, Key key);
    void destroy(Node<Key> *node);
    Node<Key> *leftMost(Node<Key> *node);
    Node<Key> *rightMost(Node<Key> *node);
    void prefixBypassCopy(Node<Key> *node);
};

}  // namespace s21

#endif  // SRC_TREE_H_
