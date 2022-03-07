#pragma once

namespace s21 {
template <class Node_type>
class Node {
    Node_type value_;
    Node* next_;
   public:
    Node(Node* next, Node_type const& data_add = Node_type()) : next_(next), value(data_add) {}
    ~Node() {}
};
}  // namespace s21