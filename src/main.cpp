#include "set.tpp"

// #include <set>
// #include <iostream>

// using namespace s21;
int main() {
    s21::set<int, std::less<int>> s1 = {8, 10, 3, 14, 1, 6, 7, 4, 2, 13, 9, 8};

    // std::cout.setf(std::ios::boolalpha);
    // std::cout << *p.first << " -> " << p.second << std::endl;

    s1.treeDisplay();

    // s21::set<int, std::less<int>> s2;

    // s2.insert(0);
    // s2.insert(-10);
    // s2.insert(22);
    // s2.insert(4);

    // s1.merge(s2);

    s21::set<int, std::less<int>>::iterator it;

    for (it = s1.begin(); it != s1.end(); ++it) {
        // *it = 5;
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    std::cout << s1.size();
}
