#ifndef _ITERATOR_H_
#define _ITERATOR_H_
template<typename T>
class Iterator
{
    private:
        T* iter;
    public:
        Iterator();
        Iterator(Iterator& another);
        ~Iterator();
        Iterator& begin();
        Iterator begin()const;
        Iterator& end();
        Iterator end()const;
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

#endif