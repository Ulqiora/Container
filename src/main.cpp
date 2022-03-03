#include "set_container.tpp"

// #include <set>

// using namespace s21;
int main() {
    s21::SetContainer<int, std::less<int>> sc;

    sc._tree->insert(8);
    sc._tree->insert(10);
    sc._tree->insert(3);
    sc._tree->insert(14);
    sc._tree->insert(1);
    sc._tree->insert(6);
    sc._tree->insert(7);
    sc._tree->insert(4);
    sc._tree->insert(2);
    sc._tree->insert(13);
    sc._tree->insert(9);

    sc._tree->display();

    s21::SetContainer<int, std::less<int>>::iterator_sc it;

    for (it = sc.begin(); it != sc.end(); ++it) {
        // *it = 5;
        std::cout << *it << ' ';
    }
}
