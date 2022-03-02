#include "tree.h"

namespace s21 {

template <class Key, class Traits>
Tree<Key, Traits>::Tree() : _root(nullptr) {}

template <class Key, class Traits>
Tree<Key, Traits>::Tree(const Tree &t) {
    prefixBypassCopy(t._root);
}

template <class Key, class Traits>
Tree<Key, Traits>::~Tree() {
    destroy(_root);
    _root = nullptr;
}

template <class Key, class Traits>
void Tree<Key, Traits>::destroy(Node<Key> *node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::createNode(Key key) {
    Node<Key> *node = new Node<Key>;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

template <class Key, class Traits>
void Tree<Key, Traits>::insert(Key key) {
    if (_root) {
        insertAfterNode(_root, key);
    } else {
        _root = createNode(key);
    }
}

template <class Key, class Traits>
void Tree<Key, Traits>::insertAfterNode(Node<Key> *node, Key key) {
    if (Traits()(key, node->key)) {
        if (node->left) {
            insertAfterNode(node->left, key);
        } else {
            node->left = createNode(key);
        }
    } else {
        if (node->right) {
            insertAfterNode(node->right, key);
        } else {
            node->right = createNode(key);
        }
    }
}

template <class Key, class Traits>
void Tree<Key, Traits>::insertNoCopy(Key key) {
    if (_root) {
        insertAfterNode_noCopy(_root, key);
    } else {
        _root = createNode(key);
    }
}

template <class Key, class Traits>
void Tree<Key, Traits>::insertAfterNode_noCopy(Node<Key> *node, Key key) {
    if (node->key != key) {
        if (Traits()(key, node->key)) {
            if (node->left) {
                insertAfterNode_noCopy(node->left, key);
            } else {
                node->left = createNode(key);
            }
        } else {
            if (node->right) {
                insertAfterNode_noCopy(node->right, key);
            } else {
                node->right = createNode(key);
            }
        }
    }
}

template <class Key, class Traits>
void Tree<Key, Traits>::display() {
    infixBypassOut(_root);
    std::cout << std::endl;
}

template <class Key, class Traits>
void Tree<Key, Traits>::infixBypassOut(Node<Key> *node) {
    if (node->left) infixBypassOut(node->left);
    std::cout << node->key << ' ';
    if (node->right) infixBypassOut(node->right);
}

template <class Key, class Traits>
void Tree<Key, Traits>::prefixBypassCopy(Node<Key> *node) {
    if (node != NULL) {
        insert(node->key);
        prefixBypassCopy(node->left);
        prefixBypassCopy(node->right);
    }
}

// ПРОШИТЬ ДЕРЕВО

}  // namespace s21
