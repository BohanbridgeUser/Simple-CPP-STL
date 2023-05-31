#ifndef _ARRAY_H_
#define _ARRAY_H_
#include<iostream>
#include <algorithm>
template<typename T, int N>
class Array{
    private:
        T* items;
        int num;
    public:
        Array();
        Array(T item);
        Array(const Array& another);
        Array(std::initializer_list<T>);
        ~Array();
        T& operator[](const int& i);
        T operator[](const int& i)const;
        T& at(const int& i);
        T at(const int& i)const;
        T& front(const int& i);
        T front(const int& i)const;
        T& back(const int& i);
        T back(const int& i)const;
        const T* data()const;
        T* data();
        bool empty()const;
        int size()const;
        int max_size()const;
        T& fill(const T& item);
        T& swap(T& another);
        bool operator<(const Array& another)const;
        bool operator<=(const Array& another)const;
        bool operator>(const Array& another)const;
        bool operator>=(const Array& another)const;

        friend bool operator== (const Array<T,N>& a, const Array<T,N>& b);
        friend bool operator!= (const Array<T,N>& a, const Array<T,N>& b);

        using iterator = T*;
        iterator begin(){return &items[0];}
        iterator end(){return &items[num];}
        iterator cbegin()const{return &items[0];}
        iterator cend()const{return &items[num];}
};

template<typename T, int N>
Array<T,N>::Array():num(N+1)
{
    items = new T[N + 1];
}
template<typename T, int N>
Array<T,N>::Array(T item):num(N+1)
{
    items = new T[N + 1];
    for(iterator i = begin();i!=end();++i) *i = item;
}
template<typename T, int N>
Array<T,N>::Array(std::initializer_list<T> list)
{
    items = new T[N+1];
    copy(list.begin(),list.end(),items.begin());
    num = N + 1;
}


#endif