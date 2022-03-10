// #include <vector>
#include <iostream>
// #include "vector/vector.tpp"
#include <gtest/gtest.h>

#include <queue>
#include <list>
#include "singly-connect-list/queue/queue.tpp"
#include "singly-connect-list/stack/stack.tpp"
#include "list/list.tpp"


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
    int init[] = {1, 2, 3, 4, 5,0};
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
    std::list<int> b{1, 2, 3, 4, 0, 0};
    std::list<int>::iterator j = b.begin();
    s21::list<int>::iterator i = a.begin();
    (a.erase(i), b.erase(j));
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
