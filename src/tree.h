#pragma once

#include <functional>
#include <stdexcept>

#include "pair.h"

namespace s21 {

template <class Key>
struct Node {
    Key key;
    Node<Key> *left;
    Node<Key> *right;
    Node<Key> *parent;
    bool leftThread, rightThread;
    Node();
    explicit Node(Key k);
};

template <class Key, class Traits>
class Tree {
 private:
    Node<Key> *_root;
    Node<Key> *_end;

 public:
    // Constructors & destructor
    Tree();
    Tree(const Tree &t);
    ~Tree();
    // Modifiers
    std::pair<Node<Key> *, bool> insert(Key key, bool allowCopy);
    void erase(Node<Key> *node);
    void destroy(Node<Key> *node);
    void clear();
    void merge(const Tree &other);
    // Lookup
    Node<Key> *begin() const;
    Node<Key> *end() const;
    bool empty() const;
    Node<Key> *find(const Key &key) const;
    Node<Key> *findFrom(const Key &key, Node<Key> *node) const;

 private:
    void prefixBypassCopy(Node<Key> *node);
    inline void appendEndToNode(Node<Key> *node);
    inline void appendToLeft(Node<Key> *node, Key key);
    inline void appendToRight(Node<Key> *node, Key key);
    inline void initialize();
};

template <class Key>
Node<Key> *leftMost(Node<Key> *node);

template <class Key>
Node<Key> *rightMost(Node<Key> *node);

/*
    #########################
    # METHODS IMPLEMENTATION
    #########################
*/

template <class Key>
Node<Key>::Node() : left(nullptr), right(nullptr), leftThread(true), rightThread(true) {}

template <class Key>
Node<Key>::Node(Key k)
    : key(k), left(nullptr), right(nullptr), parent(nullptr), leftThread(true), rightThread(true) {}

template <class Key, class Traits>
Tree<Key, Traits>::Tree() {
    initialize();
}

template <class Key, class Traits>
Tree<Key, Traits>::Tree(const Tree &t) {
    initialize();
    if (!t.empty()) {
        prefixBypassCopy(t._root);
    }
}

template <class Key, class Traits>
Tree<Key, Traits>::~Tree() {
    if (_root) {
        if (_root != _end) destroy(_root);
        delete _end;
        _root = nullptr;
    }
}

template <class Key, class Traits>
inline void Tree<Key, Traits>::initialize() {
    _end = new Node<Key>;
    _root = _end;
}

template <class Key, class Traits>
void Tree<Key, Traits>::destroy(Node<Key> *node) {
    if (!node->leftThread) destroy(node->left);
    if (!node->rightThread) destroy(node->right);
    delete node;
}

template <class Key, class Traits>
inline void Tree<Key, Traits>::appendEndToNode(Node<Key> *node) {
    node->right = _end;
    _end->left = node;
}

template <class Key, class Traits>
std::pair<Node<Key> *, bool> Tree<Key, Traits>::insert(Key key, bool allowCopy) {
    std::pair<Node<Key> *, bool> ret;
    if (!empty()) {
        Node<Key> *node = _root;
        bool isInserted = false;
        while (!isInserted) {
            if (Traits()(key, node->key)) {
                if (node->leftThread) {
                    appendToLeft(node, key);
                    isInserted = true;
                }
                node = node->left;
            } else if (allowCopy || key != node->key) {
                if (node->rightThread) {
                    appendToRight(node, key);
                    isInserted = true;
                }
                node = node->right;
            } else {
                break;
            }
        }
        _end->left = rightMost(_root);
        // pair fill
        ret.first = node;
        ret.second = isInserted;
    } else {
        _root = new Node<Key>(key);
        appendEndToNode(_root);
        // pair fill
        ret.first = _root;
        ret.second = true;
    }
    return ret;
}

template <class Key, class Traits>
inline void Tree<Key, Traits>::appendToLeft(Node<Key> *node, Key key) {
    Node<Key> *mem = node->left;
    node->left = new Node<Key>(key);
    node->left->right = node;
    node->leftThread = false;
    node->left->left = mem;
    node->left->parent = node;
}

template <class Key, class Traits>
inline void Tree<Key, Traits>::appendToRight(Node<Key> *node, Key key) {
    Node<Key> *mem = node->right;
    node->right = new Node<Key>(key);
    node->right->left = node;
    node->rightThread = false;
    node->right->right = mem;
    node->right->parent = node;
}

template <class Key>
Node<Key> *leftMost(Node<Key> *node) {
    if (node == nullptr) return nullptr;
    while (!node->leftThread) {
        node = node->left;
    }
    return node;
}

template <class Key>
Node<Key> *rightMost(Node<Key> *node) {
    if (node == nullptr) return nullptr;
    while (!node->rightThread) {
        node = node->right;
    }
    return node;
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::begin() const {
    return leftMost(_root);
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::end() const {
    return _end;
}

// VERY massive function for overwriting tree structure caused by deleting a node
template <class Key, class Traits>
void Tree<Key, Traits>::erase(Node<Key> *node) {
    if (node == _end) {
        throw std::invalid_argument("Nothing to be deleted!");
    }
    // If node doesn't has any childs
    if (node->leftThread && node->rightThread) {
        // If node is _root
        if (node->parent == nullptr) {
            _root = _end;
            // If node is left child
        } else if (node == node->parent->left) {
            node->parent->left = node->left;
            node->parent->leftThread = true;
            // If node is right child
        } else {
            node->parent->right = node->right;
            node->parent->rightThread = true;
            if (node->right == _end) _end->left = node->parent;
        }
        // If node has only left child
    } else if (!node->leftThread && node->rightThread) {
        Node<Key> *pred = rightMost(node->left);
        // If node is _root
        if (node->parent == nullptr) {
            pred->right = _end;
            _end->left = pred;
            _root = node->left;
            // If node is left child
        } else if (node == node->parent->left) {
            pred->right = node->right;
            node->parent->left = node->left;
            // If node is right child
        } else {
            pred->right = node->right;
            node->parent->right = node->left;
            if (node->right == _end) _end->left = node->left;
        }
        node->left->parent = node->parent;
        // If node has only right child
    } else if (node->leftThread && !node->rightThread) {
        Node<Key> *succ = leftMost(node->right);
        // If node is _root
        if (node->parent == nullptr) {
            succ->left = nullptr;
            _root = node->right;
            // If node is left child
        } else if (node == node->parent->left) {
            succ->left = node->left;
            node->parent->left = node->right;
            // If node is right child
        } else {
            succ->left = node->left;
            node->parent->right = node->right;
        }
        node->right->parent = node->parent;
        // If node has both childs
    } else {
        Node<Key> *pred = rightMost(node->left);
        Node<Key> *succ = leftMost(node->right);
        pred->right = succ;
        succ->left = node->left;
        succ->leftThread = false;
        if (succ != node->right) {
            succ->right = node->right;
            succ->rightThread = false;
        }
        succ->parent->leftThread = true;
        node->left->parent = succ;
        node->right->parent = succ;
        // If node is _root
        if (node->parent == nullptr) {
            succ->parent = nullptr;
            _root = succ;
        } else {
            succ->parent = node->parent;
            // If node is left child
            if (node == node->parent->left) {
                node->parent->left = succ;
                // If node is right child
            } else {
                node->parent->right = succ;
            }
        }
    }
    delete node;
}

template <class Key, class Traits>
void Tree<Key, Traits>::prefixBypassCopy(Node<Key> *node) {
    insert(node->key, true);
    if (!node->leftThread) prefixBypassCopy(node->left);
    if (!node->rightThread) prefixBypassCopy(node->right);
}

template <class Key, class Traits>
bool Tree<Key, Traits>::empty() const {
    return (_root == _end);
}

template <class Key, class Traits>
void Tree<Key, Traits>::clear() {
    if (_root != _end) destroy(_root);
    _root = _end;
}

template <class Key, class Traits>
void Tree<Key, Traits>::merge(const Tree &other) {
    if (!other.empty()) {
        prefixBypassCopy(other._root);
    }
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::find(const Key &key) const {
    if (empty()) return nullptr;
    return findFrom(key, _root);
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::findFrom(const Key &key, Node<Key> *node) const {
    while (node->key != key) {
        if (Traits()(key, node->key)) {
            if (!node->leftThread) {
                node = node->left;
            } else {
                return nullptr;
            }
        } else {
            if (!node->rightThread) {
                node = node->right;
            } else {
                return nullptr;
            }
        }
    }
    return node;
}

}  // namespace s21
