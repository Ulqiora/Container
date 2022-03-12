#include <iostream>
// #include <stack>
#include <list>
#include "list/list.tpp"

int main(){
    s21::list<int> b{1, 2, 3, 4, 5, 6};
    s21::list<int>::iterator j = b.begin();
    ++j;
    b.emplace_front(3,4,5);
    j = b.begin();
    while (j != b.end()) {
        std::cout<<*j<<"\n";
        ++j;
    }
    return 0;
}
