#include <gtest/gtest.h>

#include <stack>

#include "../s21_stack.h"

TEST(stack, constructor1) {
    s21::stack<int> a;
    ASSERT_EQ(a.size(), 0);
}

TEST(stack, constructor2) {
    s21::stack<int> a(5);
    ASSERT_EQ(a.size(), 5);
}

TEST(stack, constructor3) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    int s = a.size();
    ASSERT_EQ(s, 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), 1);
        a.pop();
    }
}

TEST(stack, constructor4) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    s21::stack<int> b(a);
    ASSERT_EQ(a.size(), b.size());
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), i);
        (a.pop(), b.pop());
    }
}

TEST(stack, constructor5) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    s21::stack<int> b(std::move(a));
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(stack, constructor6) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    s21::stack<int> b = std::move(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(stack, front1) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(a.front(), 5);
}

TEST(stack, front2) {
    s21::stack<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(stack, back1) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(a.back(), 1);
}

TEST(stack, back2) {
    s21::stack<int> a;
    ASSERT_ANY_THROW(a.back());
}

TEST(stack, empty1) {
    s21::stack<int> a;
    ASSERT_EQ(a.empty(), true);
}

TEST(stack, empty2) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(a.empty(), false);
}

TEST(stack, push1) {
    s21::stack<int> a;
    a.push(1);
    ASSERT_EQ(a.front(), 1);
}

TEST(stack, push2) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    a.push(9);
    ASSERT_EQ(a.front(), 9);
}

TEST(stack, pop1) {
    s21::stack<int> a;
    ASSERT_NO_THROW(a.pop());
}

TEST(stack, pop2) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    a.pop();
    ASSERT_EQ(a.size(), 4);
    ASSERT_EQ(a.front(), 4);
}

TEST(stack, swap) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    s21::stack<int> b;
    b.swap(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), i);
        a.pop();
    }
}

TEST(stack, emplace_front1) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    a.emplace_front(1, 2, 3);
    ASSERT_EQ(a.size(), 8);
    int init[] = {3, 2, 1, 5, 4, 3, 2, 1};
    int* j = init;
    while (a.size() != 0) {
        ASSERT_EQ(a.front(), *j);
        (a.pop(), ++j);
    }
}

TEST(stack, emplace_front2) {
    s21::stack<int> a{1, 2, 3, 4, 5};
    a.emplace_front();
    ASSERT_EQ(a.size(), 5);
    int init[] = {5, 4, 3, 2, 1};
    int* j = init;
    while (a.size() != 0) {
        ASSERT_EQ(a.front(), *j);
        (a.pop(), ++j);
    }
}

TEST(stack, emplace_front3) {
    s21::stack<int> a;
    a.emplace_front(1, 2, 3);
    ASSERT_EQ(a.size(), 3);
    int init[] = {3, 2, 1};
    int* j = init;
    while (a.size() != 0) {
        ASSERT_EQ(a.front(), *j);
        (a.pop(), ++j);
    }
}
