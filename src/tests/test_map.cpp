#include <gtest/gtest.h>

#include <map>
#include <string>

#include "../s21_map.h"

typedef std::pair<int, std::string> std_pair_t;

#define MAP_INIT                                                                           \
    {std_pair_t(8, "Finn"),        std_pair_t(10, "Jake"),  std_pair_t(3, "BiMo"),         \
     std_pair_t(14, "Simon"),      std_pair_t(1, "Gunter"), std_pair_t(6, "Marseline"),    \
     std_pair_t(7, "Bonybell"),    std_pair_t(4, "Jimmy"),  std_pair_t(2, "Mint Buttler"), \
     std_pair_t(13, "Lemonsquad"), std_pair_t(9, "Prismo"), std_pair_t(7, "Azriel")};

#define MAP_INIT_2 {std_pair_t(0, "Scooby"), std_pair_t(7, "Dooby"), std_pair_t(42, "Doo")};

template <class Key, class T>
bool isMapEqual(const std::map<Key, T>& std_map, const s21::map<Key, T>& s21_map) {
    // Sizes check
    if (std_map.size() != s21_map.size()) return false;
    typename std::map<Key, T>::const_iterator std_it = std_map.begin();
    typename s21::map<Key, T>::const_iterator s21_it = s21_map.begin();
    // Forward bypass
    while (std_it != std_map.end() || s21_it != s21_map.end()) {
        if ((*std_it).first != (*s21_it).first) {
            return false;
        }
        if ((*std_it).second != (*s21_it).second) {
            return false;
        }
        ++std_it;
        ++s21_it;
    }
    // Backward bypass
    if (std_map.size() > 0 && s21_map.size() > 0) {
        std_it = --std_map.end();
        s21_it = --s21_map.end();
        while (std_it != std_map.begin() || s21_it != s21_map.begin()) {
            if ((*std_it).first != (*s21_it).first) {
                return false;
            }
            if ((*std_it).second != (*s21_it).second) {
                return false;
            }
            --std_it;
            --s21_it;
        }
        if ((*std_it).first != (*s21_it).first) return false;
        if ((*std_it).second != (*s21_it).second) return false;
    }
    return true;
}

// CONSTRUCTORS

TEST(MAP_constructors_suit, default_constructor) {
    s21::map<int, std::string> s21_map;
    std::map<int, std::string> std_map;
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_constructors_suit, init_constructor_1) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    std::map<int, std::string> std_map = MAP_INIT;
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_constructors_suit, init_constructor_2) {
    s21::map<int, std::string> s21_map = {std_pair_t(1, "One")};
    std::map<int, std::string> std_map = {std_pair_t(1, "One")};
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_constructors_suit, init_constructor_3) {
    s21::map<double, std::string> s21_map = {std::pair<double, std::string>(1.0, "Scooby"),
                                             std::pair<double, std::string>(0.42, "Doo")};
    std::map<double, std::string> std_map = {std::pair<double, std::string>(1.0, "Scooby"),
                                             std::pair<double, std::string>(0.42, "Doo")};
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_constructors_suit, init_constructor_4) {
    s21::map<int, std::string> s21_map = {};
    std::map<int, std::string> std_map = {};
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_constructors_suit, copy_constructor_1) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2 = s21_map1;
    std::map<int, std::string> std_map1 = MAP_INIT;
    std::map<int, std::string> std_map2 = std_map1;
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, copy_constructor_2) {
    s21::map<int, std::string> s21_map1 = {std_pair_t(1, "One")};
    s21::map<int, std::string> s21_map2 = s21_map1;
    std::map<int, std::string> std_map1 = {std_pair_t(1, "One")};
    std::map<int, std::string> std_map2 = std_map1;
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, copy_constructor_3) {
    s21::map<int, std::string> s21_map1;
    s21::map<int, std::string> s21_map2 = s21_map1;
    std::map<int, std::string> std_map1;
    std::map<int, std::string> std_map2 = std_map1;
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, move_constructor_1) {
    s21::map<long int, std::string> s21_map1 = {std_pair_t(1, "One")};
    s21::map<long int, std::string> s21_map2 = std::move(s21_map1);
    std::map<long int, std::string> std_map1 = {std_pair_t(1, "One")};
    std::map<long int, std::string> std_map2 = std::move(std_map1);
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, move_constructor_2) {
    s21::map<long int, std::string> s21_map1;
    s21::map<long int, std::string> s21_map2 = std::move(s21_map1);
    std::map<long int, std::string> std_map1;
    std::map<long int, std::string> std_map2 = std::move(std_map1);
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_copy_1) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map2 = s21_map1;
    std::map<int, std::string> std_map1 = MAP_INIT;
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map2 = std_map1;
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_copy_2) {
    s21::map<int, std::string> s21_map1 = {std_pair_t(1, "One")};
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map2 = s21_map1;
    std::map<int, std::string> std_map1 = {std_pair_t(1, "One")};
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map2 = std_map1;
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_copy_3) {
    s21::map<int, std::string> s21_map1;
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map2 = s21_map1;
    std::map<int, std::string> std_map1;
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map2 = std_map1;
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_copy_4) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    s21_map = s21_map;
    std::map<int, std::string> std_map = MAP_INIT;
    std_map = std_map;
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_constructors_suit, operator_assign_move_1) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map2 = std::move(s21_map1);
    std::map<int, std::string> std_map1 = MAP_INIT;
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map2 = std::move(std_map1);
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_move_2) {
    s21::map<int, std::string> s21_map1 = {std_pair_t(1, "One")};
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map2 = std::move(s21_map1);
    std::map<int, std::string> std_map1 = {std_pair_t(1, "One")};
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map2 = std::move(std_map1);
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_move_3) {
    s21::map<int, std::string> s21_map1;
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map2 = std::move(s21_map1);
    std::map<int, std::string> std_map1;
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map2 = std::move(std_map1);
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_constructors_suit, operator_assign_move_4) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    s21_map = std::move(s21_map);
    std::map<int, std::string> std_map = MAP_INIT;
    std_map = std::move(std_map);
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

