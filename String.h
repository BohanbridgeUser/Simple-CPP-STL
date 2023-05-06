#ifndef _STRING_H_
#define _STRING_H_
#include <iostream>
#include <cstdlib>
#include <cstring>

class String
{
    private:
        char* s;
        int len;
        int capacity;
    public:
        String();
        String(char* a);
        String(char c, int i = 0);
        String(const String& another);
        ~String();
        char& at(int i);
        char at(int i)const;
        char& operator[](int i);
        char operator[](int i)const;
        char& front();
        char front()const;
        char& back();
        char back()const;
        char* c_str()const;
        bool empty()const;
        int size()const;
        int length()const;
        String& append(const char c);
        String& append(const String& s);
        String& append(const char* s);
        String& push_back(char c);
        String& push_back(const String& s);
        String& push_back(char* s);
        String& operator=(const String& another);
        friend String operator+(const String& a, const String& b);
        friend std::ostream& operator<<(std::ostream& os, const String& s);
        friend std::istream& operator>>(std::istream& is, const String& s);
        
        class Iterator
        {
            private:
                char* iter;
            public:
                Iterator();
                Iterator(Iterator& another);
                ~Iterator();
                Iterator& operator=(const Iterator& i);
                Iterator operator+(const Iterator& another)const;
                Iterator operator-(const Iterator& another)const;
                Iterator& operator++();
                Iterator operator++(int);
                Iterator& operator--();
                Iterator operator--(int);
                friend bool operator==(const Iterator& a, const Iterator& b);
                friend bool operator!=(const Iterator& a, const Iterator& b);
        };
        Iterator begin()const;
        Iterator end()const;
        Iterator rbegin()const;
        Iterator rend()const;
};
String::String()
{
    s = new char[1];
    s[0] = '\0';
    len = 0;
    capacity = len * 1.5 + 1;
}
String::String(char* a)
{
    len = strlen(a);
    capacity = len * 1.5 + 1;
    s = new char[capacity];
    strncpy(s,a,len);
    s[len] = '\0';
}
String::String(char c, int i)
{
    len = i;
    capacity = len * 1.5 + 1;
    s = new char[capacity];
    for(int j=0;j<i;j++) s[j] = c;
    s[len] = '\0';
}
String::String(const String& another)
{
    len = another.len;
    capacity = another.capacity;
    s =  new char[capacity];
    strncpy(s,another.s,len);
    s[len] = '\0';
}
String::~String()
{
    delete [] s;
}
char& String::at(int i)
{
    if (i >= len || i < 0) {
        std::cerr << "ERROR INDEX!\n";
        exit(0);
    }else{
        return s[i];
    }
    
}
char String::at(int i)const
{
    if (i >= len || i < 0) {
        std::cerr << "ERROR INDEX!\n";
        exit(0);
    }else{
        return s[i];
    }
}
char& String::operator[](int i)
{
    if (i >= len || i < 0) {
        std::cerr << "ERROR INDEX!\n";
        exit(0);
    }else{
        return s[i];
    }
}
char String::operator[](int i)const
{
    if (i >= len || i < 0) {
        std::cerr << "ERROR INDEX!\n";
        exit(0);
    }else{
        return s[i];
    }
}
char& String::front()
{
    return s[0];
}
char String::front()const
{
    return s[0];
}
char& String::back()
{
    return s[len - 1];
}
char String::back()const
{
    return s[len - 1];
}
char* String::c_str()const
{
    char* c = new char[len + 1];
    strncpy(c,s,len);
    c[len] = '\0';
    return c;
}
bool String::empty()const
{
    return (len == 0);
}
int String::size()const
{
    return len;
}
int String::length()const
{
    return len;
}

#endif