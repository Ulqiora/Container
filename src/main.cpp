#include <iostream>
// #include <stack>
#include <vector>
#include "vector/vector.tpp"

int main(){
    using namespace std;
    s21::vector<int> b{1, 2, 3, 4, 5, 6};
    s21::vector<int>::iterator j = b.begin();
    j++;j++;
    s21::vector<int>::iterator j1 = b.insert(j, 5);
    cout<<*j1<<endl;
    j = b.begin();
    s21::vector<int> a{1, 2, 5, 3, 4, 5, 6};
    s21::vector<int>::iterator i = a.begin();
    while (j != b.end()&&i!=a.end()) {
        cout<<*i<<*j<<endl;
        (++i,++j);
    }
    return 0;
}
