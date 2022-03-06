#include "set_container.tpp"

// #include <set>

// using namespace s21;
int main() {
    s21::SetContainer<int, std::greater<int>> sc1;

    sc1._tree->insert(8);
    sc1._tree->insert(10);
    sc1._tree->insert(3);
    sc1._tree->insert(14);
    sc1._tree->insert(1);
    sc1._tree->insert(6);
    sc1._tree->insert(7);
    sc1._tree->insert(4);
    sc1._tree->insert(2);
    sc1._tree->insert(13);
    sc1._tree->insert(9);

    // s21::SetContainer<int, std::greater<int>> sc2;

    // sc2._tree->insert(0);
    // sc2._tree->insert(-10);
    // sc2._tree->insert(22);
    // sc2._tree->insert(4);

    // sc1.merge(sc2);

    // s21::SetContainer<int, std::greater<int>>::iterator_sc it;

    std::cout.setf(std::ios::boolalpha);
    std::cout << sc1.contains(4) << std::endl;

    // for (it = sc1.begin(); it != sc1.end(); ++it) {
    //     // *it = 5;
    //     std::cout << *it << ' ';
    // }

}
