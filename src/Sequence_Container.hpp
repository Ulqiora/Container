#pragma once

template <typename Type>
class Sequence {
    typedef size_t size_type;

 private:
    size_type size_;

 public:
    class iterator {
     private:
        Type* elem;

     public:
        iterator(Type* other);
        virtual iterator operator++();  //    prefix
        virtual iterator operator--();  //    prefix
        virtual bool operator==(iterator const& other);
        virtual bool operator!=(iterator const& other);
        virtual ~iterator();
    };
    class reverse_iterator {
     private:
        Type* elem;

     public:
        reverse_iterator(Type* other);
        virtual reverse_iterator operator++();  //    prefix
        virtual reverse_iterator operator--();  //    prefix
        virtual bool operator==(reverse_iterator const& other);
        virtual bool operator!=(reverse_iterator const& other);
        virtual ~reverse_iterator();
    };
    Sequence() : size_(0) {}
    Sequence(Sequence& other) : size_(other.size_) {}
    virtual Sequence(size_type n, T& other = T()){};
    virtual Sequence<Type> operator=(Sequence<Type> const& other);
    virtual iterator begin();
    virtual iterator end();
    virtual reverse_iterator rbegin();
    virtual reverse_iterator rend();
    inline size_type size(){return size_};
    virtual resize(size_type n, Type other);
    inline bool empty() { return size_ == 0; }
    virtual iterator insert(iterator it, Type& other);
    virtual iterator insert(iterator it, size_type n, Type& other);
    virtual iterator erase(iterator first, iterator last);
    virtual iterator erase(iterator j);
    virtual void push_back(Sequence& other);
    virtual void pop_back() { size_--; };
    virtual Type& front();
    virtual Type& back();
};
