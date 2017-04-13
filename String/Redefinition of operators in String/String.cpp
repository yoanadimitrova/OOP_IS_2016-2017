#include "String.h"

void String::copy(const String& other)
{
    this -> data = new char[strlen(other.data) +1];
    strcpy(this->data, other.data);
    this->size = other.size;
}

void String::destroy()
{
    delete [] this -> data;
    this -> size = 0;
}

String::String(const String& other)
{
    copy(other);
}

String& String::operator=(const String& other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

String::String()
{
    this->data = NULL;
    this->size = 0;
}
String::String(char* data, size_t size)
{
    this-> data = new char[strlen(data) +1];
    strcpy(this->data, data);
    this->size = size;
}
String::~String()
{
    destroy();
}
void String::print()
{
    cout<< this->data<<endl;
}

char String::getAt(int i)
{
    return this->data[i];
}

void String::setAt(int indx, char sym)
{
    this->data[indx] = sym;
}

void String::concat(char* other)
{
    int size1 = strlen(this->data);
    int size2 = strlen(other);
    char * temp = new char[size1 + size2 + 1];

    for(int i = 0; i< size1; ++i)
    {
        temp[i] = this->data[i];
    }

    for(int i = 0; i< size2; ++i)
    {
        temp[i + size1] = other[i];
    }

    temp[size1+size2] = '\0';
    delete[] this->data;
    this-> data = temp;
}

const char* String::GetData()const
{
    return this->data;
}
void String::concat(const String& other)
{
    int size1 = strlen(this->data);
    int size2 = strlen(other.GetData());
    char * temp = new char[size1 + size2 + 1];

    for(int i = 0; i< size1; ++i)
    {
        temp[i] = this->data[i];
    }

    for(int i = 0; i< size2; ++i)
    {
        temp[i + size1] = other.GetData()[i];
    }

    temp[size1+size2] = '\0';
    delete[] this->data;
    this-> data = temp;
}
//Preddefinirane na operatori:
bool String::operator==(const String& lhs)
{
    return strcmp(this->data, lhs.data) == 0; // ==0, zashtoto ako sa ravni
}
bool String::operator!=(const String& rhs)
{
    //return!(this->operator==(rhs));
    return (*this == rhs);
}
bool String::operator<(const String& rhs)
{
    return strcmp(this->data, rhs.data) < 0;
}
bool String::operator>=(const String& rhs)
{
    return !(*this < rhs);
}
bool String::operator>(const String& rhs)
{
    return (*this==rhs) && !(*this < rhs);
}
bool String::operator<=(const String& rhs)
{
    return !(*this > rhs);
}
String& String::operator+=(const String& rhs)
{
    this->concat(rhs);
    return *this;
}
String& String::operator-=(const String& rhs)
{
    int thisSize = strlen(this->data);
    int rhsSize = strlen(rhs.data);
    char* result = strstr(this->data, rhs.data);
    for (int i=0; i<strlen(result) - rhsSize; ++i)
    {
        result [i] = result [i + rhsSize];
    }
    result [strlen(result) - rhsSize] = '\0';
    return *this;
}
 std::ostream& operator>>(std::ostream& os, String& obj) //chast ot klasa i ne se pishat ::
 {
    os << "fdgjk" << endl;
    os << obj.data << endl;
    //os << obj.size;
    return os;
 }
std::istream& operator>>(std::istream& is, String& obj)
{
    is << obj.size;
    obj.data = new chat [obj.size + 1];
    is << obj.data << endl;
    return is;
}

