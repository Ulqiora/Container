#include <vector>
#include <gtest/gtest.h>
#include "../vector/vector.tpp"

TEST(vector, constructor1) {
    std::vector<int> a;
    s21::vector<int> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(vector, constructor2) {
    std::vector<int> a(3);
    s21::vector<int> b(3);
    ASSERT_EQ(a.size(), b.size());
    std::vector<int>::iterator i = a.begin();
    s21::vector<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, constructor3) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    int init[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(a.size(), 5);
    s21::vector<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, constructor4_1) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    s21::vector<int> b(a);
    ASSERT_EQ(a.size(), b.size());
    s21::vector<int>::iterator i = a.begin();
    s21::vector<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, constructor4_2) {
    s21::vector<int> a;
    s21::vector<int> b(a);
    ASSERT_EQ(a.size(), b.size());
    s21::vector<int>::iterator i = a.begin();
    s21::vector<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, constructor5) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    s21::vector<int> b(std::move(a));
    ASSERT_EQ(b.size(), 5);
    ASSERT_EQ(a.size(), 0);
    s21::vector<int>::iterator i = b.begin();
    int init[] = {1, 2, 3, 4, 5};
    int* j = init;
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, constructor6) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    s21::vector<int> b = std::move(a);
    ASSERT_EQ(b.size(), 5);
    ASSERT_EQ(a.size(), 0);
    s21::vector<int>::iterator i = b.begin();
    int init[] = {1, 2, 3, 4, 5};
    int* j = init;
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, front1) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{1, 2, 3, 4, 5};
    ASSERT_EQ(a.front(), b.front());
}

TEST(vector, front2) {
    s21::vector<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(vector, back1) {
    s21::vector<int> a;
    ASSERT_ANY_THROW(a.back());
}

TEST(vector, back2) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{1, 2, 3, 4, 5};
    ASSERT_EQ(a.back(), b.back());
}

TEST(vector, begin) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{1, 2, 3, 4, 5};
    std::vector<int>::iterator j = b.begin();
    s21::vector<int>::iterator i = a.begin();
    ASSERT_EQ(*i, *j);
}

TEST(vector, end) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 3, 4, 0, 0};
    std::vector<int>::iterator j = b.end();
    s21::vector<int>::iterator i = a.end();
    (--j, --i);
    ASSERT_EQ(*i, *j);
}

TEST(vector, empty1) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 3, 4, 0, 0};
    ASSERT_EQ(a.empty(), b.empty());
}

TEST(vector, empt2) {
    s21::vector<int> a;
    std::vector<int> b;
    ASSERT_EQ(a.empty(), b.empty());
}

TEST(vector, size1) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 3, 4, 0, 0};
    ASSERT_EQ(a.size(), b.size());
}

TEST(vector, size2) {
    s21::vector<int> a;
    std::vector<int> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(vector, size3) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 0};
    ASSERT_NE(a.size(), b.size());
}

TEST(vector, clear1) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 3, 4, 0, 0};
    (a.clear(), b.clear());
    ASSERT_EQ(a.size(), b.size());
}

TEST(vector, clear2) {
    s21::vector<int> a;
    std::vector<int> b;
    (a.clear(), b.clear());
    ASSERT_EQ(a.size(), b.size());
}

TEST(vector, insert1) {
    s21::vector<int> b{1, 2, 3, 4, 5, 6};
    s21::vector<int>::iterator j = b.begin();
    s21::vector<int>::iterator j1 = b.insert(j, 5);
    ASSERT_EQ(*j1,5);
    j = b.begin();
    s21::vector<int> a{5, 1, 2, 3, 4, 5, 6};
    s21::vector<int>::iterator i = a.begin();
    while (j != b.end()&&i!=a.end()) {
        ASSERT_EQ(*i,*j);
        (++i,++j);
    }
}

TEST(vector, insert2) {
    s21::vector<int> a;
    std::vector<int> b;
    std::vector<int>::iterator j = b.begin();
    s21::vector<int>::iterator i = a.begin();
    s21::vector<int>::iterator i1 = a.insert(i, 5);
    std::vector<int>::iterator j1 = b.insert(j, 5);
    ASSERT_EQ(a.size(), b.size());
    ASSERT_EQ(*i1, *j1);
    j = b.begin();
    i = a.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, insert3) {
    s21::vector<int> a{1, 2, 3, 4, 5, 6};
    s21::vector<int>::iterator i = a.begin();
    ++i;
    s21::vector<int>::iterator i1 = a.insert(i, 5);
    ASSERT_EQ(a.size(),7);
    ASSERT_EQ(*i1, 5);
    i = a.begin();
    s21::vector<int> b{1, 5, 2, 3, 4, 5, 6};
    s21::vector<int>::iterator j = b.begin();
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, erase1) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 3, 4, 0, 0};
    std::vector<int>::iterator j = b.begin();
    s21::vector<int>::iterator i = a.begin();
    (a.erase(i), b.erase(j));
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, erase2) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    std::vector<int> b{1, 2, 3, 4, 0, 0};
    std::vector<int>::iterator j = b.end();
    s21::vector<int>::iterator i = a.end();
    (--i, --j);
    (a.erase(i), b.erase(j));
    (i = a.begin(), j = b.begin());
    while (i != a.end() && j != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, push_back1) {
    s21::vector<int> a{1, 2, 3, 4, 0, 0};
    a.push_back(9);
    int init[] = {1, 2, 3, 4, 0, 0, 9};
    s21::vector<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, push_back2) {
    s21::vector<int> a;
    a.push_back(9);
    int init[] = {9};
    s21::vector<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, pop_back1) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    a.pop_back();
    int init[] = {1, 2, 3, 4};
    s21::vector<int>::iterator i = a.begin();
    int* j = init;
    while (i != a.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}

TEST(vector, swap) {
    s21::vector<int> a{1, 2, 3, 4, 5};
    s21::vector<int> b;
    b.swap(a);
    ASSERT_EQ(a.size(), 0);
    int init[] = {1, 2, 3, 4, 5};
    s21::vector<int>::iterator i = b.begin();
    int* j = init;
    while (i != b.end()) {
        ASSERT_EQ(*i, *j);
        (++i, ++j);
    }
}