// #include <vector>
#include <iostream>
// #include "vector/vector.tpp"
#include <gtest/gtest.h>

#include <queue>

#include "singly-connect-list/queue/queue.tpp"
#include "singly-connect-list/stack/stack.tpp"

TEST(stack, constructor1){
    s21::stack<int> a;
    ASSERT_EQ(a.size(),0);
}

TEST(stack, constructor2){
    s21::stack<int> a(5);
    ASSERT_EQ(a.size(),5);
}

TEST(stack, constructor3){
    s21::stack<int> a{1,2,3,4,5};
    int s=a.size();
    ASSERT_EQ(s,5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), 1);
        a.pop();
    }
}

TEST(stack, constructor4){
    s21::stack<int> a{1,2,3,4,5};
    s21::stack<int> b(a);
    ASSERT_EQ(a.size(),b.size());
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), i);
        (a.pop(), b.pop());
    }
}

TEST(stack, constructor5){
    s21::stack<int> a{1,2,3,4,5};
    s21::stack<int> b(std::move(a));
    ASSERT_EQ(a.size(),0);
    ASSERT_EQ(b.size(),5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(stack, constructor6){
    s21::stack<int> a{1,2,3,4,5};
    s21::stack<int> b=std::move(a);
    ASSERT_EQ(a.size(),0);
    ASSERT_EQ(b.size(),5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(stack, front1){
    s21::stack<int> a{1,2,3,4,5};
    ASSERT_EQ(a.front(),5);
}

TEST(stack, front2){
    s21::stack<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(stack, back1){
    s21::stack<int> a{1,2,3,4,5};
    ASSERT_EQ(a.back(),1);
}

TEST(stack, back2){
    s21::stack<int> a;
    ASSERT_ANY_THROW(a.back());
}

TEST(stack, empty1){
    s21::stack<int> a;
    ASSERT_EQ(a.empty(),true);
}

TEST(stack, empty2){
    s21::stack<int> a{1,2,3,4,5};
    ASSERT_EQ(a.empty(),false);
}

TEST(stack, push1){
    s21::stack<int> a;
    a.push(1);
    ASSERT_EQ(a.front(),1);
}

TEST(stack, push2){
    s21::stack<int> a{1,2,3,4,5};
    a.push(9);
    ASSERT_EQ(a.front(),9);
}

TEST(stack, pop1){
    s21::stack<int> a;
    ASSERT_NO_THROW(a.pop());
}

TEST(stack, pop2){
    s21::stack<int> a{1,2,3,4,5};
    a.pop();
    ASSERT_EQ(a.size(),4);
    ASSERT_EQ(a.front(),4);
}

TEST(stack, swap){
    s21::stack<int> a{1,2,3,4,5};
    s21::stack<int> b;
    b.swap(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), i);
        a.pop();
    }
}

TEST(queue, constructor1){
    s21::queue<int> a;
    ASSERT_EQ(a.size(),0);
}

TEST(queue, constructor2){
    s21::queue<int> a(5);
    ASSERT_EQ(a.size(),5);
}

TEST(queue, constructor3){
    s21::queue<int> a{1,2,3,4,5};
    int s=a.size();
    ASSERT_EQ(s,5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), 1);
        a.pop();
    }
}

TEST(queue, constructor4){
    s21::queue<int> a{1,2,3,4,5};
    s21::queue<int> b(a);
    ASSERT_EQ(a.size(),b.size());
    for (int i = 1; i <= 5; ++i) {
        ASSERT_EQ(b.front(), a.front());
        (a.pop(), b.pop());
    }
}

TEST(queue, constructor5){
    s21::queue<int> a{1,2,3,4,5};
    s21::queue<int> b(std::move(a));
    ASSERT_EQ(a.size(),0);
    ASSERT_EQ(b.size(),5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(queue, constructor6){
    s21::queue<int> a{1,2,3,4,5};
    s21::queue<int> b=std::move(a);
    ASSERT_EQ(a.size(),0);
    ASSERT_EQ(b.size(),5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(b.front(), i);
        b.pop();
    }
}

TEST(queue, front1){
    s21::queue<int> a{1,2,3,4,5};
    ASSERT_EQ(a.front(),1);
}

TEST(queue, front2){
    s21::queue<int> a;
    ASSERT_ANY_THROW(a.front());
}

TEST(queue, back1){
    s21::queue<int> a{1,2,3,4,5};
    ASSERT_EQ(a.back(),5);
}

TEST(queue, back2){
    s21::queue<int> a;
    ASSERT_ANY_THROW(a.back());
}

TEST(queue, empty1){
    s21::queue<int> a;
    ASSERT_EQ(a.empty(),true);
}

TEST(queue, empty2){
    s21::queue<int> a{1,2,3,4,5};
    ASSERT_EQ(a.empty(),false);
}

TEST(queue, push1){
    s21::queue<int> a;
    a.push(1);
    ASSERT_EQ(a.front(),1);
}

TEST(queue, push2){
    s21::queue<int> a{1,2,3,4,5};
    a.push(9);
    ASSERT_EQ(a.front(),1);
}

TEST(queue, pop1){
    s21::queue<int> a;
    ASSERT_NO_THROW(a.pop());
}

TEST(queue, pop2){
    s21::queue<int> a{1,2,3,4,5};
    a.pop();
    ASSERT_EQ(a.size(),4);
    ASSERT_EQ(a.front(),2);
}

TEST(queue, swap){
    s21::queue<int> a{1,2,3,4,5};
    s21::queue<int> b;
    b.swap(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 5);
    for (int i = 5; i <= 1; --i) {
        ASSERT_EQ(a.front(), i);
        a.pop();
    }
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
