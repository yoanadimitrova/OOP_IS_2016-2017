#include"Vector.h"
#include <iostream>
Vector::Vector(const Vector& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->container = new int[other.capacity];
    for(int i=0; i
{
    this->container[i]= other.container[i];
    }
}
Vector::Vector()
{
    this->size = 0;
    this->capacity = 0;
    this->container = NULL;
}
Vector::Vector(int* arr, int size)
{
    this->size = size;
    this->capacity = size;
    this-> container = new int[size];
    for(int i=0; i
{
    this->container[i]= arr[i];
    }
}
Vector::~Vector()
{
    delete [] this -> container;
    this -> size = 0;
    this -> capacity = 0;
}
const int Vector::getSize()const
{
    return this -> size;
}
const int Vector::getCapacity()const
{
    return this -> capacity;
}
const int Vector::getAt(int index)const
{
    return this->container[index];
}
void Vector::setAt(int index, int element)
{
    this->container[index] = element;
}
bool Vector::isEmpty()
{
    return this -> size == 0;
}
Vector& Vector::operator=(const Vector& other)
{
    if(this != &other)
    {
//destroy
        delete [] this -> container;
//copy
        this -> container = new int[other.capacity];
        for(int i=0; i
    {
        this->container[i]= other.container[i];
        }
        this->size = other.size;
                     this->capacity = other.capacity;
    }
    return *this;
}
Vector& Vector::operator+=(const Vector& other)
{
    int* temp = new int[this->capacity + other.capacity];
    for(int i = 0; i< this->capacity; i++)
    {
        temp[i] = this->container[i];
    }
    for(int i = 0; i< other.capacity; i++)
    {
        temp[i + capacity] = other.container[i];
    }
    delete[] this->container;
    this-> container = temp;
}
void Vector::resize(int newCapacity)
{
    int* temp = new int[newCapacity];
    for(int i = 0; i< this->capacity; i++)
    {
        temp[i] = this->container[i];
    }
    delete[] this->container;
    this->container = temp;
    this->capacity = newCapacity;
}
void Vector::add(int element)
{
    this->container[size+1] = element;
    this->size = size+1;
}
void Vector::remove(int element)
{
    for(int i = element; i< this->capacity; i++)
    {
        this->container[i] = this->container[i+1];
    }
    this->size = size-1;
}
