#include <gtest/gtest.h>

#include <list>

#include "../s21_list.h"

TEST(list, constructor1) {
    std::list<int> a;
    s21::list<int> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(list, constructor2) {
    std::list<int> a(3);
    s21::list<int> b(3);
    ASSERT_EQ(a.size(), b.size());
    std::list<int>::iterator i = a.begin();
    s21::list<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, constructor3) {
    s21::list<int> a{1, 2, 3, 4, 5};
    int init[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(a.size(), 5);
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, constructor4_1) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b(a);
    ASSERT_EQ(a.size(), b.size());
    s21::list<int>::iterator i = a.begin();
    s21::list<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, constructor4_2) {
    s21::list<int> a;
    s21::list<int> b(a);
    ASSERT_EQ(a.size(), b.size());
    s21::list<int>::iterator i = a.begin();
    s21::list<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, constructor5) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b(std::move(a));
    ASSERT_EQ(b.size(), 5);
    ASSERT_EQ(a.size(), 0);
    s21::list<int>::iterator i = b.begin();
    int init[] = {1, 2, 3, 4, 5, 0};
    int* j = init;
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, constructor6) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b = std::move(a);
    ASSERT_EQ(b.size(), 5);
    ASSERT_EQ(a.size(), 0);
    s21::list<int>::iterator i = b.begin();
    int init[] = {1, 2, 3, 4, 5};
    int* j = init;
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, front1) {
    s21::list<int> a{1, 2, 3, 4, 5};
    std::list<int> b{1, 2, 3, 4, 5};
    ASSERT_EQ(a.front(), b.front());
}

TEST(list, front2) {
    s21::list<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(list, back1) {
    s21::list<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(list, back2) {
    s21::list<int> a{1, 2, 3, 4, 5};
    std::list<int> b{1, 2, 3, 4, 5};
    ASSERT_EQ(a.back(), b.back());
}

TEST(list, begin) {
    s21::list<int> a{1, 2, 3, 4, 5};
    std::list<int> b{1, 2, 3, 4, 5};
    std::list<int>::iterator j = b.begin();
    s21::list<int>::iterator i = a.begin();
    ASSERT_EQ(*i, *j);
}

TEST(list, end) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    std::list<int>::iterator j = b.end();
    s21::list<int>::iterator i = a.end();
    (--j, --i);
    ASSERT_EQ(*i, *j);
}

TEST(list, empty1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    ASSERT_EQ(a.empty(), b.empty());
}

TEST(list, empt2) {
    s21::list<int> a;
    std::list<int> b;
    ASSERT_EQ(a.empty(), b.empty());
}

TEST(list, size1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    ASSERT_EQ(a.size(), b.size());
}

TEST(list, size2) {
    s21::list<int> a;
    std::list<int> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(list, size3) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 0};
    ASSERT_NE(a.size(), b.size());
}

TEST(list, clear1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    (a.clear(), b.clear());
    ASSERT_EQ(a.size(), b.size());
}

TEST(list, clear2) {
    s21::list<int> a;
    std::list<int> b;
    (a.clear(), b.clear());
    ASSERT_EQ(a.size(), b.size());
}

