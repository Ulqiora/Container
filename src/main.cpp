#include <vector>
#include <iostream>

int main() {
    std::vector<int> f{5,2,3,4};
    f.resize(7);
    f.size();
    for (auto i = f.begin(); i != f.end(); i++) {
        std::cout << *i << ' ';
    }
    return 0;
}