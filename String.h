#ifnde _STRING_H_
#define _STRING_H_
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Iterator.h"

class String
{
    using Iterator = Iterator<char>;
    private:
        char* s;
        int len;
    public:
        String();
        String(char* a);
        String(int i, char c);
        String(const String& another);
        ~String();
        char& at();
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
        Iterator begin()const;
        Iterator end()const;
        Iterator rbegin()const;
        Iterator rend()const;
};

#endif