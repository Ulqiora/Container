#include "tree.hpp"

namespace s21 {

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
    _end->leftThread = true;
    _end->rightThread = true;
    _end->right = nullptr;
    _root = _end;
}

template <class Key, class Traits>
void Tree<Key, Traits>::destroy(Node<Key> *node) {
    if (!node->leftThread) destroy(node->left);
    if (!node->rightThread) destroy(node->right);
    delete node;
}

template <class Key, class Traits>
Node<Key> *Tree<Key, Traits>::createNode(Key key) {
    Node<Key> *node = new Node<Key>;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    node->leftThread = true;
    node->rightThread = true;
    return node;
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
        _root = createNode(key);
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
    node->left = createNode(key);
    node->left->right = node;
    node->leftThread = false;
    node->left->left = mem;
    node->left->parent = node;
}

template <class Key, class Traits>
inline void Tree<Key, Traits>::appendToRight(Node<Key> *node, Key key) {
    Node<Key> *mem = node->right;
    node->right = createNode(key);
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

template <class Key, class Traits>
void Tree<Key, Traits>::nodeOut(Node<Key> *node) {
    if (node->left) {
        std::cout << std::setw(4) << node->left->key;
    } else {
        std::cout << std::setw(4) << "null";
    }
    if (node->leftThread) {
        std::cout << " <*** ";
    } else {
        std::cout << " <--- ";
    }
    if (node != _end) {
        std::cout << std::setw(3) << node->key;
    } else {
        std::cout << "end";
    }
    if (node->rightThread) {
        std::cout << " ***> ";
    } else {
        std::cout << " ---> ";
    }
    if (node->right != _end) {
        if (node->right) {
            std::cout << std::setw(4) << node->right->key;
        } else {
            std::cout << "null";
        }
    } else {
        std::cout << std::setw(4) << " end";
    }
    std::cout << "\t| parent: ";
    if (node->parent) {
        std::cout << std::setw(4) << node->parent->key;
    } else {
        std::cout << "null";
    }
    std::cout << std::endl;
}

template <class Key, class Traits>
void Tree<Key, Traits>::display() {
    Node<Key> *node = begin();
    while (node != _end) {
        nodeOut(node);
        if (node->rightThread) {
            node = node->right;
        } else {
            node = leftMost(node->right);
        }
    }
    nodeOut(node);
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
            if (node->right == _end) _end->left = node->parent;
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
void Tree<Key, Traits>::merge(Tree &other) {
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
