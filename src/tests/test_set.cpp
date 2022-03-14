#include <gtest/gtest.h>

#include <set>
#include <string>

#include "../s21_set.h"

#define SET_INIT {8, 10, 3, 14, 1, 6, 7, 4, 2, 13, 9, 7};

template <class Key, class Traits>
bool isSetEqual(const std::set<Key, Traits>& std_set, const s21::set<Key, Traits>& s21_set) {
    // Sizes check
    if (std_set.size() != s21_set.size()) return false;
    typename std::set<Key, Traits>::iterator std_it = std_set.begin();
    typename s21::set<Key, Traits>::iterator s21_it = s21_set.begin();
    // Forward bypass
    while (std_it != std_set.end() || s21_it != s21_set.end()) {
        if (*std_it != *s21_it) {
            return false;
        }
        ++std_it;
        ++s21_it;
    }
    // Backward bypass
    if (std_set.size() > 0 && s21_set.size() > 0) {
        std_it = --std_set.end();
        s21_it = --s21_set.end();
        while (std_it != std_set.begin() || s21_it != s21_set.begin()) {
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

TEST(SET_constructors_suit, default_constructor) {
    s21::set<int> s21_set;
    std::set<int> std_set;
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, init_constructor_1) {
    s21::set<int> s21_set = SET_INIT;
    std::set<int> std_set = SET_INIT;
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, init_constructor_2) {
    s21::set<int> s21_set = {1};
    std::set<int> std_set = {1};
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, init_constructor_3) {
    s21::set<std::string> s21_set = {"Jack", "Scooby", "Rose", "Doo", "Rachel", "Dick"};
    std::set<std::string> std_set = {"Jack", "Scooby", "Rose", "Doo", "Rachel", "Dick"};
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, init_constructor_4) {
    s21::set<int> s21_set = {};
    std::set<int> std_set = {};
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, init_constructor_5) {
    s21::set<int, std::greater<int>> s21_set SET_INIT;
    std::set<int, std::greater<int>> std_set SET_INIT;
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, copy_constructor_1) {
    s21::set<int> s21_set1 = SET_INIT;
    s21::set<int> s21_set2 = s21_set1;
    std::set<int> std_set1 = SET_INIT;
    std::set<int> std_set2 = std_set1;
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, copy_constructor_2) {
    s21::set<int> s21_set1 = {1};
    s21::set<int> s21_set2 = s21_set1;
    std::set<int> std_set1 = {1};
    std::set<int> std_set2 = std_set1;
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, copy_constructor_3) {
    s21::set<int> s21_set1;
    s21::set<int> s21_set2 = s21_set1;
    std::set<int> std_set1;
    std::set<int> std_set2 = std_set1;
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, move_constructor_1) {
    s21::set<long int> s21_set1 = SET_INIT;
    s21::set<long int> s21_set2 = std::move(s21_set1);
    std::set<long int> std_set1 = SET_INIT;
    std::set<long int> std_set2 = std::move(std_set1);
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, move_constructor_2) {
    s21::set<long int> s21_set1 = {1};
    s21::set<long int> s21_set2 = std::move(s21_set1);
    std::set<long int> std_set1 = {1};
    std::set<long int> std_set2 = std::move(std_set1);
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, move_constructor_3) {
    s21::set<long int> s21_set1;
    s21::set<long int> s21_set2 = std::move(s21_set1);
    std::set<long int> std_set1;
    std::set<long int> std_set2 = std::move(std_set1);
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_copy_1) {
    s21::set<double> s21_set1 = SET_INIT;
    s21::set<double> s21_set2 = {1, 2, 3};
    s21_set2 = s21_set1;
    std::set<double> std_set1 = SET_INIT;
    std::set<double> std_set2 = {1, 2, 3};
    std_set2 = std_set1;
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_copy_2) {
    s21::set<double> s21_set1 = {1};
    s21::set<double> s21_set2 = {1, 2, 3};
    s21_set2 = s21_set1;
    std::set<double> std_set1 = {1};
    std::set<double> std_set2 = {1, 2, 3};
    std_set2 = std_set1;
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_copy_3) {
    s21::set<double> s21_set1;
    s21::set<double> s21_set2 = {1, 2, 3};
    s21_set2 = s21_set1;
    std::set<double> std_set1;
    std::set<double> std_set2 = {1, 2, 3};
    std_set2 = std_set1;
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_copy_4) {
    s21::set<double> s21_set = SET_INIT;
    s21_set = s21_set;
    std::set<double> std_set = SET_INIT;
    std_set = std_set;
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_constructors_suit, operator_assign_move_1) {
    s21::set<double> s21_set1 = SET_INIT;
    s21::set<double> s21_set2 = {1, 2, 3};
    s21_set2 = std::move(s21_set1);
    std::set<double> std_set1 = SET_INIT;
    std::set<double> std_set2 = {1, 2, 3};
    std_set2 = std::move(std_set1);
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_move_2) {
    s21::set<double> s21_set1 = {1};
    s21::set<double> s21_set2 = {1, 2, 3};
    s21_set2 = std::move(s21_set1);
    std::set<double> std_set1 = {1};
    std::set<double> std_set2 = {1, 2, 3};
    std_set2 = std::move(std_set1);
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_move_3) {
    s21::set<double> s21_set1;
    s21::set<double> s21_set2 = {1, 2, 3};
    s21_set2 = std::move(s21_set1);
    std::set<double> std_set1;
    std::set<double> std_set2 = {1, 2, 3};
    std_set2 = std::move(std_set1);
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_constructors_suit, operator_assign_move_4) {
    s21::set<double> s21_set = SET_INIT;
    s21_set = std::move(s21_set);
    std::set<double> std_set = SET_INIT;
    std_set = std::move(std_set);
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

// ITERATORS

TEST(SET_iterators_suit, begin_1) {
    s21::set<int> s = SET_INIT;
    s21::set<int>::iterator it = s.begin();
    ASSERT_EQ(*it, 1);
    ASSERT_EQ(*++it, 2);
}

TEST(SET_iterators_suit, begin_2) {
    s21::set<int> s = {42};
    s21::set<int>::iterator it = s.begin();
    ASSERT_EQ(*it, 42);
    ASSERT_EQ(++it, s.end());
}

TEST(SET_iterators_suit, begin_3) {
    s21::set<int> s;
    s21::set<int>::iterator it = s.begin();
    ASSERT_EQ(it, s.end());
}

TEST(SET_iterators_suit, cbegin_1) {
    s21::set<int> s = SET_INIT;
    s21::set<int>::const_iterator it = s.cbegin();
    ASSERT_EQ(*it, 1);
    ASSERT_EQ(*++it, 2);
}

TEST(SET_iterators_suit, cbegin_2) {
    s21::set<int> s = {42};
    s21::set<int>::const_iterator it = s.cbegin();
    ASSERT_EQ(*it, 42);
    ASSERT_EQ(++it, s.end());
}

TEST(SET_iterators_suit, cbegin_3) {
    s21::set<int> s;
    s21::set<int>::const_iterator it = s.cbegin();
    ASSERT_EQ(it, s.end());
}

TEST(SET_iterators_suit, end_1) {
    s21::set<int> s = SET_INIT;
    s21::set<int>::iterator it = s.end();
    ASSERT_EQ(*--it, 14);
    ASSERT_EQ(*--it, 13);
}

TEST(SET_iterators_suit, end_2) {
    s21::set<int> s = {42};
    s21::set<int>::iterator it = s.end();
    ASSERT_EQ(*--it, 42);
}

TEST(SET_iterators_suit, end_3) {
    s21::set<int> s;
    s21::set<int>::iterator it = s.end();
    ASSERT_EQ(it, s.begin());
}

TEST(SET_iterators_suit, cend_1) {
    s21::set<int> s = SET_INIT;
    s21::set<int>::const_iterator it = s.cend();
    ASSERT_EQ(*--it, 14);
    ASSERT_EQ(*--it, 13);
}

TEST(SET_iterators_suit, cend_2) {
    s21::set<int> s = {42};
    s21::set<int>::const_iterator it = s.cend();
    ASSERT_EQ(*--it, 42);
}

TEST(SET_iterators_suit, cend_3) {
    s21::set<int> s;
    s21::set<int>::const_iterator it = s.cend();
    ASSERT_EQ(it, s.begin());
}

// CAPACITY

TEST(SET_capacity_suit, empty_1) {
    s21::set<int> s = SET_INIT;
    ASSERT_FALSE(s.empty());
}

TEST(SET_capacity_suit, empty_2) {
    s21::set<int> s = {42};
    ASSERT_FALSE(s.empty());
    s.erase(s.begin());
    ASSERT_TRUE(s.empty());
}

TEST(SET_capacity_suit, empty_3) {
    s21::set<int> s;
    ASSERT_TRUE(s.empty());
}

TEST(SET_capacity_suit, size_1) {
    s21::set<int> s = SET_INIT;
    ASSERT_EQ(s.size(), 11);
    s.erase(s.begin());
    ASSERT_EQ(s.size(), 10);
    s.insert(13);
    ASSERT_EQ(s.size(), 10);
    s.insert(42);
    ASSERT_EQ(s.size(), 11);
}

TEST(SET_capacity_suit, size_2) {
    s21::set<int> s = {42};
    ASSERT_EQ(s.size(), 1);
    s.erase(s.begin());
    ASSERT_EQ(s.size(), 0);
    s.insert(42);
    s.insert(21);
    ASSERT_EQ(s.size(), 2);
}

TEST(SET_capacity_suit, max_size) {
    s21::set<double> s = SET_INIT;
    size_t real = static_cast<size_t>(
        pow(2, sizeof(void*) * 8) / (sizeof(double) + 3 * sizeof(void*) + 2 * sizeof(bool)) - 1);
    ASSERT_EQ(s.max_size(), real);
}

// MODIFIERS

TEST(SET_modifiers_suit, clear_1) {
    s21::set<int> s21_set = SET_INIT;
    s21_set.clear();
    std::set<int> std_set = SET_INIT;
    std_set.clear();
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, clear_2) {
    s21::set<int> s21_set = {42};
    s21_set.clear();
    std::set<int> std_set = {42};
    std_set.clear();
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, clear_3) {
    s21::set<int> s21_set;
    s21_set.clear();
    std::set<int> std_set;
    std_set.clear();
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, insert) {
    s21::set<int> s21_set = SET_INIT;
    std::pair<s21::set<int>::iterator, bool> p;
    p = s21_set.insert(6);
    ASSERT_EQ(*p.first, 6);
    ASSERT_FALSE(p.second);
    p = s21_set.insert(42);
    ASSERT_EQ(*p.first, 42);
    ASSERT_TRUE(p.second);
    p = s21_set.insert(100);
    ASSERT_EQ(*p.first, 100);
    ASSERT_TRUE(p.second);
    p = s21_set.insert(4);
    ASSERT_EQ(*p.first, 4);
    ASSERT_FALSE(p.second);
    std::set<int> std_set = SET_INIT;
    std_set.insert(6);
    std_set.insert(42);
    std_set.insert(100);
    std_set.insert(4);
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, erase_1) {
    s21::set<int> s21_set = {8, 3, 10};
    s21_set.erase(s21_set.find(3));
    s21_set.erase(s21_set.find(10));
    s21_set.erase(s21_set.find(8));
    std::set<int> std_set = {8, 3, 10};
    std_set.erase(std_set.find(3));
    std_set.erase(std_set.find(10));
    std_set.erase(std_set.find(8));
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, erase_2) {
    s21::set<int> s21_set = {8, 3, 6, 1, 0, 4, 5};
    s21_set.erase(s21_set.find(1));
    s21_set.erase(s21_set.find(6));
    s21_set.erase(s21_set.find(8));
    std::set<int> std_set = {8, 3, 6, 1, 0, 4, 5};
    std_set.erase(std_set.find(1));
    std_set.erase(std_set.find(6));
    std_set.erase(std_set.find(8));
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, erase_3) {
    s21::set<int> s21_set = {8, 13, 10, 14, 11, 15, 2};
    s21_set.erase(s21_set.find(10));
    s21_set.erase(s21_set.find(14));
    s21_set.erase(s21_set.find(8));
    std::set<int> std_set = {8, 13, 10, 14, 11, 15, 2};
    std_set.erase(std_set.find(10));
    std_set.erase(std_set.find(14));
    std_set.erase(std_set.find(8));
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, erase_4) {
    s21::set<int> s21_set = SET_INIT;
    s21_set.erase(s21_set.find(3));
    s21_set.erase(s21_set.find(10));
    s21_set.erase(s21_set.find(8));
    std::set<int> std_set = SET_INIT;
    std_set.erase(std_set.find(3));
    std_set.erase(std_set.find(10));
    std_set.erase(std_set.find(8));
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, erase_5) {
    s21::set<int> s21_set = SET_INIT;
    s21_set.erase(--s21_set.end());
    std::set<int> std_set = SET_INIT;
    std_set.erase(--std_set.end());
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, erase_6) {
    s21::set<int> s21_set = {42};
    s21_set.erase(s21_set.find(42));
    std::set<int> std_set = {42};
    std_set.erase(std_set.find(42));
    ASSERT_TRUE(isSetEqual(std_set, s21_set));
}

TEST(SET_modifiers_suit, swap_1) {
    s21::set<int> s21_set1 = SET_INIT;
    s21::set<int> s21_set2 = {1, 2, 3};
    s21_set1.swap(s21_set2);
    std::set<int> std_set1 = SET_INIT;
    std::set<int> std_set2 = {1, 2, 3};
    std_set1.swap(std_set2);
    ASSERT_TRUE(isSetEqual(std_set1, s21_set1));
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_modifiers_suit, swap_2) {
    s21::set<int> s21_set1 = SET_INIT;
    s21::set<int> s21_set2;
    s21_set1.swap(s21_set2);
    std::set<int> std_set1 = SET_INIT;
    std::set<int> std_set2;
    std_set1.swap(std_set2);
    ASSERT_TRUE(isSetEqual(std_set1, s21_set1));
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_modifiers_suit, swap_3) {
    s21::set<int> s21_set1;
    s21::set<int> s21_set2;
    s21_set1.swap(s21_set2);
    std::set<int> std_set1;
    std::set<int> std_set2;
    std_set1.swap(std_set2);
    ASSERT_TRUE(isSetEqual(std_set1, s21_set1));
    ASSERT_TRUE(isSetEqual(std_set2, s21_set2));
}

TEST(SET_modifiers_suit, merge_1) {
    s21::set<int> s21_set1 = SET_INIT;
    s21::set<int> s21_set2 = {42, 2, 20, 0, 10};
    s21_set1.merge(s21_set2);
    std::set<int> std_set = SET_INIT;
    std_set.insert(42);
    std_set.insert(2);
    std_set.insert(20);
    std_set.insert(0);
    std_set.insert(10);
    ASSERT_TRUE(isSetEqual(std_set, s21_set1));
}

TEST(SET_modifiers_suit, merge_2) {
    s21::set<int> s21_set1 = SET_INIT;
    s21::set<int> s21_set2;
    s21_set1.merge(s21_set2);
    std::set<int> std_set = SET_INIT;
    ASSERT_TRUE(isSetEqual(std_set, s21_set1));
}

TEST(SET_modifiers_suit, merge_3) {
    s21::set<int> s21_set1;
    s21::set<int> s21_set2 = SET_INIT;
    s21_set1.merge(s21_set2);
    std::set<int> std_set = SET_INIT;
    ASSERT_TRUE(isSetEqual(std_set, s21_set1));
}

TEST(SET_modifiers_suit, emplace_1) {
    s21::set<int> m = SET_INIT;
    auto p = m.emplace(6, 42, 100, 4);

    ASSERT_EQ(*p[0].first, 6);
    ASSERT_FALSE(p[0].second);

    ASSERT_EQ(*p[1].first, 42);
    ASSERT_TRUE(p[1].second);

    ASSERT_EQ(*p[2].first, 100);
    ASSERT_TRUE(p[2].second);

    ASSERT_EQ(*p[3].first, 4);
    ASSERT_FALSE(p[3].second);
}

TEST(SET_modifiers_suit, emplace_2) {
    s21::set<int> m;
    auto p = m.emplace(6);

    ASSERT_EQ(*p[0].first, 6);
    ASSERT_TRUE(p[0].second);
}

TEST(SET_modifiers_suit, emplace_3) {
    s21::set<int> m = SET_INIT;
    auto p = m.emplace();
    ASSERT_EQ(p.size(), 0);
}

// LOOKUP

TEST(SET_lookup_suit, find_1) {
    s21::set<int> s = SET_INIT;
    ASSERT_EQ(*s.find(7), 7);
    ASSERT_EQ(s.find(42), s.end());
}

TEST(SET_lookup_suit, find_2) {
    s21::set<int> s;
    ASSERT_EQ(s.find(42), s.end());
}

TEST(SET_lookup_suit, contains_1) {
    s21::set<int> s = SET_INIT;
    ASSERT_TRUE(s.contains(7));
    ASSERT_FALSE(s.contains(42));
    s.erase(s.find(7));
    s.insert(42);
    ASSERT_FALSE(s.contains(7));
    ASSERT_TRUE(s.contains(42));
}

TEST(SET_lookup_suit, contains_2) {
    s21::set<int> s;
    ASSERT_FALSE(s.contains(0));
}
