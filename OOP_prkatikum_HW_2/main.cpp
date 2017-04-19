#include <iostream>
#include <cstring>
#include "BigInt.h"
using namespace std;

int main()
{
    BigInt number(123, "123");
    number.print();
    /*
    BigInt number("123");
    BigInt number2(77);
    cout << (number + number2); // Извежда 200
    BigInt number3 = number - number2;
    BigInt number4("-3");
    cout << (number3 - number4); // Извежда 49
    number4 += 6;
    cout << number4; // Извежда 3
    cout << number4++; // Извежда 3
    cout << ++number4; // Извежда 5
    number4 = 25 * 2;
    cout << number4; // Извежда 50
    BigInt number5;
    cin >> number5;// Потребителят въвежда 321
    cout << (number5 + 9); // Извежда 330
    // Най-голямата възможна стойност на 64 битово число(без знак) е 18446744073709551615 (2^64 - 1)
    CBigInt bigNumber("1844674407370955161500032143565778237539485785849494");
    cout << (bigNumber + 16); // Извежда 1844674407370955161500032143565778237539485785849510
    */
    return 0;
}
