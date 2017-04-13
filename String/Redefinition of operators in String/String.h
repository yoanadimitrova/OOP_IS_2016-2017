
#pragma once
#include <cstring>
#include <iostream>

using namespace std;
class String
{
public:
    String();
    String(char* data, size_t size);
    String(const String& other);
    String& operator=(const String&);
    ~String();
    void print();

    char getAt(int index);
    void setAt(int index, char symbol);


    void concat(const String&);
    void concat(char* other);

    const char* GetData()const;

    String& operator+=(const String& rhs);
    String& operator-=(const String& rhs);

    bool operator==(const String& rhs); //predefinirame operator ==
    bool operator!=(const String& rhs); //predefinirame operator !=


    bool operator< (const String& rhs);
    bool operator> (const String& rhs);
    bool operator<=(const String& rhs);
    bool operator>=(const String& rhs);
    friend std::istream& operator>>(std::istream& is, String& obj);
    friend std::ostream& operator<<(std::ostream& os, const String& obj);

private:
    void copy(const String&);
    void destroy();


    char* data;
    size_t size;
};