// ITERATORS

TEST(MAP_iterators_suit, begin_1) {
    s21::map<int, std::string> s = MAP_INIT;
    s21::map<int, std::string>::iterator it = s.begin();
    ASSERT_EQ((*it).first, 1);
    ASSERT_EQ((*++it).first, 2);
}

TEST(MAP_iterators_suit, begin_2) {
    s21::map<int, std::string> s = {std_pair_t(1, "One")};
    s21::map<int, std::string>::iterator it = s.begin();
    ASSERT_EQ((*it).first, 1);
    ASSERT_EQ(++it, s.end());
}

TEST(MAP_iterators_suit, begin_3) {
    s21::map<int, std::string> s;
    s21::map<int, std::string>::iterator it = s.begin();
    ASSERT_EQ(it, s.end());
}

TEST(MAP_iterators_suit, cbegin_1) {
    s21::map<int, std::string> s = MAP_INIT;
    s21::map<int, std::string>::const_iterator it = s.cbegin();
    ASSERT_EQ((*it).first, 1);
    ASSERT_EQ((*++it).first, 2);
}

TEST(MAP_iterators_suit, cbegin_2) {
    s21::map<int, std::string> s = {std_pair_t(1, "One")};
    s21::map<int, std::string>::const_iterator it = s.cbegin();
    ASSERT_EQ((*it).first, 1);
    ASSERT_EQ(++it, s.end());
}

TEST(MAP_iterators_suit, cbegin_3) {
    s21::map<int, std::string> s;
    s21::map<int, std::string>::const_iterator it = s.cbegin();
    ASSERT_EQ(it, s.end());
}

TEST(MAP_iterators_suit, end_1) {
    s21::map<int, std::string> s = MAP_INIT;
    s21::map<int, std::string>::iterator it = s.end();
    ASSERT_EQ((*--it).first, 14);
    ASSERT_EQ((*--it).first, 13);
}

TEST(MAP_iterators_suit, end_2) {
    s21::map<int, std::string> s = {std_pair_t(1, "One")};
    s21::map<int, std::string>::iterator it = s.end();
    ASSERT_EQ((*--it).first, 1);
}

TEST(MAP_iterators_suit, end_3) {
    s21::map<int, std::string> s;
    s21::map<int, std::string>::iterator it = s.end();
    ASSERT_EQ(it, s.begin());
}

TEST(MAP_iterators_suit, cend_1) {
    s21::map<int, std::string> s = MAP_INIT;
    s21::map<int, std::string>::const_iterator it = s.cend();
    ASSERT_EQ((*--it).first, 14);
    ASSERT_EQ((*--it).first, 13);
}

