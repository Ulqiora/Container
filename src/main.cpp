#include <iostream>
// #include <stack>
#include <vector>
#include "vector/vector.tpp"

int main(){
    // s21::vector<int> a{1, 2, 3, 4, 5, 6};
    s21::vector<int> b{1, 2, 3, 4, 5, 6};
    s21::vector<int>::iterator j = b.begin();
    // s21::vector<int>::iterator i = a.begin();
    int add=7;
    while (j != b.end()) {
        std::cout << *j << std::endl;
        ++j;
    }
    std::cout << "\n\n\n";
    j = b.begin();
    // ++j;
    s21::vector<int>::iterator j1 = b.insert(j, add);
    // i = a.begin();
    j = b.begin();
    while(j!=b.end()){
        std::cout<<*j<<std::endl;
        // ++i;
        ++j;
    }
    return 0;
}
