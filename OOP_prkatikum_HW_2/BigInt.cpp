#include "BigInt.h"

using namespace std;

BigInt::BigInt(int newNumber, char* newBigNumber)
        : number(newNumber), bigNumber(newBigNumber)
{

}

void BigInt::copy(const BigInt& other)
{
    this -> number = other.number;
    this -> bigNumber = new char[strlen(other.bigNumber) + 1];
    strcpy(this -> bigNumber, other.bigNumber);
}

void BigInt::destroy()
{
    this -> number = 0;
    delete [] this -> bigNumber;
}

BigInt::BigInt(const BigInt& other)
{
    copy(other);
}

/*BigInt& BigInt::operator=(const BigInt& other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}
*/
BigInt::BigInt()
{
    this -> number = 0;
    this -> bigNumber = nullptr;
}

BigInt::~BigInt()
{
    destroy();
}

void BigInt::print()
{
    cout << number << " " << bigNumber <<endl;
}

int BigInt::GetNumber() const
{
    return this -> number;
}
void BigInt::SetNumber(int newNumber)
{
    number = newNumber;
}

const char* BigInt::GetBigNumber() const
{
    return this -> bigNumber;
}
void BigInt::SetBigNumber (const char* newBigNumber)
{
    delete[] bigNumber;
    if (newBigNumber != nullptr)
    {
        int len = strlen(newBigNumber);
        if (len != 0)
        {
            bigNumber = new char[len + 1];
            strcpy(bigNumber, newBigNumber);
            return;
        }
    }
    bigNumber = new char[1];
    bigNumber[0] = '\0';
}

void BigInt::concat(char* other)
{
    int size1 = strlen(this -> bigNumber);
    int size2 = strlen(other);
    char* temp = new char[size1 + size2 + 1];

    for(int i = 0; i < size1; i++)
    {
        temp[i] = this -> bigNumber[i];
    }

    for(int i = 0; i < size2; i++)
    {
        temp[i + size1] = other[i];
    }

    temp[size1 + size2] = '\0';
    delete[] this -> bigNumber;
    this -> bigNumber = temp;
}
void BigInt::concat(const BigInt& other)
{
    int size1 = strlen(this -> bigNumber);
    int size2 = strlen(other.GetBigNumber());
    char* temp = new char[size1 + size2 + 1];

    for(int i = 0; i < size1; i++)
    {
        temp[i] = this -> bigNumber[i];
    }

    for(int i = 0; i < size2; i++)
    {
        temp[i + size1] = other.GetBigNumber()[i];
    }

    temp[size1 + size2] = '\0';
    delete[] this -> bigNumber;
    this -> bigNumber = temp;
}

//Redefinition of operators:
BigInt& BigInt::operator=(const BigInt& rhs) 
{
    //number = rhs.number;
    bigNumber = rhs.bigNumber;
    return *this;
}
BigInt& BigInt::operator=(int rhs) 
{
    number = rhs;
    return *this;
}
BigInt& BigInt::operator+=(const BigInt& rhs)
{
    this -> concat(rhs);
    return *this;
}

const BigInt BigInt::operator+(const BigInt& rhs)
{
    return BigInt (this -> number, this -> bigNumber) += rhs;
}
BigInt& BigInt::operator++() 
{
    *this += BigInt (1, "18446744073");
    return *this;
}
const BigInt& BigInt::operator++(int) 
{
    BigInt copy (this -> number, this -> bigNumber);
    ++(*this);
    return copy;
}
BigInt& BigInt::operator-=(const BigInt& rhs)
{
    int thisSize = strlen(this -> bigNumber);
    int rhsSize = strlen(rhs.bigNumber);
    char* result = strstr(this -> bigNumber, rhs.bigNumber);
    for (int i = 0; i < strlen(result) - rhsSize; i++)
    {
        result [i] = result [i + rhsSize];
    }
    result [strlen(result) - rhsSize] = '\0';
    return *this;
}
const BigInt& BigInt::operator-(const BigInt& rhs)
{
    return BigInt (this -> number, this -> bigNumber) -= rhs;
}
BigInt& BigInt::operator--()
{
    *this -= BigInt (1, "18446744073");
    return *this;
}
const BigInt& BigInt::operator--(int)
{
    BigInt copy (this -> number, this -> bigNumber);
    --(*this);
    return copy;
}

std::ostream& operator<<(std::ostream& out, const BigInt& rhs)
{
    out << rhs.number << ", " << rhs.bigNumber;
    return out;
}
std::istream& operator>>(std::istream& in, BigInt& rhs)
{
    in >> rhs.number >> rhs.bigNumber;
    return in;
}
