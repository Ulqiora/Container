#include "set.tpp"

// #include <iostream>
#include <set>

#define SET_INIT {8, 10, 3, 14, 1, 6, 7, 4, 2, 13, 9, 7};

int main() {
    s21::set<int> s21_set = {8, 3, 6, 1, 0, 4, 5};
    // s21_set.erase(s21_set.find(1));
    // s21_set.erase(s21_set.find(6));
    s21_set.erase(s21_set.find(8));

    s21_set.treeDisplay();

    // std::set<int> std_set = SET_INIT;
    // s21_set.insert(6);
    // s21_set.insert(42);
    // s21_set.insert(100);
    // s21_set.insert(4);



    // std::cout << "STD SET:" << std::endl;
    // std::set<int>::iterator it1;
    // for (it1 = std_set.begin(); it1 != std_set.end(); ++it1) {
    //     std::cout << *it1 << ' ';
    // }
    // std::cout << std::endl;

    std::cout << "MY SET:" << std::endl;
    s21::set<int>::iterator it2;
    for (it2 = s21_set.begin(); it2 != s21_set.end(); ++it2) {
        std::cout << *it2 << ' ';
    }
    std::cout << std::endl;
}
