#include <iostream>
#include <queue>
#include <stack>

int main(){
    std::stack<int> a;
    a.push(3);
    std::cout << a.size() << std::endl;
    a.pop();
    std::cout << a.size() << std::endl;
}