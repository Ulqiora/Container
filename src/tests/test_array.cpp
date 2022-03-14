#include <gtest/gtest.h>

#include <array>
#include <string>

#include "../s21_array.h"

#define ARRAY_INIT {8, 10, 3, 14, 1, 6, 7, 4, 2, 13, 9, 7};
#define ARRAY_INIT_2 {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

template <class T, std::size_t N>
bool isArraysEqual(const std::array<T, N>& std_arr, const s21::array<T, N>& s21_arr) {
    // Sizes check
    if (std_arr.size() != s21_arr.size()) return false;
    typename std::array<T, N>::const_iterator std_it = std_arr.cbegin();
    typename s21::array<T, N>::const_iterator s21_it = s21_arr.cbegin();
    // Forward bypass
    while (std_it != std_arr.cend() || s21_it != s21_arr.cend()) {
        if (*std_it != *s21_it) {
            return false;
        }
        ++std_it;
        ++s21_it;
    }
    // Backward bypass
    if (std_arr.size() > 0 && s21_arr.size() > 0) {
        std_it = std_arr.cend();
        s21_it = s21_arr.cend();
        --std_it;
        --s21_it;
        while (std_it != std_arr.cbegin() || s21_it != s21_arr.cbegin()) {
            if (*std_it != *s21_it) {
                return false;
            }
            --std_it;
            --s21_it;
        }
        if (*std_it != *s21_it) return false;
    }
    return true;
}

// CONSTRUCTORS

TEST(ARRAY_constructors_suit, default_constructor_1) { s21::array<int, 12> s21_arr; }

TEST(ARRAY_constructors_suit, default_constructor_2) {
    s21::array<int, 0> s21_arr;
    std::array<int, 0> std_arr;
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_constructors_suit, init_constructor_1) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    std::array<int, 12> std_arr = ARRAY_INIT;
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_constructors_suit, init_constructor_2) {
    s21::array<int, 1> s21_arr = {1};
    std::array<int, 1> std_arr = {1};
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_constructors_suit, init_constructor_3) {
    s21::array<std::string, 6> s21_arr = {"Jack", "Scooby", "Rose", "Doo", "Rachel", "Dick"};
    std::array<std::string, 6> std_arr = {"Jack", "Scooby", "Rose", "Doo", "Rachel", "Dick"};
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_constructors_suit, init_constructor_4) { s21::array<int, 12> s21_arr = {}; }

TEST(ARRAY_constructors_suit, init_constructor_5) {
    try {
        s21::array<int, 10> s21_arr = ARRAY_INIT;
        FAIL() << "Expected std::out_of_range";
    } catch (std::out_of_range const& err) {
        EXPECT_EQ(err.what(), std::string("Too many initializers!"));
    }
}

