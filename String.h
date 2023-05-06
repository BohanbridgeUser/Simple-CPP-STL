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
        String& push_back(const char c);
        String& push_back(const String& s);
        String& push_back(const char* s);
        String& operator=(const String& another);
        String& operator=(String&& another);
        friend String operator+(const String& a, const String& b);
        friend std::ostream& operator<<(std::ostream& os, const String& s);
        friend std::istream& operator>>(std::istream& is, String& s);
        
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
String& String::append(const char c)
{
    s[len++] = c;
    s[len] = '\0';
    return *this;
}
String& String::append(const String& another)
{
    if (another.len + len + 1 > capacity) {
        capacity = (len + another.len) * 1.5 + 1;
        char* temp = new char[capacity];
        strncpy(temp, s, len);
        len += another.len;
        strncat(temp, another.s, another.len);
        temp[len] ='\0';
        delete [] s;
        s = temp;
        return *this;
    } else {
        strncat(s,another.s,another.len);
        len += another.len;
        s[len] = '\0';
        return *this;
    }
}
String& String::append(const char* c)
{
    if (len + strlen(c) + 1 > capacity ) {
        capacity = (len + strlen(c)) * 1.5 + 1;
        char* temp = new char[capacity];
        strncpy(temp, s, len);
        len += strlen(c);
        strncat(temp, c, strlen(c));
        temp[len] = '\0';
        delete [] s;
        s = temp;
        return *this;
    } else {
        strncat(s, c, strlen(c));
        len += strlen(c);
        s[len] = '\0';
        return *this;
    }
}
String& String::push_back(const char c)
{
    if ( len + 2 > capacity ) {
        capacity = (len + 2) * 1.5 + 1;
        char* temp = new char[capacity];
        strncpy(temp,s,len);
        temp[len++] = c;
        temp[len] ='\0';
        return *this;
    }else {
        s[len++] = c;
        s[len] = '\0';
        return *this;
    }
}
String& String::push_back(const String& another)
{
    if ( len + another.len + 1 > capacity ) {
        capacity = (len + another.len) * 1.5 + 1;
        char* temp = new char[capacity];
        strncpy(temp,s,len);
        len += another.len;
        strncat(temp,another.s,another.len);
        temp[len] ='\0';
        return *this;
    }else {
        strncat(s,another.s,another.len);
        len += another.len;
        s[len] = '\0';
        return *this;
    }
}
String& String::push_back(const char* c)
{
    if ( len + strlen(c) + 1 > capacity ) {
        capacity = (len + strlen(c)) * 1.5 + 1;
        char* temp = new char[capacity];
        strncpy(temp,s,len);
        len += strlen(c);
        strncat(temp,c,strlen(c));
        temp[len] ='\0';
        return *this;
    }else {
        strncat(s,c,strlen(c));
        len += strlen(c);
        s[len] = '\0';
        return *this;
    }
}
String& String::operator=(const String& another)
{
    if (this == &another) return *this;
    else {
        delete [] s;
        len = another.len;
        capacity = another.capacity;
        s = new char[capacity];
        strncpy(s, another.s, another.len);
        s[len] = '\0';
        return *this;
    }
}
String& String::operator=(String&& another)
{
    delete [] s;
    len = another.len;
    capacity = another.capacity;
    s = another.s;
    another.s = nullptr;
    return *this;
}
String operator+(const String& a, const String& b)
{
    String temp;
    temp.capacity = (a.len + b.len) * 1.5 + 1;
    temp.len = a.len + b.len;
    temp.s = new char[temp.capacity];
    strncpy(temp.s, a.s, a.len);
    strncat(temp.s, b.s, b.len);
    temp.s[temp.len] = '\0';
    return temp;
}
std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.s;
    return os;
}
std::istream& operator>>(std::istream& is, String& str)
{
    delete [] str.s;
    str.len = 0;
    str.capacity = 10;
    char t = '\0';
    str.s = new char[str.capacity];
    while ( is.get(t) && (t != '\n' || t != ' ')) {
        if (str.len + 1 < str.capacity) str.s[str.len++] = t;
        else {
            str.capacity = str.len * 1.5 + 1;
            char* temp = new char[str.capacity];
            strncpy(temp, str.s, str.len);
            temp[str.len++] = t;
            delete [] str.s;
            str.s = temp;
        }
    }
    str.s[str.len] = '\0';
    return is;
}
#endif