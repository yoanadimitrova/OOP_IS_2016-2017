#pragma once
#include "RegistrationSystem.h"

class Car : public RegistrationSystem
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

    enum TypeCoupe
    {
        NonE,
        Hatchback,
        Sedan,
        Wagon,
        Cabriolet,
        Liftback,
    };

protected:
    TypeMotor eTypeMotor; // Тип на двигател
    unsigned int power; // Мощност(брой конски сили)
    unsigned int workingVolume; // Работен обем на двигателя
    unsigned int numCylinders; // Брой цилиндри
    euroStandart eEuroStandart; // Евростандарт, който се покрива от лекия автомобил. Възможните стойности са от 'Евро 1' до 'Евро 6'
    TypeCoupe eTypeCoupe; // Тип на купето - хечбек, седан, комби, кабриолет или лифтбек

public:
    Car();
    Car(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour, TypeMotor eTypeMotor = None, unsigned int power = 0,unsigned int workingVolume = 0,unsigned int numCylinders = 0, euroStandart eEuroStandart = none, TypeCoupe eTypeCoupe = NonE);
    ~Car();
    Car& operator=(const Car& other);
    Car(const Car& other);

    // Getters
    TypeMotor GeteTypeMotor() const;
    unsigned int GetPower() const;
    unsigned int GetWorkingVolume() const;
    unsigned int GetNumCylinders() const;
    euroStandart GeteEuroStandart() const;
    TypeCoupe GeteTypeCoupe() const;

    // Setters
    void SeteTypeMotor(TypeMotor neweTypeMotor);
    void SetPower(unsigned int newPower);
    void SetWorkingVolume(unsigned int newWorkingVolume);
    void SetNumCylinders(unsigned int newNumCylinders);
    void SeteEuroStandart(euroStandart neweEuroStandart);
    void SeteTypeCoupe(TypeCoupe neweTypeCoupe);

    double CivilLiability() const; // колко струва гражднаската отговорност
    double PriceOfTheRegionalTax() const; // цената на областния данък
};
