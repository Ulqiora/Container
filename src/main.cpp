#include "set_container.tpp"

// using namespace s21;
int main() {
    s21::SetContainer<int, std::less<int>> sc;

    sc._tree->insert(8);
    sc._tree->insert(3);
    sc._tree->insert(10);
    sc._tree->insert(1);
    sc._tree->insert(6);
    sc._tree->insert(14);
    sc._tree->insert(4);
    sc._tree->insert(13);
    sc._tree->insert(7);
    // sc._tree->insert(2);
    // sc._tree->insert(1);

    sc._tree->display();

    int *ptr = sc._tree->getByIndex(2);

    std::cout << *ptr;


    // t.insert(10);
    // t.insert(7);
    // t.insert(1);

    // t.display();

    return 0;
}
