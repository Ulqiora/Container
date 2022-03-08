#include <gtest/gtest.h>

#include <set>
#include <string>

#include "multiset.tpp"

#define MULTISET_INIT {8, 10, 3, 14, 1, 6, 7, 4, 2, 13, 9, 7};

template <class Key, class Traits>
bool isSetEqual(const std::multiset<Key, Traits>& std_mset,
                const s21::multiset<Key, Traits>& s21_mset) {
    // Sizes check
    if (std_mset.size() != s21_mset.size()) return false;
    typename std::multiset<Key, Traits>::iterator std_it = std_mset.begin();
    typename s21::multiset<Key, Traits>::iterator s21_it = s21_mset.begin();
    // Forward bypass
    while (std_it != std_mset.end() || s21_it != s21_mset.end()) {
        if (*std_it != *s21_it) {
            return false;
        }
        ++std_it;
        ++s21_it;
    }
    // Backward bypass
    if (std_mset.size() > 0 && s21_mset.size() > 0) {
        std_it = --std_mset.end();
        s21_it = --s21_mset.end();
        while (std_it != std_mset.begin() || s21_it != s21_mset.begin()) {
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

TEST(constructors_suit, default_constructor) {
    s21::multiset<int> s21_mset;
    std::multiset<int> std_mset;
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(constructors_suit, init_constructor_1) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    std::multiset<int> std_mset = MULTISET_INIT;
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(constructors_suit, init_constructor_2) {
    s21::multiset<int> s21_mset = {1};
    std::multiset<int> std_mset = {1};
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(constructors_suit, init_constructor_3) {
    s21::multiset<std::string> s21_mset = {"Jack", "Scooby", "Rose", "Doo", "Rachel", "Dick"};
    std::multiset<std::string> std_mset = {"Jack", "Scooby", "Rose", "Doo", "Rachel", "Dick"};
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(constructors_suit, init_constructor_4) {
    s21::multiset<int> s21_mset = {};
    std::multiset<int> std_mset = {};
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(constructors_suit, copy_constructor_1) {
    s21::multiset<int> s21_mset1 = MULTISET_INIT;
    s21::multiset<int> s21_mset2 = s21_mset1;
    std::multiset<int> std_mset1 = MULTISET_INIT;
    std::multiset<int> std_mset2 = std_mset1;
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, copy_constructor_2) {
    s21::multiset<int> s21_mset1 = {1};
    s21::multiset<int> s21_mset2 = s21_mset1;
    std::multiset<int> std_mset1 = {1};
    std::multiset<int> std_mset2 = std_mset1;
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, copy_constructor_3) {
    s21::multiset<int> s21_mset1;
    s21::multiset<int> s21_mset2 = s21_mset1;
    std::multiset<int> std_mset1;
    std::multiset<int> std_mset2 = std_mset1;
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, move_constructor_1) {
    s21::multiset<long int> s21_mset1 = MULTISET_INIT;
    s21::multiset<long int> s21_mset2 = std::move(s21_mset1);
    std::multiset<long int> std_mset1 = MULTISET_INIT;
    std::multiset<long int> std_mset2 = std::move(std_mset1);
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, move_constructor_2) {
    s21::multiset<long int> s21_mset1 = {1};
    s21::multiset<long int> s21_mset2 = std::move(s21_mset1);
    std::multiset<long int> std_mset1 = {1};
    std::multiset<long int> std_mset2 = std::move(std_mset1);
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, move_constructor_3) {
    s21::multiset<long int> s21_mset1;
    s21::multiset<long int> s21_mset2 = std::move(s21_mset1);
    std::multiset<long int> std_mset1;
    std::multiset<long int> std_mset2 = std::move(std_mset1);
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, operator_assign_1) {
    s21::multiset<double> s21_mset1 = MULTISET_INIT;
    s21::multiset<double> s21_mset2 = {1, 2, 3};
    s21_mset2 = s21_mset1;
    std::multiset<double> std_mset1 = MULTISET_INIT;
    std::multiset<double> std_mset2 = {1, 2, 3};
    std_mset2 = std_mset1;
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, operator_assign_2) {
    s21::multiset<double> s21_mset1 = {1};
    s21::multiset<double> s21_mset2 = {1, 2, 3};
    s21_mset2 = s21_mset1;
    std::multiset<double> std_mset1 = {1};
    std::multiset<double> std_mset2 = {1, 2, 3};
    std_mset2 = std_mset1;
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, operator_assign_3) {
    s21::multiset<double> s21_mset1;
    s21::multiset<double> s21_mset2 = {1, 2, 3};
    s21_mset2 = s21_mset1;
    std::multiset<double> std_mset1;
    std::multiset<double> std_mset2 = {1, 2, 3};
    std_mset2 = std_mset1;
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(constructors_suit, operator_assign_4) {
    s21::multiset<double> s21_mset = MULTISET_INIT;
    s21_mset = s21_mset;
    std::multiset<double> std_mset = MULTISET_INIT;
    std_mset = std_mset;
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}
// ITERATORS

TEST(iterators_suit, begin_1) {
    s21::multiset<int> s = MULTISET_INIT;
    s21::multiset<int>::iterator it = s.begin();
    ASSERT_EQ(*it, 1);
    ASSERT_EQ(*++it, 2);
}

TEST(iterators_suit, begin_2) {
    s21::multiset<int> s = {42};
    s21::multiset<int>::iterator it = s.begin();
    ASSERT_EQ(*it, 42);
    ASSERT_EQ(++it, s.end());
}

TEST(iterators_suit, begin_3) {
    s21::multiset<int> s;
    s21::multiset<int>::iterator it = s.begin();
    ASSERT_EQ(it, s.end());
}

TEST(iterators_suit, cbegin_1) {
    s21::multiset<int> s = MULTISET_INIT;
    s21::multiset<int>::const_iterator it = s.cbegin();
    ASSERT_EQ(*it, 1);
    ASSERT_EQ(*++it, 2);
}

TEST(iterators_suit, cbegin_2) {
    s21::multiset<int> s = {42};
    s21::multiset<int>::const_iterator it = s.cbegin();
    ASSERT_EQ(*it, 42);
    ASSERT_EQ(++it, s.end());
}

TEST(iterators_suit, cbegin_3) {
    s21::multiset<int> s;
    s21::multiset<int>::const_iterator it = s.cbegin();
    ASSERT_EQ(it, s.end());
}

TEST(iterators_suit, end_1) {
    s21::multiset<int> s = MULTISET_INIT;
    s21::multiset<int>::iterator it = s.end();
    ASSERT_EQ(*--it, 14);
    ASSERT_EQ(*--it, 13);
}

TEST(iterators_suit, end_2) {
    s21::multiset<int> s = {42};
    s21::multiset<int>::iterator it = s.end();
    ASSERT_EQ(*--it, 42);
}

TEST(iterators_suit, end_3) {
    s21::multiset<int> s;
    s21::multiset<int>::iterator it = s.end();
    ASSERT_EQ(it, s.begin());
}

TEST(iterators_suit, cend_1) {
    s21::multiset<int> s = MULTISET_INIT;
    s21::multiset<int>::const_iterator it = s.cend();
    ASSERT_EQ(*--it, 14);
    ASSERT_EQ(*--it, 13);
}

TEST(iterators_suit, cend_2) {
    s21::multiset<int> s = {42};
    s21::multiset<int>::const_iterator it = s.cend();
    ASSERT_EQ(*--it, 42);
}

TEST(iterators_suit, cend_3) {
    s21::multiset<int> s;
    s21::multiset<int>::const_iterator it = s.cend();
    ASSERT_EQ(it, s.begin());
}

// CAPACITY

TEST(capacity_suit, empty_1) {
    s21::multiset<int> s = MULTISET_INIT;
    ASSERT_FALSE(s.empty());
}

TEST(capacity_suit, empty_2) {
    s21::multiset<int> s = {42};
    ASSERT_FALSE(s.empty());
    s.erase(s.begin());
    ASSERT_TRUE(s.empty());
}

TEST(capacity_suit, empty_3) {
    s21::multiset<int> s;
    ASSERT_TRUE(s.empty());
}

TEST(capacity_suit, size_1) {
    s21::multiset<int> s = MULTISET_INIT;
    ASSERT_EQ(s.size(), 12);
    s.erase(s.begin());
    ASSERT_EQ(s.size(), 11);
    s.insert(13);
    ASSERT_EQ(s.size(), 12);
    s.insert(42);
    ASSERT_EQ(s.size(), 13);
}

TEST(capacity_suit, size_2) {
    s21::multiset<int> s = {42};
    ASSERT_EQ(s.size(), 1);
    s.erase(s.begin());
    ASSERT_EQ(s.size(), 0);
    s.insert(42);
    s.insert(21);
    ASSERT_EQ(s.size(), 2);
}

TEST(capacity_suit, max_size) {
    s21::multiset<double> s = MULTISET_INIT;
    size_t real = static_cast<size_t>(
        pow(2, sizeof(void*) * 8) / (sizeof(double) + 3 * sizeof(void*) + 2 * sizeof(bool)) - 1);
    ASSERT_EQ(s.max_size(), real);
}

// MODIFIERS

TEST(modifiers_suit, clear_1) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21_mset.clear();
    std::multiset<int> std_mset = MULTISET_INIT;
    std_mset.clear();
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, clear_2) {
    s21::multiset<int> s21_mset = {42};
    s21_mset.clear();
    std::multiset<int> std_mset = {42};
    std_mset.clear();
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, clear_3) {
    s21::multiset<int> s21_mset;
    s21_mset.clear();
    std::multiset<int> std_mset;
    std_mset.clear();
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, insert) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21_mset.insert(6);
    s21_mset.insert(42);
    s21_mset.insert(100);
    s21_mset.insert(4);
    std::multiset<int> std_mset = MULTISET_INIT;
    std_mset.insert(6);
    std_mset.insert(42);
    std_mset.insert(100);
    std_mset.insert(4);
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, erase_1) {
    s21::multiset<int> s21_mset = {8, 3, 10};
    s21_mset.erase(s21_mset.find(3));
    s21_mset.erase(s21_mset.find(10));
    s21_mset.erase(s21_mset.find(8));
    std::multiset<int> std_mset = {8, 3, 10};
    std_mset.erase(std_mset.find(3));
    std_mset.erase(std_mset.find(10));
    std_mset.erase(std_mset.find(8));
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, erase_2) {
    s21::multiset<int> s21_mset = {8, 3, 6, 1, 0, 4, 5};
    s21_mset.erase(s21_mset.find(1));
    s21_mset.erase(s21_mset.find(6));
    s21_mset.erase(s21_mset.find(8));
    std::multiset<int> std_mset = {8, 3, 6, 1, 0, 4, 5};
    std_mset.erase(std_mset.find(1));
    std_mset.erase(std_mset.find(6));
    std_mset.erase(std_mset.find(8));
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, erase_3) {
    s21::multiset<int> s21_mset = {8, 13, 10, 14, 11, 15, 2};
    s21_mset.erase(s21_mset.find(10));
    s21_mset.erase(s21_mset.find(14));
    s21_mset.erase(s21_mset.find(8));
    std::multiset<int> std_mset = {8, 13, 10, 14, 11, 15, 2};
    std_mset.erase(std_mset.find(10));
    std_mset.erase(std_mset.find(14));
    std_mset.erase(std_mset.find(8));
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, erase_4) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21_mset.erase(s21_mset.find(3));
    s21_mset.erase(s21_mset.find(10));
    s21_mset.erase(s21_mset.find(8));
    std::multiset<int> std_mset = MULTISET_INIT;
    std_mset.erase(std_mset.find(3));
    std_mset.erase(std_mset.find(10));
    std_mset.erase(std_mset.find(8));
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, erase_5) {
    s21::multiset<int> s21_mset = {42};
    s21_mset.erase(s21_mset.find(42));
    std::multiset<int> std_mset = {42};
    std_mset.erase(std_mset.find(42));
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset));
}

TEST(modifiers_suit, swap_1) {
    s21::multiset<int> s21_mset1 = MULTISET_INIT;
    s21::multiset<int> s21_mset2 = {1, 2, 3};
    s21_mset1.swap(s21_mset2);
    std::multiset<int> std_mset1 = MULTISET_INIT;
    std::multiset<int> std_mset2 = {1, 2, 3};
    std_mset1.swap(std_mset2);
    ASSERT_TRUE(isSetEqual(std_mset1, s21_mset1));
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(modifiers_suit, swap_2) {
    s21::multiset<int> s21_mset1 = MULTISET_INIT;
    s21::multiset<int> s21_mset2;
    s21_mset1.swap(s21_mset2);
    std::multiset<int> std_mset1 = MULTISET_INIT;
    std::multiset<int> std_mset2;
    std_mset1.swap(std_mset2);
    ASSERT_TRUE(isSetEqual(std_mset1, s21_mset1));
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(modifiers_suit, swap_3) {
    s21::multiset<int> s21_mset1;
    s21::multiset<int> s21_mset2;
    s21_mset1.swap(s21_mset2);
    std::multiset<int> std_mset1;
    std::multiset<int> std_mset2;
    std_mset1.swap(std_mset2);
    ASSERT_TRUE(isSetEqual(std_mset1, s21_mset1));
    ASSERT_TRUE(isSetEqual(std_mset2, s21_mset2));
}

TEST(modifiers_suit, merge_1) {
    s21::multiset<int> s21_mset1 = MULTISET_INIT;
    s21::multiset<int> s21_mset2 = {42, 2, 20, 0, 10};
    s21_mset1.merge(s21_mset2);
    std::multiset<int> std_mset = MULTISET_INIT;
    std_mset.insert(42);
    std_mset.insert(2);
    std_mset.insert(20);
    std_mset.insert(0);
    std_mset.insert(10);
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset1));
}

TEST(modifiers_suit, merge_2) {
    s21::multiset<int> s21_mset1 = MULTISET_INIT;
    s21::multiset<int> s21_mset2;
    s21_mset1.merge(s21_mset2);
    std::multiset<int> std_mset = MULTISET_INIT;
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset1));
}

TEST(modifiers_suit, merge_3) {
    s21::multiset<int> s21_mset1;
    s21::multiset<int> s21_mset2 = MULTISET_INIT;
    s21_mset1.merge(s21_mset2);
    std::multiset<int> std_mset = MULTISET_INIT;
    ASSERT_TRUE(isSetEqual(std_mset, s21_mset1));
}

// LOOKUP

TEST(lookup_suit, count_1) {
    s21::multiset<int> s = MULTISET_INIT;
    ASSERT_EQ(s.count(7), 2);
    s.insert(7);
    ASSERT_EQ(s.count(7), 3);
    ASSERT_EQ(s.count(13), 1);
    ASSERT_EQ(s.count(42), 0);
}

TEST(lookup_suit, count_2) {
    s21::multiset<int> s;
    ASSERT_EQ(s.count(7), 0);
}

TEST(lookup_suit, find_1) {
    s21::multiset<int> s = MULTISET_INIT;
    ASSERT_EQ(*s.find(7), 7);
    ASSERT_EQ(s.find(42), s.end());
}

TEST(lookup_suit, find_2) {
    s21::multiset<int> s;
    ASSERT_EQ(s.find(42), s.end());
}

TEST(lookup_suit, contains_1) {
    s21::multiset<int> s = MULTISET_INIT;
    ASSERT_TRUE(s.contains(7));
    ASSERT_FALSE(s.contains(42));
    s.erase(s.find(7));
    s.insert(42);
    ASSERT_TRUE(s.contains(7));
    ASSERT_TRUE(s.contains(42));
}

TEST(lookup_suit, contains_2) {
    s21::multiset<int> s;
    ASSERT_FALSE(s.contains(0));
}

TEST(lookup_suit, equal_range_1) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21_mset.insert(7);
    std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> s21_p = s21_mset.equal_range(7);
    std::multiset<int> std_mset = MULTISET_INIT;
    std_mset.insert(7);
    std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> std_p = std_mset.equal_range(7);
    s21::multiset<int>::iterator s21_it = s21_p.first;
    std::multiset<int>::iterator std_it = std_p.first;
    for (; s21_it != s21_p.second && std_it != std_p.second; ++s21_it, ++std_it) {
        ASSERT_EQ(*s21_it, *std_it);
    }
    ASSERT_EQ(*s21_it, *std_it);
}

