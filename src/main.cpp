// #include <vector>
#include <iostream>
#include "vector/vector.tpp"

int main() {
    s21::vector<int> a(3);
    a[0] = 1;
    a[1] = 5;
    a[2] = 10;
    s21::vector<int> b;
    b=std::move(a);
    for(auto i=b.begincbegin();i!=b.endcend();i++){
        std::cout << *i << ' ';
    }
    std::cout << "\nsize=" << a.size() << std::endl;
    std::cout << "capacity=" << a.capacity() << std::endl;
    try {
        a.at(3);
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}