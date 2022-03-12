#pragma once

namespace s21 {
template <class Node_type>
class Node_ {
 public:
    Node_type value_;
    Node_* next_;
    Node_(Node_* next, Node_type const& data_add = Node_type()) : next_(next), value_(data_add) {}
    ~Node_() {}
};
}  // namespace s21