#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Vehicle v1("Volvo", 123, 1, 312,Red);
    cout << v1.GetBrand() << endl;
    cout << v1.GetYearOfMeintenance() << endl;
    cout << v1.GetMaxSpeed() << endl;
    cout << v1.GetColour() << endl;

    return 0;
}