TEST(lookup_suit, equal_range_2) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> s21_p = s21_mset.equal_range(5);
    std::multiset<int> std_mset = MULTISET_INIT;
    std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> std_p = std_mset.equal_range(5);
    s21::multiset<int>::iterator s21_it = s21_p.first;
    std::multiset<int>::iterator std_it = std_p.first;
    ASSERT_EQ(*s21_it, *std_it);
    ASSERT_EQ(*++s21_it, *++std_it);
}

TEST(lookup_suit, equal_range_3) {
    s21::multiset<int> mset = MULTISET_INIT;
    std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> p = mset.equal_range(42);
    ASSERT_EQ(p.first, mset.end());
}

TEST(lookup_suit, equal_range_4) {
    s21::multiset<int> mset;
    std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> p = mset.equal_range(42);
    ASSERT_EQ(p.first, mset.end());
}

TEST(lookup_suit, lower_bound_1) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21::multiset<int>::iterator s21_it = s21_mset.lower_bound(7);
    std::multiset<int> std_mset = MULTISET_INIT;
    std::multiset<int>::iterator std_it = std_mset.lower_bound(7);
    ASSERT_EQ(*s21_it, *std_it);
}

TEST(lookup_suit, lower_bound_2) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21::multiset<int>::iterator s21_it = s21_mset.lower_bound(5);
    std::multiset<int> std_mset = MULTISET_INIT;
    std::multiset<int>::iterator std_it = std_mset.lower_bound(5);
    ASSERT_EQ(*s21_it, *std_it);
}

