#ifndef SRC_TREE_H_
#define SRC_TREE_H_

#include <functional>
#include <iostream>

namespace s21 {

template <class Key>
struct Node {
    Key key;
    Node<Key> *left;
    Node<Key> *right;
};

template <class Key, class Traits>
class Tree {
 private:
    Node<Key> *root;

 public:
    // Constructor
    Tree();
    ~Tree();
    // Methods
    void insert(Key key);
    void insertNoCopy(Key key);
    void display(); // *** DEBUG
    // Other
 private:
    Node<Key> *createNode(Key key);
    void insertAfterNode(Node<Key> *node, Key key);
    void insertAfterNode_noCopy(Node<Key> *node, Key key);
    void destroy(Node<Key> *node);
    void infixBypass(Node<Key> *node);  // *** DEBUG
};

}  // namespace s21

#endif  // SRC_TREE_H_
