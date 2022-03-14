#include <gtest/gtest.h>

#include <queue>

#include "../s21_queue.h"

TEST(queue, constructor1) {
    s21::queue<int> a;
    ASSERT_EQ(a.size(), 0);
}

TEST(queue, constructor2) {
    s21::queue<int> a(5);
    ASSERT_EQ(a.size(), 5);
}

TEST(queue, constructor3) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    int s = a.size();
    ASSERT_EQ(s, 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), 1);
        a.pop();
    }
}

TEST(queue, constructor4) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    s21::queue<int> b(a);
    ASSERT_EQ(a.size(), b.size());
    for (int i = 1; i <= 5; ++i) {
        ASSERT_EQ(b.front(), a.front());
        (a.pop(), b.pop());
    }
}

TEST(queue, constructor5) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    s21::queue<int> b(std::move(a));
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(queue, constructor6) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    s21::queue<int> b = std::move(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(queue, front1) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(a.front(), 1);
}

TEST(queue, front2) {
    s21::queue<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(queue, back1) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(a.back(), 5);
}

TEST(queue, back2) {
    s21::queue<int> a;
    ASSERT_ANY_THROW(a.back());
}

TEST(queue, empty1) {
    s21::queue<int> a;
    ASSERT_EQ(a.empty(), true);
}

TEST(queue, empty2) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(a.empty(), false);
}

TEST(queue, push1) {
    s21::queue<int> a;
    a.push(1);
    ASSERT_EQ(a.front(), 1);
}

TEST(queue, push2) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    a.push(9);
    ASSERT_EQ(a.front(), 1);
}

TEST(queue, pop1) {
    s21::queue<int> a;
    ASSERT_NO_THROW(a.pop());
}

TEST(queue, pop2) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    a.pop();
    ASSERT_EQ(a.size(), 4);
    ASSERT_EQ(a.front(), 2);
}

TEST(queue, swap) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    s21::queue<int> b;
    b.swap(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), i);
        a.pop();
    }
}

TEST(queue, emplace_back1) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    a.emplace_back(1, 2, 3);
    ASSERT_EQ(a.size(), 8);
    int init[] = {1, 2, 3, 4, 5, 1, 2, 3};
    int* j = init;
    while (a.size() != 0) {
        ASSERT_EQ(a.front(), *j);
        (a.pop(), ++j);
    }
}

TEST(queue, emplace_back2) {
    s21::queue<int> a{1, 2, 3, 4, 5};
    a.emplace_back();
    ASSERT_EQ(a.size(), 5);
    int init[] = {1, 2, 3, 4, 5};
    int* j = init;
    while (a.size() != 0) {
        ASSERT_EQ(a.front(), *j);
        (a.pop(), ++j);
    }
}

TEST(queue, emplace_back3) {
    s21::queue<int> a;
    a.emplace_back(1, 2, 3);
    ASSERT_EQ(a.size(), 3);
    int init[] = {1, 2, 3};
    int* j = init;
    while (a.size() != 0) {
        ASSERT_EQ(a.front(), *j);
        (a.pop(), ++j);
    }
}
