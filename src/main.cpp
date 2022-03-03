// #include <vector>
#include <iostream>
#include "vector/vector.tpp"
#include "list/list.tpp"
#include <list>

int main() {
    std::list<int> a{1,2,3,4};
    s21::list<int> b{1,2,2,3};
    // std::cout << *a.insert(a.begin(),5)<<std::endl;
    // b.push_back(3);
    s21::list<int>::iterator it=b.begincbegin();
    ++it;
    b.insert(it,8);
    b.push_back(9);
    b.push_front(10);
    // std::cout << b.front() << "\n";
    // std::cout << b.back() << "\n";
    // std::cout << (int)b.size() << "\n";
    // std::cout << (int)b.empty() << "\n";
    // b.unique();
    std::cout<<"list:";
    for (auto i = b.begincbegin(); i != b.endcend(); ++i) {
        std::cout << *i <<"|";    
    }
    std::cout<<"\nsize="<<b.size()<<"|";
    return 0;
}
