// #include <vector>
#include <iostream>
// #include "vector/vector.tpp"
#include "list/list.tpp"
#include <list>
#include <gtest/gtest.h>

int main(){
    std::list<char> a{1,3,5,7,9,11};
    s21::list<int> b{2,4,6,8,10,12,14};
    std::cout << a.max_size() << std::endl;
    unsigned long long max=std::numeric_limits<int>::max();
    printf("%Ld",max);
    return 0;
}