TEST(ARRAY_constructors_suit, copy_constructor_1) {
    s21::array<int, 12> s21_arr1 = ARRAY_INIT;
    s21::array<int, 12> s21_arr2 = s21_arr1;
    std::array<int, 12> std_arr1 = ARRAY_INIT;
    std::array<int, 12> std_arr2 = std_arr1;
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, copy_constructor_2) {
    s21::array<int, 0> s21_arr1;
    s21::array<int, 0> s21_arr2 = s21_arr1;
    std::array<int, 0> std_arr1;
    std::array<int, 0> std_arr2 = std_arr1;
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, move_constructor_1) {
    s21::array<long int, 12> s21_arr1 = ARRAY_INIT;
    s21::array<long int, 12> s21_arr2 = std::move(s21_arr1);
    std::array<long int, 12> std_arr1 = ARRAY_INIT;
    std::array<long int, 12> std_arr2 = std::move(std_arr1);
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, move_constructor_2) {
    s21::array<long int, 0> s21_arr1;
    s21::array<long int, 0> s21_arr2 = std::move(s21_arr1);
    std::array<long int, 0> std_arr1;
    std::array<long int, 0> std_arr2 = std::move(std_arr1);
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, operator_assign_copy_1) {
    s21::array<double, 12> s21_arr1 = ARRAY_INIT;
    s21::array<double, 12> s21_arr2 = {1, 2, 3};
    s21_arr2 = s21_arr1;
    std::array<double, 12> std_arr1 = ARRAY_INIT;
    std::array<double, 12> std_arr2 = {1, 2, 3};
    std_arr2 = std_arr1;
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, operator_assign_copy_2) {
    s21::array<double, 0> s21_arr1;
    s21::array<double, 0> s21_arr2;
    s21_arr2 = s21_arr1;
    std::array<double, 0> std_arr1;
    std::array<double, 0> std_arr2;
    std_arr2 = std_arr1;
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, operator_assign_copy_3) {
    s21::array<double, 12> s21_arr = ARRAY_INIT;
    s21_arr = s21_arr;
    std::array<double, 12> std_arr = ARRAY_INIT;
    std_arr = std_arr;
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_constructors_suit, operator_assign_move_1) {
    s21::array<double, 12> s21_arr1 = ARRAY_INIT;
    s21::array<double, 12> s21_arr2 = {1, 2, 3};
    s21_arr2 = std::move(s21_arr1);
    std::array<double, 12> std_arr1 = ARRAY_INIT;
    std::array<double, 12> std_arr2 = {1, 2, 3};
    std_arr2 = std::move(std_arr1);
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, operator_assign_move_2) {
    s21::array<double, 0> s21_arr1;
    s21::array<double, 0> s21_arr2;
    s21_arr2 = std::move(s21_arr1);
    std::array<double, 0> std_arr1;
    std::array<double, 0> std_arr2;
    std_arr2 = std::move(std_arr1);
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_constructors_suit, operator_assign_move_3) {
    s21::array<double, 12> s21_arr = ARRAY_INIT;
    s21_arr = std::move(s21_arr);
    std::array<double, 12> std_arr = ARRAY_INIT;
    std_arr = std::move(std_arr);
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

// ELEMENT ACCESS

TEST(ARRAY_element_access_suit, at_1) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    std::array<int, 12> std_arr = ARRAY_INIT;
    ASSERT_THROW(s21_arr.at(-1), std::out_of_range);
    ASSERT_EQ(s21_arr.at(0), std_arr.at(0));
    ASSERT_EQ(s21_arr.at(5), std_arr.at(5));
    ASSERT_EQ(s21_arr.at(11), std_arr.at(11));
    ASSERT_THROW(s21_arr.at(12), std::out_of_range);
}

TEST(ARRAY_element_access_suit, at_2) {
    s21::array<int, 1> s21_arr = {42};
    std::array<int, 1> std_arr = {42};
    ASSERT_EQ(s21_arr.at(0), std_arr.at(0));
    ASSERT_THROW(s21_arr.at(1), std::out_of_range);
}

TEST(ARRAY_element_access_suit, at_3) {
    s21::array<int, 0> s21_arr;
    ASSERT_THROW(s21_arr.at(0), std::out_of_range);
}

TEST(ARRAY_element_access_suit, operator_sqr_braces_1) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    std::array<int, 12> std_arr = ARRAY_INIT;
    ASSERT_EQ(s21_arr[0], std_arr[0]);
    ASSERT_EQ(s21_arr[5], std_arr[5]);
    ASSERT_EQ(s21_arr[11], std_arr[11]);
}

TEST(ARRAY_element_access_suit, operator_sqr_braces_2) {
    s21::array<int, 1> s21_arr = {42};
    std::array<int, 1> std_arr = {42};
    ASSERT_EQ(s21_arr[0], std_arr[0]);
}

TEST(ARRAY_element_access_suit, front_1) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    std::array<int, 12> std_arr = ARRAY_INIT;
    ASSERT_EQ(s21_arr.front(), std_arr.front());
    s21_arr[0] = 3;
    std_arr[0] = 3;
    ASSERT_EQ(s21_arr.front(), std_arr.front());
}

