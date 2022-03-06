#include "set.tpp"

// #include <set>
// #include <iostream>

// using namespace s21;
int main() {
    s21::set<int, std::less<int>> s1;

    s1.insert(8);
    s1.insert(10);
    s1.insert(3);
    s1.insert(14);
    s1.insert(1);
    s1.insert(6);
    s1.insert(7);
    s1.insert(4);
    s1.insert(2);
    s1.insert(13);
    s1.insert(9);

    std::pair<s21::set<int, std::less<int>>::iterator, bool> p;
    p = s1.insert(40);

    std::cout.setf(std::ios::boolalpha);
    std::cout << *p.first << " -> " << p.second << std::endl;

    s1._tree->display();

    // s21::SetContainer<int, std::less<int>> sc2;

    // sc2._tree->insert(0);
    // sc2._tree->insert(-10);
    // sc2._tree->insert(22);
    // sc2._tree->insert(4);

    // sc1.merge(sc2);

    s21::set<int, std::less<int>>::iterator it;

    for (it = s1.begin(); it != s1.end(); ++it) {
        // *it = 5;
        std::cout << *it << ' ';
    }
    // std::cout << *it << ' ';

}
