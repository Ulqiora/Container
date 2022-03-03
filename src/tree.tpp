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
    node->parent = nullptr;
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
            node->left->parent = node;
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
            node->right->parent = node;
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
            if (node->left && !node->leftThread) {
                insertAfterNode_noCopy(node->left, key);
            } else {
                Node<Key> *mem = node->left;
                node->left = createNode(key);
                node->left->right = node;
                node->leftThread = false;
                node->left->left = mem;
                node->left->parent = node;
            }
        } else {
            if (node->right && !node->rightThread) {
                insertAfterNode_noCopy(node->right, key);
            } else {
                Node<Key> *mem = node->right;
                node->right = createNode(key);
                node->right->left = node;
                node->rightThread = false;
                node->right->right = mem;
                node->right->parent = node;
            }
        }
    } else {
        throw std::invalid_argument("The element already present in container!");
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

// *** DEBUG
template <class Key>
void nodeOut(Node<Key> *node) {
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
    std::cout << std::setw(2) << node->key;
    if (node->rightThread) {
        std::cout << " ***> ";
    } else {
        std::cout << " ---> ";
    }
    if (node->right) {
        std::cout << std::setw(4) << node->right->key;
    } else {
        std::cout << std::setw(4) << "null";
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
    Node<Key> *node = leftMost(_root);
    while (node != nullptr) {
        // std::cout << node->key << ' ';
        nodeOut(node);
        if (node->rightThread) {
            node = node->right;
        } else {
            node = leftMost(node->right);
        }
    }
    /*
    Node<Key> *node = rightMost(_root);
    while (node != nullptr) {
        std::cout << node->key << ' ';
        if (node->leftThread) {
            node = node->left;
        } else {
            node = rightMost(node->left);
        }
    }
    */
}

// VERY massive function for overwriting tree structure caused by deleting a node
template <class Key, class Traits>
void Tree<Key, Traits>::erase(Node<Key> *node) {
    if (node == nullptr) {
        throw std::invalid_argument("Nothing to be deleted!");
    }
    // If node doesn't has any childs
    if (node->leftThread && node->rightThread) {
        // If node is _root
        if (node->parent == nullptr) {
            _root = nullptr;
            // If node is left child
        } else if (node == node->parent->left) {
            node->parent->left = node->left;
            node->parent->leftThread = true;
            // If node is right child
        } else {
            node->parent->right = node->right;
            node->parent->rightThread = true;
        }
        // If node has only left child
    } else if (!node->leftThread && node->rightThread) {
        Node<Key> *pred = rightMost(node->left);
        // If node is _root
        if (node->parent == nullptr) {
            pred->right = nullptr;
            _root = node->left;
            // If node is left child
        } else if (node == node->parent->left) {
            pred->right = node->right;
            node->parent->left = node->left;
            // If node is right child
        } else {
            pred->right = node->right;
            node->parent->right = node->left;
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
    if (node != NULL) {
        insert(node->key);
        prefixBypassCopy(node->left);
        prefixBypassCopy(node->right);
    }
}

}  // namespace s21
