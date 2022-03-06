#pragma once

namespace s21 {
template <class Node_type>
class Node_queue {
    Node_type value_;
    Node_queue* next_;
   public:
    Node_queue(Node_queue* next, Node_type const& data_add = Node_type()) : next_(next), value(data_add) {}
    ~Node_queue() {}
};
}  // namespace s21