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
        if (!node->leftThread) destroy(node->left);
        if (!node->rightThread) destroy(node->right);
        delete node;
    }
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::createNode(Key key) {
    Node<Key> *node = new Node<Key>;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->leftThread = true;
    node->rightThread = true;
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
        if (node->left && !node->leftThread) {
            insertAfterNode(node->left, key);
        } else {
            Node<Key> *mem = node->left;
            node->left = createNode(key);
            node->left->right = node;
            node->leftThread = false;
            node->left->left = mem;
        }
    } else {
        if (node->right && !node->rightThread) {
            insertAfterNode(node->right, key);
        } else {
            Node<Key> *mem = node->right;
            node->right = createNode(key);
            node->right->left = node;
            node->rightThread = false;
            node->right->right = mem;
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
Node<Key> *Tree<Key, Traits>::leftMost(Node<Key> *node) {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr && !node->leftThread) {
        node = node->left;
    }
    return node;
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::rightMost(Node<Key> *node) {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr && !node->rightThread) {
        node = node->right;
    }
    return node;
}

template <class Key, class Traits>
void Tree<Key, Traits>::display() {
    Node<Key> *node = leftMost(_root);
    while (node != nullptr) {
        std::cout << node->key << ' ';
        if (node->rightThread) {
            node = node->right;
        } else {
            node = leftMost(node->right);
        }
    }

    // Node<Key> *node = rightMost(_root);
    // while (node != nullptr) {
    //     std::cout << node->key << ' ';
    //     if (node->leftThread) {
    //         node = node->left;
    //     } else {
    //         node = rightMost(node->left);
    //     }
    // }

    std::cout << std::endl;
}

template <class Key, class Traits>
void Tree<Key, Traits>::prefixBypassCopy(Node<Key> *node) {
    if (node != NULL) {
        insert(node->key);
        prefixBypassCopy(node->left);
        prefixBypassCopy(node->right);
    }
}

}  // namespace s21
