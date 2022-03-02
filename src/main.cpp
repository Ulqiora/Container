// #include <vector>
#include <iostream>
#include "vector/vector.tpp"
#include "list/list.tpp"
#include <list>

int main() {
    std::list<int> a{1,2,3,4};
    s21::list<int> b{1,2,3,4};
    for(auto i=a.begin();i!=a.end();++i){
        std::cout << *i << " ";
    }
    std::cout << "\n";
    for (auto i = b.begincbegin(); i != (b.endcend()); ++i) {
        std::cout << *i << " ";
    }
    return 0;
}