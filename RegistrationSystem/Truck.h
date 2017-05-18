#pragma once
#include "RegistrationSystem.h"

class Truck : public RegistrationSystem
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

    enum TypeOfTheTruck
    {
        NonE,
        Trailer,
        Ordinary,
        Special,
    };

protected:
    TypeMotor eTypeMotor; // ��� �� ��������
    unsigned int power; // �������(���� ������ ����)
    unsigned int workingVolume; // ������� ���� �� ���������
    unsigned int numCylinders; // ���� ��������
    euroStandart eEuroStandart; // ������������, ����� �� ������� �� ����� ���������. ���������� ��������� �� �� '���� 1' �� '���� 6'
    TypeOfTheTruck eTypeOfTheTruck; // ��� �� ������� - ������, ��������� ������ ��� �� ��������� �������� (�������� ������, ��������� � �����)
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

    double CivilLiability() const; //����� ������ ������������ �����������
    double PriceOfTheRegionalTax() const; // ������ �� ��������� �����
};