TEST(list, insert1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    std::list<int>::iterator j = b.begin();
    s21::list<int>::iterator i = a.begin();
    s21::list<int>::iterator i1 = a.insert(i, 5);
    std::list<int>::iterator j1 = b.insert(j, 5);
    ASSERT_EQ(a.size(), b.size());
    ASSERT_EQ(*i1, *j1);
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, insert2) {
    s21::list<int> a;
    std::list<int> b;
    std::list<int>::iterator j = b.begin();
    s21::list<int>::iterator i = a.begin();
    s21::list<int>::iterator i1 = a.insert(i, 5);
    std::list<int>::iterator j1 = b.insert(j, 5);
    ASSERT_EQ(a.size(), b.size());
    ASSERT_EQ(*i1, *j1);
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, insert3) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    std::list<int>::iterator j = b.begin();
    s21::list<int>::iterator i = a.begin();
    (++i, ++j);
    s21::list<int>::iterator i1 = a.insert(i, 5);
    std::list<int>::iterator j1 = b.insert(j, 5);
    ASSERT_EQ(a.size(), b.size());
    ASSERT_EQ(*i1, *j1);
    (i = a.begin(), j = b.begin());
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, erase1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    s21::list<int> b{2, 3, 4, 0, 0};
    s21::list<int>::iterator j = b.begin();
    s21::list<int>::iterator i = a.begin();
    a.erase(i);
    i = a.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, erase2) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    std::list<int> b{1, 2, 3, 4, 0, 0};
    std::list<int>::iterator j = b.end();
    s21::list<int>::iterator i = a.end();
    (--i, --j);
    (a.erase(i), b.erase(j));
    (i = a.begin(), j = b.begin());
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, push_back1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    a.push_back(9);
    int init[] = {1, 2, 3, 4, 0, 0, 9};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, push_back2) {
    s21::list<int> a;
    a.push_back(9);
    int init[] = {9};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, pop_back1) {
    s21::list<int> a{1, 2, 3, 4, 5};
    a.pop_back();
    int init[] = {1, 2, 3, 4};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, push_front1) {
    s21::list<int> a{1, 2, 3, 4, 0, 0};
    a.push_front(9);
    int init[] = {9, 1, 2, 3, 4, 0, 0};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, push_front2) {
    s21::list<int> a;
    a.push_front(9);
    int init[] = {9};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, pop_front1) {
    s21::list<int> a{1, 2, 3, 4, 5};
    a.pop_front();
    int init[] = {2, 3, 4, 5};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, swap) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b;
    b.swap(a);
    ASSERT_EQ(a.size(), 0);
    int init[] = {1, 2, 3, 4, 5};
    s21::list<int>::iterator i = b.begin();
    int* j = init;
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}
TEST(list, merge) {
    s21::list<int> a{1, 3, 5, 7, 9, 11};
    s21::list<int> b{2, 4, 6, 8, 10, 12, 14};
    s21::list<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14};
    s21::list<int>::const_iterator i = a.cbegin();
    s21::list<int>::const_iterator j = c.cbegin();
    a.merge(b);
    i = a.cbegin();
    ASSERT_EQ(*i, *j);
    while (i != a.cend()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, splice) {
    s21::list<int> a{1, 2, 3, 4, 5, 6};
    s21::list<int> b(a);
    s21::list<int> c{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6};
    s21::list<int>::const_iterator i = a.cbegin();
    s21::list<int>::const_iterator j = b.cbegin();
    a.splice(i, b);
    i = c.cbegin();
    j = b.cbegin();
    while (j != b.cend()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, reverse1) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b{5, 4, 3, 2, 1};
    b.reverse();
    s21::list<int>::iterator i = b.begin();
    s21::list<int>::iterator j = a.begin();
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, reverse2) {
    s21::list<int> a{1, 2, 3, 4, 5, 6};
    s21::list<int> b{6, 5, 4, 3, 2, 1};
    b.reverse();
    s21::list<int>::iterator i = b.begin();
    s21::list<int>::iterator j = a.begin();
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, unique) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    b.unique();
    s21::list<int>::iterator i = b.begin();
    s21::list<int>::iterator j = a.begin();
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, sort) {
    s21::list<int> a{1, 2, 3, 4, 5};
    s21::list<int> b{5, 2, 3, 1, 4};
    b.sort();
    s21::list<int>::iterator i = b.begin();
    s21::list<int>::iterator j = a.begin();
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace1) {
    s21::list<int> a;
    a.emplace(a.begin(), 5, 4, 3, 2, 1);
    ASSERT_EQ(a.size(), 5);
    int init[] = {1, 2, 3, 4, 5};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace2) {
    s21::list<int> a{1, 2, 3};
    a.emplace(a.begin());
    ASSERT_EQ(a.size(), 3);
    int init[] = {1, 2, 3};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace3) {
    s21::list<int> a{1, 2, 3};
    a.emplace(a.begin(), 4, 5);
    ASSERT_EQ(a.size(), 5);
    int init[] = {5, 4, 1, 2, 3};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace_back1) {
    s21::list<int> a;
    a.emplace_back(5, 4, 3, 2, 1);
    ASSERT_EQ(a.size(), 5);
    int init[] = {5, 4, 3, 2, 1};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace_back2) {
    s21::list<int> a{1, 2, 3};
    a.emplace_back();
    ASSERT_EQ(a.size(), 3);
    int init[] = {1, 2, 3};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace_back3) {
    s21::list<int> a{1, 2, 3};
    a.emplace_back(4, 5);
    ASSERT_EQ(a.size(), 5);
    int init[] = {1, 2, 3, 4, 5};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace_front1) {
    s21::list<int> a;
    a.emplace_front(5, 4, 3, 2, 1);
    ASSERT_EQ(a.size(), 5);
    int init[] = {1, 2, 3, 4, 5};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace_front2) {
    s21::list<int> a{1, 2, 3};
    a.emplace_front();
    ASSERT_EQ(a.size(), 3);
    int init[] = {1, 2, 3};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(list, emplace_front3) {
    s21::list<int> a{1, 2, 3};
    a.emplace_front(4, 5);
    ASSERT_EQ(a.size(), 5);
    int init[] = {5, 4, 1, 2, 3};
    s21::list<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}
