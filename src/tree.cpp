#include "tree.h"
using namespace s21;

template <class Key, class Traits>
Tree<Key, Traits>::Tree(const Tree& t) {
    prefixBypassCopy(t.root);
}

template <class Key, class Traits>
Tree<Key, Traits>::~Tree() {
    destroy(root);
}

template <class Key, class Traits>
void Tree<Key, Traits>::destroy(Node<Key>* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <class Key, class Traits>
Node<Key>* Tree<Key, Traits>::createNode(Key key) {
    Node<Key>* node = new Node<Key>;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

template <class Key, class Traits>
void Tree<Key, Traits>::insert(Key key) {
    if (root) {
        insertAfterNode(root, key);
    } else {
        root = createNode(key);
    }
}

template <class Key, class Traits>
void Tree<Key, Traits>::insertAfterNode(Node<Key>* node, Key key) {
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
    if (root) {
        insertAfterNode_noCopy(root, key);
    } else {
        root = createNode(key);
    }
}

template <class Key, class Traits>
void Tree<Key, Traits>::insertAfterNode_noCopy(Node<Key>* node, Key key) {
    if (node->key != key) {
        if (Traits()(node->key, key)) {
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
    infixBypass(root);
    std::cout << std::endl;
}

template <class Key, class Traits>
void Tree<Key, Traits>::infixBypass(Node<Key>* node) {
    if (node->left) infixBypass(node->left);
    std::cout << node->key << ' ';
    if (node->right) infixBypass(node->right);
}

template <class Key, class Traits>
void Tree<Key, Traits>::prefixBypassCopy(Node<Key>* node) {
    if (node != NULL) {
        insert(node->key);
        prefixBypassCopy(node->left);
        prefixBypassCopy(node->right);
    }
}
