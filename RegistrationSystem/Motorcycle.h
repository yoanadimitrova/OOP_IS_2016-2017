#pragma once
#include "RegistrationSystem.h"

class Motorcycle : public RegistrationSystem
{
    enum TypeMotor
    {
        None,
        ExternalCombustionEngine, //�������� � ������ ������
        InternalCombustionEngine, // �������� � �������� ������
        FourStrokeEngine, // ������������ ��������
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
    TypeMotor eTypeMotor; // ��� �� ��������
    unsigned int power; // �������(���� ������ ����)
    unsigned int workingVolume; // ������� ���� �� ���������
    unsigned int numCylinders; // ���� ��������
    EuroStandart eEuroStandart; // ������������, ����� �� ������� �� ����� ���������. ���������� ��������� �� �� '���� 1' �� '���� 6'
    TypeOfTheMotorcycle eTypeOfTheMotorcycle; // ��� �� ������ - �������, ������������, �������, ����� ��� ������
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

    double CivilLiability() const; //����� ������ ������������ �����������
    double PriceOfTheRegionalTax() const; // ������ �� ��������� �����
};