TEST(ARRAY_element_access_suit, front_2) {
    s21::array<int, 1> s21_arr = {42};
    std::array<int, 1> std_arr = {42};
    ASSERT_EQ(s21_arr.front(), std_arr.front());
}

TEST(ARRAY_element_access_suit, back_1) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    std::array<int, 12> std_arr = ARRAY_INIT;
    ASSERT_EQ(s21_arr.back(), std_arr.back());
    s21_arr[11] = 3;
    std_arr[11] = 3;
    ASSERT_EQ(s21_arr.back(), std_arr.back());
}

TEST(ARRAY_element_access_suit, back_2) {
    s21::array<int, 1> s21_arr = {42};
    std::array<int, 1> std_arr = {42};
    ASSERT_EQ(s21_arr.back(), std_arr.back());
}

TEST(ARRAY_element_access_suit, data_1) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    std::array<int, 12> std_arr = ARRAY_INIT;
    for (int i = 0; i < 12; i++) {
        ASSERT_EQ(*(std_arr.data() + i), *(s21_arr.data() + i));
    }
}

TEST(ARRAY_element_access_suit, data_2) {
    s21::array<int, 1> s21_arr = {42};
    std::array<int, 1> std_arr = {42};
    ASSERT_EQ(*std_arr.data(), *s21_arr.data());
}

// ITERATORS

TEST(ARRAY_iterators_suit, begin_1) {
    s21::array<int, 12> a = ARRAY_INIT;
    s21::array<int, 12>::iterator it = a.begin();
    ASSERT_EQ(*it, 8);
    ASSERT_EQ(*++it, 10);
}

TEST(ARRAY_iterators_suit, begin_2) {
    s21::array<int, 1> a = {42};
    s21::array<int, 1>::iterator it = a.begin();
    ASSERT_EQ(*it, 42);
    ASSERT_EQ(++it, a.end());
}

TEST(ARRAY_iterators_suit, begin_3) {
    s21::array<int, 0> a;
    s21::array<int, 0>::iterator it = a.begin();
    ASSERT_EQ(it, a.end());
}

TEST(ARRAY_iterators_suit, cbegin_1) {
    s21::array<int, 12> a = ARRAY_INIT;
    s21::array<int, 12>::const_iterator it = a.cbegin();
    ASSERT_EQ(*it, 8);
    ASSERT_EQ(*++it, 10);
}

TEST(ARRAY_iterators_suit, cbegin_2) {
    s21::array<int, 1> a = {42};
    s21::array<int, 1>::const_iterator it = a.cbegin();
    ASSERT_EQ(*it, 42);
    ASSERT_EQ(++it, a.cend());
}

TEST(ARRAY_iterators_suit, cbegin_3) {
    s21::array<int, 0> a;
    s21::array<int, 0>::const_iterator it = a.cbegin();
    ASSERT_EQ(it, a.cend());
}

TEST(ARRAY_iterators_suit, end_1) {
    s21::array<int, 12> a = ARRAY_INIT;
    s21::array<int, 12>::iterator it = a.end();
    ASSERT_EQ(*--it, 7);
    ASSERT_EQ(*--it, 9);
}

TEST(ARRAY_iterators_suit, end_2) {
    s21::array<int, 1> a = {42};
    s21::array<int, 1>::iterator it = a.end();
    ASSERT_EQ(*--it, 42);
}

TEST(ARRAY_iterators_suit, end_3) {
    s21::array<int, 0> a;
    s21::array<int, 0>::iterator it = a.end();
    ASSERT_EQ(it, a.begin());
}

TEST(ARRAY_iterators_suit, cend_1) {
    s21::array<int, 12> a = ARRAY_INIT;
    s21::array<int, 12>::const_iterator it = a.cend();
    ASSERT_EQ(*--it, 7);
    ASSERT_EQ(*--it, 9);
}

