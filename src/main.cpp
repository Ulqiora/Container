#include "set_container.tpp"

// using namespace s21;
int main() {
    s21::Tree<int, std::less<int>> t;

    t.insert(8);
    t.insert(10);
    t.insert(3);
    t.insert(14);
    t.insert(1);
    t.insert(6);
    t.insert(7);
    t.insert(4);
    t.insert(2);
    t.insert(13);

    t.erase(t._root);

    t.display();

    return 0;
}