TEST(lookup_suit, lower_bound_3) {
    s21::multiset<int> mset = MULTISET_INIT;
    s21::multiset<int>::iterator it = mset.lower_bound(42);
    ASSERT_EQ(it, mset.end());
}

TEST(lookup_suit, lower_bound_4) {
    s21::multiset<int> mset;
    s21::multiset<int>::iterator it = mset.lower_bound(42);
    ASSERT_EQ(it, mset.end());
}

TEST(lookup_suit, upper_bound_1) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21::multiset<int>::iterator s21_it = s21_mset.upper_bound(7);
    std::multiset<int> std_mset = MULTISET_INIT;
    std::multiset<int>::iterator std_it = std_mset.upper_bound(7);
    ASSERT_EQ(*s21_it, *std_it);
}

TEST(lookup_suit, upper_bound_2) {
    s21::multiset<int> s21_mset = MULTISET_INIT;
    s21::multiset<int>::iterator s21_it = s21_mset.upper_bound(5);
    std::multiset<int> std_mset = MULTISET_INIT;
    std::multiset<int>::iterator std_it = std_mset.upper_bound(5);
    ASSERT_EQ(*s21_it, *std_it);
}

TEST(lookup_suit, upper_bound_3) {
    s21::multiset<int> mset = MULTISET_INIT;
    s21::multiset<int>::iterator it = mset.upper_bound(42);
    ASSERT_EQ(it, mset.end());
}

TEST(lookup_suit, upper_bound_4) {
    s21::multiset<int> mset;
    s21::multiset<int>::iterator it = mset.upper_bound(42);
    ASSERT_EQ(it, mset.end());
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