TEST(MAP_iterators_suit, cend_2) {
    s21::map<int, std::string> s = {std_pair_t(1, "One")};
    s21::map<int, std::string>::const_iterator it = s.cend();
    ASSERT_EQ((*--it).first, 1);
}

TEST(MAP_iterators_suit, cend_3) {
    s21::map<int, std::string> s;
    s21::map<int, std::string>::const_iterator it = s.cend();
    ASSERT_EQ(it, s.begin());
}

// CAPACITY

TEST(MAP_capacity_suit, empty_1) {
    s21::map<int, std::string> s = MAP_INIT;
    ASSERT_FALSE(s.empty());
}

TEST(MAP_capacity_suit, empty_2) {
    s21::map<int, std::string> s = {std_pair_t(1, "One")};
    ASSERT_FALSE(s.empty());
    s.erase(s.begin());
    ASSERT_TRUE(s.empty());
}

TEST(MAP_capacity_suit, empty_3) {
    s21::map<int, std::string> s;
    ASSERT_TRUE(s.empty());
}

TEST(MAP_capacity_suit, size_1) {
    s21::map<int, std::string> s = MAP_INIT;
    ASSERT_EQ(s.size(), 11);
    s.erase(s.begin());
    ASSERT_EQ(s.size(), 10);
    s.insert(13, "Gabriel");
    ASSERT_EQ(s.size(), 10);
    s.insert(42, "Ice King");
    ASSERT_EQ(s.size(), 11);
}

TEST(MAP_capacity_suit, size_2) {
    s21::map<int, std::string> s = {std_pair_t(1, "One")};
    ASSERT_EQ(s.size(), 1);
    s.erase(s.begin());
    ASSERT_EQ(s.size(), 0);
    s.insert(42, "Gabriel");
    s.insert(21, "Ice King");
    ASSERT_EQ(s.size(), 2);
}

TEST(MAP_capacity_suit, max_size) {
    s21::map<int, std::string> s = MAP_INIT;
    size_t real = static_cast<size_t>(pow(2, sizeof(void*) * 8) / (sizeof(std::pair<int, std::string>) +
                                                                   3 * sizeof(void*) + 2 * sizeof(bool)) -
                                      1);
    ASSERT_EQ(s.max_size(), real);
}

// ELEMENT ACCESS

TEST(MAP_element_access_suit, at_1) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    std::map<int, std::string> std_map = MAP_INIT;
    ASSERT_THROW(s21_map.at(0), std::out_of_range);
    ASSERT_EQ(s21_map.at(1), std_map.at(1));
    ASSERT_EQ(s21_map.at(7), std_map.at(7));
    ASSERT_THROW(s21_map.at(42), std::out_of_range);
}

TEST(MAP_element_access_suit, at_2) {
    s21::map<int, std::string> s21_map = {std_pair_t(1, "One")};
    std::map<int, std::string> std_map = {std_pair_t(1, "One")};
    ASSERT_EQ(s21_map.at(1), std_map.at(1));
    s21_map.erase(s21_map.begin());
    ASSERT_THROW(s21_map.at(1), std::out_of_range);
}

