// #include <vector>
#include <iostream>
#include "vector/vector.tpp"
#include "list/list.tpp"
#include <list>

int main() {
    s21::list<int> a{1,2,3,4,5};
    s21::list<int> b(a);
    // a.push_back(8);
    // s21::list<int> a(b);
    // auto it=a.begin();
    // it++;
    // a.insert(a.begin(),-6);
    // std::cout<<"When using unique\n";
    for (auto i = b.begin(); i != b.end(); ++i) {
        // std::cout<<*i<<std::endl;

        s21::Node_list<int>* val = i.get();
        if (i != b.begin()) {
            std::cout << *(val->prev->data) << "<---" << *i << "--->" << *(val->next->data) << "\n";
        } else {
            std::cout << "     " <<*i << "--->" << *(val->next->data) << "\n";
        }
    }
    std::cout<<"size="<<b.size()<<"|";
    return 0;
}
