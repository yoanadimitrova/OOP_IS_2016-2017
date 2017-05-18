#pragma once
#include "RegistrationSystem.h"

class Truck : public RegistrationSystem
{
     enum TypeMotor
    {
        None,
        ExternalCombustionEngine, //двигател с външно горене
        InternalCombustionEngine, // двигател с вътрешно горене
        FourStrokeEngine, // четиритактов двигател
    };

    enum euroStandart
    {
        none,
        Euro1,
        Euro2,
        Euro3,
        Euro4,
        Euro5,
        Euro6
    };

    enum TypeOfTheTruck
    {
        NonE,
        Trailer,
        Ordinary,
        Special,
    };

protected:
    TypeMotor eTypeMotor; // Тип на двигател
    unsigned int power; // Мощност(брой конски сили)
    unsigned int workingVolume; // Работен обем на двигателя
    unsigned int numCylinders; // Брой цилиндри
    euroStandart eEuroStandart; // Евростандарт, който се покрива от лекия автомобил. Възможните стойности са от 'Евро 1' до 'Евро 6'
    TypeOfTheTruck eTypeOfTheTruck; // Тип на камиона - влекач, обикновен камион или за специална употреба (хладилен камион, бетоновоз и други)
public:
    Truck();
    Truck(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour, TypeMotor eTypeMotor = None,unsigned int power = 0,unsigned int workingVolume = 0,unsigned int numCylinders = 0, euroStandart eEuroStandart = none, TypeOfTheTruck eTypeOfTheTruck = NonE);
    ~Truck();
    Truck& operator=(const Truck& other);
    Truck(const Truck& other);

    // Getters
    TypeMotor GeteTypeMotor() const;
    unsigned int GetPower() const;
    unsigned int GetWorkingVolume() const;
    unsigned int GetNumCylinders() const;
    euroStandart GeteEuroStandart() const;
    TypeOfTheTruck GeteTypeOfTheTruck() const;

    // Setters
    void SeteTypeMotor(TypeMotor neweTypeMotor);
    void SetPower(unsigned int newPower);
    void SetWorkingVolume(unsigned int newWorkingVolume);
    void SetNumCylinders(unsigned int newNumCylinders);
    void SeteEuroStandart(euroStandart neweEuroStandart);
    void SeteTypeOfTheTruck(TypeOfTheTruck neweTypeOfTheTruck);

    double CivilLiability() const; //колко струва гражднаската отговорност
    double PriceOfTheRegionalTax() const; // цената на областния данък
};