TEST(MAP_modifiers_suit, operator_sqr_braces_1) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    s21_map[6] = "Fire Princess";
    s21_map[42] = "Ice King";
    s21_map[100] = "Jeffry";
    s21_map[4] = "Buble Gum";
    std::map<int, std::string> std_map = MAP_INIT;
    std_map[6] = "Fire Princess";
    std_map[42] = "Ice King";
    std_map[100] = "Jeffry";
    std_map[4] = "Buble Gum";
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, operator_sqr_braces_2) {
    s21::map<int, std::string> s21_map;
    s21_map[6] = "Fire Princess";
    s21_map[42] = "Ice King";
    s21_map[100] = "Jeffry";
    s21_map[42] = "Buble Gum";
    std::map<int, std::string> std_map;
    std_map[6] = "Fire Princess";
    std_map[42] = "Ice King";
    std_map[100] = "Jeffry";
    std_map[42] = "Buble Gum";
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

// MODIFIERS

TEST(MAP_modifiers_suit, clear_1) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    s21_map.clear();
    std::map<int, std::string> std_map = MAP_INIT;
    std_map.clear();
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, clear_2) {
    s21::map<int, std::string> s21_map = {std_pair_t(1, "One")};
    s21_map.clear();
    std::map<int, std::string> std_map = {std_pair_t(1, "One")};
    std_map.clear();
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, clear_3) {
    s21::map<int, std::string> s21_map;
    s21_map.clear();
    std::map<int, std::string> std_map;
    std_map.clear();
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, insert_1) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    std::pair<s21::map<int, std::string>::iterator, bool> p;
    p = s21_map.insert(std_pair_t(6, "Fire Princess"));
    ASSERT_EQ((*p.first).first, 6);
    ASSERT_EQ((*p.first).second, "Marseline");
    ASSERT_FALSE(p.second);
    p = s21_map.insert(std_pair_t(42, "Ice King"));
    ASSERT_EQ((*p.first).first, 42);
    ASSERT_EQ((*p.first).second, "Ice King");
    ASSERT_TRUE(p.second);
    p = s21_map.insert(std_pair_t(100, "Fire Princess"));
    ASSERT_EQ((*p.first).first, 100);
    ASSERT_EQ((*p.first).second, "Fire Princess");
    ASSERT_TRUE(p.second);
    p = s21_map.insert(std_pair_t(4, "Buble Gum"));
    ASSERT_EQ((*p.first).first, 4);
    ASSERT_EQ((*p.first).second, "Jimmy");
    ASSERT_FALSE(p.second);
    std::map<int, std::string> std_map = MAP_INIT;
    std_map.insert(std_pair_t(6, "Fire Princess"));
    std_map.insert(std_pair_t(42, "Ice King"));
    std_map.insert(std_pair_t(100, "Fire Princess"));
    std_map.insert(std_pair_t(4, "Buble Gum"));
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, insert_2) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    std::pair<s21::map<int, std::string>::iterator, bool> p;
    p = s21_map.insert(6, "Fire Princess");
    ASSERT_EQ((*p.first).first, 6);
    ASSERT_EQ((*p.first).second, "Marseline");
    ASSERT_FALSE(p.second);
    p = s21_map.insert(42, "Ice King");
    ASSERT_EQ((*p.first).first, 42);
    ASSERT_EQ((*p.first).second, "Ice King");
    ASSERT_TRUE(p.second);
    p = s21_map.insert(100, "Fire Princess");
    ASSERT_EQ((*p.first).first, 100);
    ASSERT_EQ((*p.first).second, "Fire Princess");
    ASSERT_TRUE(p.second);
    p = s21_map.insert(4, "Buble Gum");
    ASSERT_EQ((*p.first).first, 4);
    ASSERT_EQ((*p.first).second, "Jimmy");
    ASSERT_FALSE(p.second);
    std::map<int, std::string> std_map = MAP_INIT;
    std_map.insert(std_pair_t(6, "Fire Princess"));
    std_map.insert(std_pair_t(42, "Ice King"));
    std_map.insert(std_pair_t(100, "Fire Princess"));
    std_map.insert(std_pair_t(4, "Buble Gum"));
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, insert_3) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    std::pair<s21::map<int, std::string>::iterator, bool> p;
    p = s21_map.insert_or_assign(6, "Fire Princess");
    ASSERT_EQ((*p.first).first, 6);
    ASSERT_EQ((*p.first).second, "Fire Princess");
    ASSERT_FALSE(p.second);
    p = s21_map.insert_or_assign(42, "Ice King");
    ASSERT_EQ((*p.first).first, 42);
    ASSERT_EQ((*p.first).second, "Ice King");
    ASSERT_TRUE(p.second);
    p = s21_map.insert_or_assign(100, "Scooby Doo");
    ASSERT_EQ((*p.first).first, 100);
    ASSERT_EQ((*p.first).second, "Scooby Doo");
    ASSERT_TRUE(p.second);
    p = s21_map.insert_or_assign(4, "Buble Gum");
    ASSERT_EQ((*p.first).first, 4);
    ASSERT_EQ((*p.first).second, "Buble Gum");
    ASSERT_FALSE(p.second);
}

TEST(MAP_modifiers_suit, erase) {
    s21::map<int, std::string> s21_map = MAP_INIT;
    s21_map.erase(s21_map.begin());
    s21_map.erase(--(s21_map.end()));
    s21_map.erase(++s21_map.begin());
    std::map<int, std::string> std_map = MAP_INIT;
    std_map.erase(std_map.begin());
    std_map.erase(--(std_map.end()));
    std_map.erase(++std_map.begin());
    ASSERT_TRUE(isMapEqual(std_map, s21_map));
}

