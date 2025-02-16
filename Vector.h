#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class Vector 
{
    template<typename U>
    friend ostream& operator<<(ostream& out, const Vector<U>& other);
    template <typename U>
    friend istream& operator>>(istream& input, Vector<U>& other);
    private:
    T *arr;
    int maxSize;
    int currentSize;
    void resize();
    public:
    Vector();
    Vector(int maxSize);
    Vector(const Vector &orig);
    ~Vector();
    int getSize() const;
    int getMaxSize() const;
    void push_back(T num);
    T pop_back();
    bool is_empty() const;
    bool is_full() const;
    T at(int index);
    void swap(Vector &other);
    T erase(int index);
    void insert(T num, int index);
    void sort();
    void move(int num);
    int count(const T& element);
    Vector<T> unionOfVectors(const Vector<T> &other);
    Vector<T> intersectionOfVectors(const Vector<T> &other);
    Vector<T> unique();
    bool subset(const Vector &other);
    bool search(T key);
    Vector<T> operator+(const Vector<T> &other) const;
    T& operator[](int index);
    bool operator==(const Vector<T> &other) const;
    bool operator>(const Vector<T> &other) const;
    bool operator<(const Vector<T> &other) const;
    Vector<T>& operator=(const Vector<T> &other);
    Vector<T> operator-(const Vector<T> &other) const;
};
template<typename T>
inline void Vector<T>::resize() 
{
   if(currentSize==maxSize)
        {
            this->maxSize=2*this->maxSize;
            T * temp=new T [this->maxSize];
            for(int i=0;i<this->maxSize;i++)
            {
                temp[i]=arr[i];
            }
            delete[] arr;
            arr=temp;
            temp=nullptr;
        }
        else if(currentSize<maxSize/4)
        {
            int newSize=maxSize/2;
            T * temp=new T [newSize];
            for(int i=0;i<currentSize;i++)
            {
                temp[i]=arr[i];
            }
            delete[] arr;
            arr=temp;
            temp=nullptr;
        }
}
#endif
