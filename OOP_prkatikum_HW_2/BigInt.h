#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class BigInt
{
private:
    int number; 
    char* bigNumber;

    void copy(const BigInt&);
    void destroy();

public:
    BigInt();
    BigInt(int number, char* bigNumber);
    BigInt(const BigInt& other);
    //BigInt& operator=(const BigInt&);
    ~BigInt();
    void print();

    //Getters
    int GetNumber() const;
    const char* GetBigNumber() const;

    //Setters
    void SetNumber(int newNumber);
    void SetBigNumber (const char* newBigNumber);

    void concat(const BigInt&);
    void concat(char* other);

    //Redefinition of operators:
    BigInt& operator=(const BigInt& rhs); 
    BigInt& operator=(int rhs);
    const BigInt operator+(const BigInt& rhs);
    BigInt& operator+=(const BigInt& rhs);
    BigInt& operator++();
    const BigInt& operator++(int);
    const BigInt& operator-(const BigInt& rhs); 
    BigInt& operator-=(const BigInt& rhs); 
    BigInt& operator--();
    const BigInt& operator--(int); 

    friend std::ostream& operator<<(std::ostream& out, const BigInt& rhs); 
    friend std::istream& operator>>(std::istream& in, BigInt& rhs); 
};
