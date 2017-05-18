#include <iostream>
#include <cstring>
#include "RegistrationSystem.h"
#include "Truck.h"

using namespace std;


Truck::Truck(): RegistrationSystem(), eTypeMotor(None), power(0), workingVolume(0), numCylinders(0), eEuroStandart(none), eTypeOfTheTruck(NonE)
{
}

Truck::Truck(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour, TypeMotor neweTypeMotor, unsigned int newPower, unsigned int newWorkingVolume, unsigned int newNumCylinders, euroStandart neweEuroStandart, TypeOfTheTruck neweTypeOfTheTruck)
    : RegistrationSystem(name, EGN, regNum, regDate, eColour), eTypeMotor(neweTypeMotor), power(newPower), workingVolume(newWorkingVolume), numCylinders(newNumCylinders), eEuroStandart(neweEuroStandart), eTypeOfTheTruck(neweTypeOfTheTruck)
{
}

Truck::~Truck()
{
}

Truck& Truck::operator=(const Truck& other)
{
    if(this == &other)
    {
        RegistrationSystem::operator=(other);
        eTypeMotor = other.eTypeMotor;
        power = other.power;
        workingVolume = other.workingVolume;
        numCylinders = other.numCylinders;
        eEuroStandart = other.eEuroStandart;
        eTypeOfTheTruck = other.eTypeOfTheTruck;
    }
    return *this;
}
Truck::Truck(const Truck& other): RegistrationSystem(other)
{
    SeteTypeMotor(other.eTypeMotor);
    SetPower(other.power);
    SetWorkingVolume(other.workingVolume);
    SetNumCylinders(other.numCylinders);
    SeteEuroStandart(other.eEuroStandart);
    SeteTypeOfTheTruck(other.eTypeOfTheTruck);
}

// Getters
Truck::TypeMotor Truck::GeteTypeMotor() const
{
    return this -> eTypeMotor;
}
unsigned int Truck::GetPower() const
{
    return this -> power;
}
unsigned int Truck::GetWorkingVolume() const
{
    return this -> workingVolume;
}
unsigned int Truck::GetNumCylinders() const
{
    return this -> numCylinders;
}
Truck::euroStandart Truck::GeteEuroStandart() const
{
    return this -> eEuroStandart;
}
Truck::TypeOfTheTruck Truck::GeteTypeOfTheTruck() const
{
    return this -> eTypeOfTheTruck;
}

// Setters
void Truck::SeteTypeMotor(TypeMotor neweTypeMotor)
{
    this -> eTypeMotor = neweTypeMotor;
}
void Truck::SetPower(unsigned int newPower)
{
    this -> power = newPower;
}
void Truck::SetWorkingVolume(unsigned int newWorkingVolume)
{
    this -> workingVolume = newWorkingVolume;
}
void Truck::SetNumCylinders(unsigned int newNumCylinders)
{
    this -> numCylinders = newNumCylinders;
}
void Truck::SeteEuroStandart(euroStandart neweEuroStandart)
{
    this -> eEuroStandart = neweEuroStandart;
}
void Truck::SeteTypeOfTheTruck(TypeOfTheTruck neweTypeOfTheTruck)
{
    this -> eTypeOfTheTruck = neweTypeOfTheTruck;
}

double Truck::CivilLiability() const
{
    double fee; //такса_спрямо_възрастта_на_собственика
    double coefficient; // коефицент_спрямо_областна_регистрация
    double res;
    res = (50.00 + fee)*coefficient; // (50лв. + такса_спрямо_възрастта_на_собственика) * коефицент_спрямо_областна_регистрация
}

double Truck::PriceOfTheRegionalTax() const
{
    double initialFee; // начална_такса
    unsigned int numHorsepower; // брой_конски_сили
    double coefficient; // коефицент_спрямо_областна_регистрация
    double res;
    res = (initialFee + numHorsepower)*coefficient; // (начална_такса + брой_конски_сили) * коефицент_спрямо_областна_регистрация
}
