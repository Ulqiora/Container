// #include <vector>
#include <iostream>
#include "vector/vector.tpp"
#include "list/list.tpp"
#include <list>

int main() {
    std::list<int> a{1,2,3,4};
    s21::list<int> b{2,2,2,2};
    b.push_back(2);
    b.push_front(2);
    b.insert(b.begincbegin(),2);
    std::cout << b.front() << "\n";
    std::cout << b.back() << "\n";
    std::cout << (int)b.size() << "\n";
    std::cout << (int)b.empty() << "\n";
    b.unique();
    for (auto i = b.begincbegin(); i != b.endcend(); ++i) {
        std::cout << *i << " |";
    }
    return 0;
}
