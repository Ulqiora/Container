#include "array.tpp"

// #include <iostream>
#include <array>

int main() {
    s21::array<int, 5> a = {1, 2, 3, 4};
    s21::array<int, 5> b = std::move(a);

    return 0;
}
