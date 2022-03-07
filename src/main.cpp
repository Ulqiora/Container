#include "multiset.tpp"

// #include <iostream>
// #include <set>

int main() {
    using namespace s21;
    // using namespace std;

    multiset<int> s1 = {8, 10, 3, 14, 1, 6, 7, 4, 2, 13, 9, 7};

    s1.insert(7);

    // std::cout.setf(std::ios::boolalpha);
    // std::cout << *p.first << " -> " << p.second << std::endl;

    // s1.treeDisplay();

    // s21::set<int> s2;

    // s2.insert(0);
    // s2.insert(-10);
    // s2.insert(22);
    // s2.insert(4);

    // s1.merge(s2);

    multiset<int>::iterator it;

    for (it = s1.begin(); it != s1.end(); ++it) {
        // *it = 5;
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::pair<multiset<int>::iterator, multiset<int>::iterator> pr = s1.equal_range(9);
    for (it = pr.first; it != pr.second; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    // std::cout << *(s1.upper_bound(7));
}
