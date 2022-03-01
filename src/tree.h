#ifndef SRC_TREE_H_
#define SRC_TREE_H_

#include <functional>
#include <iostream>  // *** DEBUG

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
    Key *getByIndex(int pos);

 private:
    Node<Key> *createNode(Key key);
    void insertAfterNode(Node<Key> *node, Key key);
    void insertAfterNode_noCopy(Node<Key> *node, Key key);
    void destroy(Node<Key> *node);
    void infixBypassOut(Node<Key> *node);  // *** DEBUG
    void prefixBypassCopy(Node<Key> *node);
    Key *infixBypassGet(Node<Key> *node, int pos);
};

}  // namespace s21

#endif  // SRC_TREE_H_
