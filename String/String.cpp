#include "String.h"

void String::copy(const String& other)
{
    this -> data = new char [strlen(other.data) + 1];
    strcpy (this -> data, other.data);
    this -> size = other.size;
}

/*
String::String(const char* newData, size_t newSize)
{
    setData(newData);
    setSize(newSize);
}
*/

void String::destroy() // osvobojdavame dinamichnata pamet
{
    delete [] this -> data;
    this -> size = 0;
}

String::~String()
{
    destroy();
}

// operator =
String& String :: operator = (const String& other)
{
    if (this != &other)
    {
        destroy();
        copy (other);
    }
    return *this;
}

// copy konstriktor
String::String(const String& other)
{
    copy(other);
}

String::String()
{
     this -> data = NULL;
     this -> size =  0;
}

String::String(char* data)
{
    this -> data = new char [strlen(data) + 1]; //zadelqme pamet
    strcpy (this -> data, data);
    this -> size = strlen(data);
}

const char* String::getData() const
{
    return this -> data;
}
void String::setData (const char* newData)
{
    delete [] this -> data;
    if (newData != NULL)
    {
        int len = strlen (newData);
        this -> data = new char [strlen(newData) + 1];
        strcpy (this -> data, newData);
        this -> size = len;
    }
    else
    {
        this -> data = new char [1];
        this -> data[0] = '\0';
    }
}

size_t String::getSize()
{
    return this -> size;
}
/*
void String::setSize (size_t newSize)
{
    size = newSize;
}
*/

void String::print()
{
    cout << data << " " << strlen(data) << endl;
}
