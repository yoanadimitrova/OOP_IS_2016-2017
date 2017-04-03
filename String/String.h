#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class String
{
public:
    String();
    String(char* data);
    String(const String& other); // copy konstruktor
    String& operator = (const String&);
    ~String();
    void print ();

    const char* getData() const;
    void setData (const char* newData);

    size_t getSize();
   // void setSize (size_t newSize);

private:
    void copy (const String&);
    void destroy();
    char* data;
    size_t size;
};


