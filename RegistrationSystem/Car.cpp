#include <iostream>
#include <cstring>
#include "RegistrationSystem.h"
#include "Car.h"

using namespace std;

Car::Car(): RegistrationSystem(), eTypeMotor(None), power(0), workingVolume(0), numCylinders(0), eEuroStandart(none), eTypeCoupe(NonE)
{
}

Car::Car(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour, TypeMotor neweTypeMotor, unsigned int newPower, unsigned int newWorkingVolume, unsigned int newNumCylinders, euroStandart neweEuroStandart, TypeCoupe neweTypeCoupe)
    : RegistrationSystem(name, EGN, regNum, regDate, eColour), eTypeMotor(neweTypeMotor), power(newPower), workingVolume(newWorkingVolume), numCylinders(newNumCylinders), eEuroStandart(neweEuroStandart), eTypeCoupe(neweTypeCoupe)
{
}

Car::~Car()
{
}

Car& Car::operator=(const Car& other)
{
    if(this == &other)
    {
        RegistrationSystem::operator=(other);
        eTypeMotor = other.eTypeMotor;
        power = other.power;
        workingVolume = other.workingVolume;
        numCylinders = other.numCylinders;
        eEuroStandart = other.eEuroStandart;
        eTypeCoupe = other.eTypeCoupe;
    }
    return *this;
}
Car::Car(const Car& other): RegistrationSystem(other)
{
    SeteTypeMotor(other.eTypeMotor);
    SetPower(other.power);
    SetWorkingVolume(other.workingVolume);
    SetNumCylinders(other.numCylinders);
    SeteEuroStandart(other.eEuroStandart);
    SeteTypeCoupe(other.eTypeCoupe);
}

// Getters
Car::TypeMotor Car::GeteTypeMotor() const
{
    return this -> eTypeMotor;
}
unsigned int Car::GetPower() const
{
    return this -> power;
}
unsigned int Car::GetWorkingVolume() const
{
    return this -> workingVolume;
}
unsigned int Car::GetNumCylinders() const
{
    return this -> numCylinders;
}
Car::euroStandart Car::GeteEuroStandart() const
{
    return this -> eEuroStandart;
}
Car::TypeCoupe Car::GeteTypeCoupe() const
{
    return this -> eTypeCoupe;
}

// Setters
void Car::SeteTypeMotor(TypeMotor neweTypeMotor)
{
    this -> eTypeMotor = neweTypeMotor;
}
void Car::SetPower(unsigned int newPower)
{
    this -> power = newPower;
}
void Car::SetWorkingVolume(unsigned int newWorkingVolume)
{
    this -> workingVolume = newWorkingVolume;
}
void Car::SetNumCylinders(unsigned int newNumCylinders)
{
    this -> numCylinders = newNumCylinders;
}
void Car::SeteEuroStandart(euroStandart neweEuroStandart)
{
    this -> eEuroStandart = neweEuroStandart;
}
void Car::SeteTypeCoupe(TypeCoupe neweTypeCoupe)
{
    this -> eTypeCoupe = neweTypeCoupe;
}

double Car::CivilLiability() const
{
    double fee; //такса_спрямо_възрастта_на_собственика
    double coefficient; // коефицент_спрямо_областна_регистрация
    double res;
    res = (50.00 + fee)*coefficient; // (50лв. + такса_спрямо_възрастта_на_собственика) * коефицент_спрямо_областна_регистрация
}

double Car::PriceOfTheRegionalTax() const
{
    double initialFee; // начална_такса
    unsigned int numHorsepower; // брой_конски_сили
    double coefficient; // коефицент_спрямо_областна_регистрация
    double res;
    res = (initialFee + numHorsepower)*coefficient; // (начална_такса + брой_конски_сили) * коефицент_спрямо_областна_регистрация
}
