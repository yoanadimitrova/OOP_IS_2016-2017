#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class BigInt
{
private:
    int number; //Създаване на обект от цяло число
    char* bigNumber;//Създаване на обект от от низ, съдържащ само десетични цифри(възможно е да съдържа минус на първата си позиция)

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
    BigInt& operator=(const BigInt& rhs); //Оперататор за присвояване, който приема като десен аргумент обект от тип BigInt
    BigInt& operator=(int rhs); //Оперататор за присвояване, който приема като десен аргумент обект цяло число
    const BigInt operator+(const BigInt& rhs); // Оператор +
    BigInt& operator+=(const BigInt& rhs); // Оператор +=
    BigInt& operator++(); // Префиксен оператор ++
    const BigInt& operator++(int);// Постфиксен оператор ++
    const BigInt& operator-(const BigInt& rhs); // Оператор -
    BigInt& operator-=(const BigInt& rhs); // Оператор -=
    BigInt& operator--(); // Префиксен оператор --
    const BigInt& operator--(int); // Постфиксен оператор --

    friend std::ostream& operator<<(std::ostream& out, const BigInt& rhs); // Оператор за изход <<
    friend std::istream& operator>>(std::istream& in, BigInt& rhs); // Оператор за вход >>
};
