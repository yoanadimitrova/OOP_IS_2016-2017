#include <iostream>
#include <cstring>
#include "RegistrationSystem.h"
#include "Trailer.h"

using namespace std;

Trailer::Trailer(): RegistrationSystem(), numAxes(0), maxPermissibleMass(0.0)
{
}

Trailer::Trailer(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour, unsigned int newNumAxes, double newMaxPermissibleMass)
    : RegistrationSystem(name, EGN, regNum, regDate, eColour), numAxes(newNumAxes), maxPermissibleMass(newMaxPermissibleMass)
{
}

Trailer::~Trailer()
{
}

Trailer& Trailer::operator=(const Trailer& other)
{
    if(this == &other)
    {
        RegistrationSystem::operator=(other);
        numAxes = other.numAxes;
        maxPermissibleMass = other.maxPermissibleMass;
    }
    return *this;
}
Trailer::Trailer(const Trailer& other): RegistrationSystem(other)
{
    SetNumAxes(other.numAxes);
    SetMaxPermissibleMass(other.maxPermissibleMass);
}

// Getters
unsigned int Trailer::GetNumAxes() const
{
    return this -> numAxes;
}
double Trailer::GetMaxPermissibleMass() const
{
    return this -> maxPermissibleMass;
}

// Setters
void Trailer::SetNumAxes(unsigned int newNumAxes)
{
    this -> numAxes = newNumAxes;
}
void Trailer::SetMaxPermissibleMass(double newMaxPermissibleMass)
{
    this -> maxPermissibleMass = newMaxPermissibleMass;
}

double Trailer::CivilLiability() const
{
    double fee; //�����_������_���������_��_�����������
    double coefficient; // ���������_������_��������_�����������
    double res;
    res = (50.00 + fee)*coefficient; // (50��. + �����_������_���������_��_�����������) * ���������_������_��������_�����������
}
