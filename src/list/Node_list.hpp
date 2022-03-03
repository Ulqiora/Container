#pragma once
namespace s21 {
template <class Type_node>
class Node_list {
   public:
    Node_list* next;
    Node_list* prev;
    Type_node* data;
    Node_list(Node_list* next_new, Node_list* prev_new, Type_node& data_add = Type_node()) {
        next = next_new;
        prev = prev_new;
        data = data_add;
    }
    ~Node_list();
};
}  // namespace s21