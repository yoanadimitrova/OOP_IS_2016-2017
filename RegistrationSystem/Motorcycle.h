#pragma once
#include "RegistrationSystem.h"

class Motorcycle : public RegistrationSystem
{
    enum TypeMotor
    {
        None,
        ExternalCombustionEngine, //двигател с външно горене
        InternalCombustionEngine, // двигател с вътрешно горене
        FourStrokeEngine, // четиритактов двигател
    };

    enum EuroStandart
    {
        none,
        Euro1,
        Euro2,
        Euro3,
        Euro4,
        Euro5,
        Euro6
    };

    enum TypeOfTheMotorcycle
    {
        NonE,
        Sports,
        Hiking,
        Cruise,
        Chopper,
        CrossCountry,
    };

protected:
    TypeMotor eTypeMotor; // Тип на двигател
    unsigned int power; // Мощност(брой конски сили)
    unsigned int workingVolume; // Работен обем на двигателя
    unsigned int numCylinders; // Брой цилиндри
    EuroStandart eEuroStandart; // Евростандарт, който се покрива от лекия автомобил. Възможните стойности са от 'Евро 1' до 'Евро 6'
    TypeOfTheMotorcycle eTypeOfTheMotorcycle; // Тип на мотора - спортен, туристически, круизър, чопър или кросов
public:
    Motorcycle();
    Motorcycle(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour,TypeMotor eTypeMotor = None, unsigned int power = 0, unsigned int workingVolume = 0, unsigned int numCylinders = 0, EuroStandart eEuroStandart = none, TypeOfTheMotorcycle eTypeOfTheMotorcycle = NonE);
    ~Motorcycle();
    Motorcycle& operator=(const Motorcycle& other);
    Motorcycle(const Motorcycle& other);

    // Getters
    TypeMotor GeteTypeMotor() const;
    unsigned int GetPower() const;
    unsigned int GetWorkingVolume() const;
    unsigned int GetNumCylinders() const;
    EuroStandart GeteEuroStandart() const;
    TypeOfTheMotorcycle GeteTypeOfTheMotorcycle() const;

    // Setters
    void SeteTypeMotor(TypeMotor neweTypeMotor);
    void SetPower(unsigned int newPower);
    void SetWorkingVolume(unsigned int newWorkingVolume);
    void SetNumCylinders(unsigned int newNumCylinders);
    void SeteEuroStandart(EuroStandart neweEuroStandart);
    void SeteTypeOfTheMotorcycle(TypeOfTheMotorcycle neweTypeOfTheMotorcycle);

    double CivilLiability() const; //колко струва гражднаската отговорност
    double PriceOfTheRegionalTax() const; // цената на областния данък
};