TEST(ARRAY_iterators_suit, cend_2) {
    s21::array<int, 1> a = {42};
    s21::array<int, 1>::const_iterator it = a.cend();
    ASSERT_EQ(*--it, 42);
}

TEST(ARRAY_iterators_suit, cend_3) {
    s21::array<int, 0> a;
    s21::array<int, 0>::const_iterator it = a.cend();
    ASSERT_EQ(it, a.cbegin());
}

// CAPACITY

TEST(ARRAY_capacity_suit, empty_1) {
    s21::array<int, 12> a = ARRAY_INIT;
    ASSERT_FALSE(a.empty());
}

TEST(ARRAY_capacity_suit, empty_2) {
    s21::array<int, 12> a = {42};
    ASSERT_FALSE(a.empty());
}

TEST(ARRAY_capacity_suit, empty_3) {
    s21::array<int, 12> a;
    ASSERT_FALSE(a.empty());
}

TEST(ARRAY_capacity_suit, empty_4) {
    s21::array<int, 0> a;
    ASSERT_TRUE(a.empty());
}

TEST(ARRAY_capacity_suit, size_1) {
    s21::array<int, 12> a = ARRAY_INIT;
    ASSERT_EQ(a.size(), 12);
}

TEST(ARRAY_capacity_suit, size_2) {
    s21::array<int, 12> a = {42};
    ASSERT_EQ(a.size(), 12);
}

TEST(ARRAY_capacity_suit, size_3) {
    s21::array<int, 5> a;
    ASSERT_EQ(a.size(), 5);
}

TEST(ARRAY_capacity_suit, size_4) {
    s21::array<int, 0> a;
    ASSERT_EQ(a.size(), 0);
}

TEST(ARRAY_capacity_suit, max_size) {
    s21::array<double, 12> a = ARRAY_INIT;
    size_t real = static_cast<size_t>(pow(2, sizeof(void*) * 8) / sizeof(double) - 1);
    ASSERT_EQ(a.max_size(), real);
}

// MODIFIERS

TEST(ARRAY_modifiers_suit, swap_1) {
    s21::array<int, 12> s21_arr1 = ARRAY_INIT;
    s21::array<int, 12> s21_arr2 = ARRAY_INIT_2;
    s21_arr1.swap(s21_arr2);
    std::array<int, 12> std_arr1 = ARRAY_INIT;
    std::array<int, 12> std_arr2 = ARRAY_INIT_2;
    std_arr1.swap(std_arr2);
    ASSERT_TRUE(isArraysEqual(std_arr1, s21_arr1));
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_modifiers_suit, swap_2) {
    s21::array<int, 0> s21_arr1;
    s21::array<int, 0> s21_arr2;
    s21_arr1.swap(s21_arr2);
    std::array<int, 0> std_arr1;
    std::array<int, 0> std_arr2;
    std_arr1.swap(std_arr2);
    ASSERT_TRUE(isArraysEqual(std_arr1, s21_arr1));
    ASSERT_TRUE(isArraysEqual(std_arr2, s21_arr2));
}

TEST(ARRAY_modifiers_suit, fill_1) {
    s21::array<int, 12> s21_arr;
    s21_arr.fill(42);
    std::array<int, 12> std_arr;
    std_arr.fill(42);
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_modifiers_suit, fill_2) {
    s21::array<int, 12> s21_arr = ARRAY_INIT;
    s21_arr.fill(707);
    std::array<int, 12> std_arr = ARRAY_INIT;
    std_arr.fill(707);
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}

TEST(ARRAY_modifiers_suit, fill_3) {
    s21::array<int, 0> s21_arr;
    s21_arr.fill(42);
    std::array<int, 0> std_arr;
    std_arr.fill(42);
    ASSERT_TRUE(isArraysEqual(std_arr, s21_arr));
}
