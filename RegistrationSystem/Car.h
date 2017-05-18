#pragma once
#include "RegistrationSystem.h"

class Car : public RegistrationSystem
{
    enum TypeMotor
    {
        None,
        ExternalCombustionEngine, //�������� � ������ ������
        InternalCombustionEngine, // �������� � �������� ������
        FourStrokeEngine, // ������������ ��������
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
    TypeMotor eTypeMotor; // ��� �� ��������
    unsigned int power; // �������(���� ������ ����)
    unsigned int workingVolume; // ������� ���� �� ���������
    unsigned int numCylinders; // ���� ��������
    euroStandart eEuroStandart; // ������������, ����� �� ������� �� ����� ���������. ���������� ��������� �� �� '���� 1' �� '���� 6'
    TypeCoupe eTypeCoupe; // ��� �� ������ - ������, �����, �����, ��������� ��� �������

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

    double CivilLiability() const; // ����� ������ ������������ �����������
    double PriceOfTheRegionalTax() const; // ������ �� ��������� �����
};
