#pragma once
#include <iostream>

template<class Type,class Key>
class map{
    public:

    typedef Key key_type;
    typedef Type mapped_type;
    typedef std::pair<key_type, mapped_type> value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef size_t size_type;

    map();
    map(std::initializer_list<value_type> const &items);
    map(const map &m);
    map(map &&m);
    ~map()
    map& operator=(map &&m);

    T& at(const Key& key);
    T& operator[](const Key& key);

    iterator begin();
    const_iterator cbegin();
    iterator end();
    const_iterator cend();

    bool empty()
    size_type size();
    size_type max_size();
    void clear()
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const Key& key, const T& obj);
    std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
    void erase(iterator pos);
    void swap(map& other);
    void merge(map& other);
    bool contains(const Key& key)
    private:
};
