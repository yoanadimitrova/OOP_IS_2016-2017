#include <iostream>
#include <cstring>
#include "RegistrationSystem.h"
#include "Motorcycle.h"

using namespace std;

Motorcycle::Motorcycle(): RegistrationSystem(), eTypeMotor(None), power(0), workingVolume(0), numCylinders(0), eEuroStandart(none), eTypeOfTheMotorcycle(NonE)
{
}

Motorcycle::Motorcycle(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour, TypeMotor neweTypeMotor, unsigned int newPower, unsigned int newWorkingVolume, unsigned int newNumCylinders, EuroStandart neweEuroStandart, TypeOfTheMotorcycle neweTypeOfTheMotorcycle)
    : RegistrationSystem(name, EGN, regNum, regDate, eColour), eTypeMotor(neweTypeMotor), power(newPower), workingVolume(newWorkingVolume), numCylinders(newNumCylinders), eEuroStandart(neweEuroStandart), eTypeOfTheMotorcycle(neweTypeOfTheMotorcycle)
{
}

Motorcycle::~Motorcycle()
{
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other)
{
    if(this == &other)
    {
        RegistrationSystem::operator=(other);
        eTypeMotor = other.eTypeMotor;
        power = other.power;
        workingVolume = other.workingVolume;
        numCylinders = other.numCylinders;
        eEuroStandart = other.eEuroStandart;
        eTypeOfTheMotorcycle = other.eTypeOfTheMotorcycle;
    }
    return *this;
}
Motorcycle::Motorcycle(const Motorcycle& other): RegistrationSystem(other)
{
    SeteTypeMotor(other.eTypeMotor);
    SetPower(other.power);
    SetWorkingVolume(other.workingVolume);
    SetNumCylinders(other.numCylinders);
    SeteEuroStandart(other.eEuroStandart);
    SeteTypeOfTheMotorcycle(other.eTypeOfTheMotorcycle);
}

// Getters
Motorcycle::TypeMotor Motorcycle::GeteTypeMotor() const
{
    return this -> eTypeMotor;
}
unsigned int Motorcycle::GetPower() const
{
    return this -> power;
}
unsigned int Motorcycle::GetWorkingVolume() const
{
    return this -> workingVolume;
}
unsigned int Motorcycle::GetNumCylinders() const
{
    return this -> numCylinders;
}
Motorcycle::EuroStandart Motorcycle::GeteEuroStandart() const
{
    return this -> eEuroStandart;
}
Motorcycle::TypeOfTheMotorcycle Motorcycle::GeteTypeOfTheMotorcycle() const
{
    return this -> eTypeOfTheMotorcycle;
}

// Setters
void Motorcycle::SeteTypeMotor(TypeMotor neweTypeMotor)
{
    this -> eTypeMotor = neweTypeMotor;
}
void Motorcycle::SetPower(unsigned int newPower)
{
    this -> power = newPower;
}
void Motorcycle::SetWorkingVolume(unsigned int newWorkingVolume)
{
    this -> workingVolume = newWorkingVolume;
}
void Motorcycle::SetNumCylinders(unsigned int newNumCylinders)
{
    this -> numCylinders = newNumCylinders;
}
void Motorcycle::SeteEuroStandart(EuroStandart neweEuroStandart)
{
    this -> eEuroStandart = neweEuroStandart;
}
void Motorcycle::SeteTypeOfTheMotorcycle(TypeOfTheMotorcycle neweTypeOfTheMotorcycle)
{
    this -> eTypeOfTheMotorcycle = neweTypeOfTheMotorcycle;
}

double Motorcycle::CivilLiability() const
{
    double fee; //такса_спрямо_възрастта_на_собственика
    double coefficient; // коефицент_спрямо_областна_регистрация
    double res;
    res = (50.00 + fee)*coefficient; // (50лв. + такса_спрямо_възрастта_на_собственика) * коефицент_спрямо_областна_регистрация
}

double Motorcycle::PriceOfTheRegionalTax() const
{
    double initialFee; // начална_такса
    unsigned int numHorsepower; // брой_конски_сили
    double coefficient; // коефицент_спрямо_областна_регистрация
    double res;
    res = (initialFee + numHorsepower)*coefficient; // (начална_такса + брой_конски_сили) * коефицент_спрямо_областна_регистрация
}
