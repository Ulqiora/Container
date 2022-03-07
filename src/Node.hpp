#pragma once

namespace s21 {
template <class Node_type>
class Node {
 public:
    Node_type value_;
    Node* next_;
    Node(Node* next, Node_type const& data_add = Node_type()) : next_(next), value_(data_add) {}
    ~Node() {}
};
}  // namespace s21