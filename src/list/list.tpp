#include "list.hpp"

namespace s21 {
    template<class Type_list>
    list<Type_list>::list():size_(0),head_(nullptr){}

    template<class Type_list>
    list<Type_list>::list(size_type n):size_(n){
        head_=new Node_list<Type_list>(nullptr,nullptr); 
        Node_list<Type_list>* current=head_;
        for(size_type i=1;i<n;i++){
            current->next=new Node_list<Type_list>(nullptr,current);
            current=current->next;
        }
    }

    template <class Type_list>
    list<Type_list>::list(std::initializer_list<Type_list> const& items) : size_(items.size()) {
        head_ = new Node_list<Type_list>(nullptr, nullptr, *(items.begin()));
        Node_list<Type_list>* current = head_;
        for (auto i = items.begin(); i != items.end; ++i) {
            if (i != items.begin()) {
                current->next = new Node_list<Type_list>(nullptr, current, i->data);
                current = current->next;
            }
        }
    }

    template<class Type_list>
    list<Type_list>::list(const list<Type_list>& v){
        head_ = new Node_list<Type_list>(nullptr, nullptr, *(v.begincbegin()));
        Node_list<Type_list>* current_this = head_;
        for (auto i = v.begincbegin(); i != v.endcend(); ++i) {
            if (i != v.begincbegin()) {
                current_this = new Node_list<Type_list>(nullptr, current_this, i->data);
                current_this = current_this->next;
            }
        }
    }

    template <class Type_list>
    list<Type_list>::list(list<Type_list>&& v) {
        head_ = v.head_;
        size_ = v.size_;
        v.size_ = 0;
        v.head_ = NULL;
    }

    template <class Type_list>
    list<Type_list>::~list(){}

    template<class Type_list>
    typename list<Type_list>& list<Type_list>::operator=(list&& v){
        head_ = new Node_list<Type_list>(nullptr, nullptr, *(v.begincbegin()));
        Node_list<Type_list>* current_this = head_;
        for (auto i = v.begincbegin(); i != v.endcend(); ++i) {
            if (i != v.begincbegin()) {
                current_this = new Node_list<Type_list>(nullptr, current_this, i->data);
                current_this = current_this->next;
            }
        }
    }

    template<class Type_list>
    typename s21::list<Type_list>::const_reference list<Type_list>::front(){
        if(head_==nullptr) throw std::out_of_range("size of list equal 0");
        return *(head_->data);
    }

    template<class Type_list>
    typename s21::list<Type_list>::const_reference list<Type_list>::back(){
        if(head_==nullptr) throw std::out_of_range("size of list equal 0");
        Node_list<Type_list>* current=this->head_;
        while (current->next != null) {
            current=current->next;
        }
        return *(current->data);
    }

    template<class Type_list>
    typename list<Type_list>::iterator list<Type_list>::begincbegin(){
        list<Type_list>::iterator i(head_);
        return i;
    }
    
    template<class Type_list>
    typename list<Type_list>::iterator list<Type_list>::endcend(){
        list<Type_list>::iterator i(nullptr);
        return i;
    }

    template<class Type_list>
    void list<Type_list>::clear(){
        Node_list<Type_list>* current=head_;
        head_=nullptr;
        while(current!=nullptr){
            delete current->data;
            current=current->next;
        }
    }

    template<class Type_list>
    typename list<Type_list>::iterator list<Type_list>::insert(iterator pos, const_reference value){
        for
    }











    template<class Type_list>
    void list<Type_list>::push_back(const_reference value){
        if (head_ == nullptr) {
            head_ = new Node_list<Type_list>(nullptr, nullptr, value);
        } else {
            Node_list<Type_list> *current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next=new Node_list<Type_list>(nullptr,current,value);
        }
        ++size_;
    }
}