TEST(MAP_modifiers_suit, swap_1) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map1.swap(s21_map2);
    std::map<int, std::string> std_map1 = MAP_INIT;
    std::map<int, std::string> std_map2 = MAP_INIT_2;
    std_map1.swap(std_map2);
    ASSERT_TRUE(isMapEqual(std_map1, s21_map1));
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_modifiers_suit, swap_2) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2;
    s21_map1.swap(s21_map2);
    std::map<int, std::string> std_map1 = MAP_INIT;
    std::map<int, std::string> std_map2;
    std_map1.swap(std_map2);
    ASSERT_TRUE(isMapEqual(std_map1, s21_map1));
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_modifiers_suit, swap_3) {
    s21::map<int, std::string> s21_map1;
    s21::map<int, std::string> s21_map2;
    s21_map1.swap(s21_map2);
    std::map<int, std::string> std_map1;
    std::map<int, std::string> std_map2;
    std_map1.swap(std_map2);
    ASSERT_TRUE(isMapEqual(std_map1, s21_map1));
    ASSERT_TRUE(isMapEqual(std_map2, s21_map2));
}

TEST(MAP_modifiers_suit, merge_1) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2 = MAP_INIT_2;
    s21_map1.merge(s21_map2);
    std::map<int, std::string> std_map = MAP_INIT;
    std_map.insert(std_pair_t(0, "Scooby"));
    std_map.insert(std_pair_t(7, "Dooby"));
    std_map.insert(std_pair_t(42, "Doo"));
    ASSERT_TRUE(isMapEqual(std_map, s21_map1));
}

TEST(MAP_modifiers_suit, merge_2) {
    s21::map<int, std::string> s21_map1 = MAP_INIT;
    s21::map<int, std::string> s21_map2;
    s21_map1.merge(s21_map2);
    std::map<int, std::string> std_map = MAP_INIT;
    ASSERT_TRUE(isMapEqual(std_map, s21_map1));
}

TEST(MAP_modifiers_suit, merge_3) {
    s21::map<int, std::string> s21_map1;
    s21::map<int, std::string> s21_map2 = MAP_INIT;
    s21_map1.merge(s21_map2);
    std::map<int, std::string> std_map = MAP_INIT;
    ASSERT_TRUE(isMapEqual(std_map, s21_map1));
}

TEST(MAP_modifiers_suit, emplace_1) {
    s21::map<int, std::string> m = MAP_INIT;
    auto p = m.emplace(std_pair_t(6, "Fire Princess"), std_pair_t(42, "Ice King"),
                       std_pair_t(100, "Fire Princess"), std_pair_t(4, "Buble Gum"));

    ASSERT_EQ((*p[0].first).first, 6);
    ASSERT_EQ((*p[0].first).second, "Marseline");
    ASSERT_FALSE(p[0].second);

    ASSERT_EQ((*p[1].first).first, 42);
    ASSERT_EQ((*p[1].first).second, "Ice King");
    ASSERT_TRUE(p[1].second);

    ASSERT_EQ((*p[2].first).first, 100);
    ASSERT_EQ((*p[2].first).second, "Fire Princess");
    ASSERT_TRUE(p[2].second);

    ASSERT_EQ((*p[3].first).first, 4);
    ASSERT_EQ((*p[3].first).second, "Jimmy");
    ASSERT_FALSE(p[3].second);
}

TEST(MAP_modifiers_suit, emplace_2) {
    s21::map<int, std::string> m;
    auto p = m.emplace(std_pair_t(6, "Fire Princess"));

    ASSERT_EQ((*p[0].first).first, 6);
    ASSERT_EQ((*p[0].first).second, "Fire Princess");
    ASSERT_TRUE(p[0].second);
}

TEST(MAP_modifiers_suit, emplace_3) {
    s21::map<int, std::string> m = MAP_INIT;
    auto p = m.emplace();
    ASSERT_EQ(p.size(), 0);
}

// LOOKUP

TEST(MAP_lookup_suit, contains_1) {
    s21::map<int, std::string> s = MAP_INIT;
    ASSERT_TRUE(s.contains(1));
    ASSERT_FALSE(s.contains(42));
    s.erase(s.begin());
    s.insert(42, "Scooby Doo");
    ASSERT_TRUE(s.contains(7));
    ASSERT_TRUE(s.contains(42));
}

TEST(MAP_lookup_suit, contains_2) {
    s21::map<int, std::string> s;
    ASSERT_FALSE(s.contains(0));
}
