#include <iostream>
#include "RegistrationSystem.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Trailer.h"

using namespace std;

int main()
{
    //RegistrationSystem Car("Ivan", 9009090909, "EB6666EB", Date(2017, Date::May, 18), Blue);
    //cout << "Registration system: owner's name: " << Car.GetName << ", owner's EGN: " << Car.GetEGN << ", registration number: "
    //<< Car.GetRegNum << ", registration date: " << Car.GetRegDate << ", car's colour: " << Car.GeteColour << endl;

    //RegistrationSystem r1 ("Ivan", 9009090909, "EB6666EB");
    //r1.print();

    Motorcycle m;
    Car c;
    Truck t;
    cout << m.PriceOfTheRegionalTax();
    cout << c.PriceOfTheRegionalTax();
    cout << t.PriceOfTheRegionalTax();


    return 0;
}
