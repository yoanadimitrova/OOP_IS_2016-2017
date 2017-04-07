#pragma once
class Vector
{
private:
    int* container;
    int size;
    int capacity;
    void resize(int newCapacity);//
public:
    Vector();//
    Vector(int* arr, int size);//
    Vector(const Vector& other);//
    Vector& operator=(const Vector& other);//
    ~Vector();//
    const int getSize()const;//
    const int getCapacity()const;//
    const int getAt(int index)const;//
    void setAt(int index, int element);//
    bool isEmpty();//
    void add(int element); //
    void remove(int element); //
    void sort(bool increasing);
    bool isSorted(bool increasing);
    Vector& operator+=(const Vector& other);//
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const Vector& other);
    Vector& operator/=(const Vector& other);
    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend Vector operator-(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend Vector operator/(const Vector& v1, const Vector& v2);
};

