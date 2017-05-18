#pragma once
#include "RegistrationSystem.h"

class Trailer : public RegistrationSystem
{
protected:
    unsigned int numAxes; // Брой оси
    double maxPermissibleMass; // Максимална допустима маса
public:
    Trailer();
    Trailer(char* name, unsigned int EGN, char* regNum, Date regDate, Colour eColour,unsigned int numAxes = 0, double maxPermissibleMass = 0);
    ~Trailer();
    Trailer& operator=(const Trailer& other);
    Trailer(const Trailer& other);

    // Getters
    unsigned int GetNumAxes() const;
    double GetMaxPermissibleMass() const;

    // Setters
    void SetNumAxes(unsigned int newNumAxes);
    void SetMaxPermissibleMass(double newMaxPermissibleMass);

    double CivilLiability() const; //колко струва гражднаската отговорност
};
