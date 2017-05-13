#include "Vehicle.h"
#include <iostream>
#include <cstring>
using namespace std;

Vehicle::Vehicle(const char* newBrand, int newYearOfMeintenance, int newSeats, double newMaxSpeed, Colour neweColour)
    : brand(nullptr), yearOfMeintenance(newYearOfMeintenance), seats(seats), maxSpeed(maxSpeed), eColour(eColour)
{
    SetBrand(newBrand);
}

Vehicle::Vehicle()
    : brand(nullptr), yearOfMeintenance(0), seats(0), maxSpeed(0.0), eColour(None)
{
    SetBrand("");
}

Vehicle::~Vehicle()
{
    delete [] brand;
}

Vehicle::Vehicle(const Vehicle& other)
    : brand(nullptr), yearOfMeintenance(other.yearOfMeintenance), seats(other.seats), maxSpeed(other.maxSpeed), eColour(other.eColour)
{
    SetBrand(other.brand);
}

Vehicle& Vehicle::operator=(const Vehicle& rhs)
{
    if (this != &rhs)
    {
        SetBrand(rhs.brand);
        yearOfMeintenance = rhs.yearOfMeintenance;
        seats = rhs.seats;
        maxSpeed = rhs.maxSpeed;
        eColour = rhs.eColour;
    }
    return *this;
}

//Getters
const char* Vehicle::GetBrand() const
{
    return brand;
}

int Vehicle::GetYearOfMeintenance() const
{
    return yearOfMeintenance;
}
int Vehicle::GetSeats() const
{
    return seats;
}
double Vehicle::GetMaxSpeed() const
{
    return maxSpeed;
}
Colour Vehicle::GetColour() const
{
    return eColour;
}

//Setters
void Vehicle::SetBrand(const char* newBrand)
{
    delete[] brand;
    if (newBrand != nullptr)
    {
        size_t len = strlen(newBrand);
        if (len != 0)
        {
            brand = new char[len + 1];
            strcpy(brand, newBrand);
            return;
        }
    }
    brand = new char[1];
    brand[0] = '\0';
}

void Vehicle::SetYearOfMeintenance(int newYearOfMeintenance)
{
    yearOfMeintenance= newYearOfMeintenance;
}
void Vehicle::SetSeats(int newSeats)
{
    seats = newSeats;
}
void Vehicle::SetMaxSpeed(double newMaxSpeed)
{
    maxSpeed = newMaxSpeed;
}
void Vehicle::SetColour(Colour neweColour)
{
    eColour = neweColour;
}

ostream& operator<<(ostream& out, const Vehicle& rhs)
{
    out << rhs.brand << " , " << rhs.yearOfMeintenance << " , " << rhs.seats << " , " << rhs.maxSpeed << " , " << rhs.eColour;
    return out;
}

istream& operator>>(istream& in, Vehicle& rhs)
{
    int type;

    in >> rhs.brand >> rhs.yearOfMeintenance >> rhs.seats >> rhs.maxSpeed >> type;
    eColour = type;
    return in;
}

// Bicycle

Bicycle(): Vehicle(), gear(0), hasLights(false), hasLightReflectors(false), hasBell(hasBell)
{

}

Bicycle(const char* brand, int yearOfMeintenance, int seats, double maxSpeed, Colour eColour, int gears, bool hLight, bool hLightReflector, bool hBell)
    : Vehicle(brand, yearOfMeintenance, seats, maxSpeed, eColour), gear(gears), hasLights(hLight), hasLightReflectors(hLightReflector), hasBell(hBell)
{
    /*this->hasLights = _hl;
    this->hasLightReflectors = _hlr;
    this->hasBell = _hb; */
}

Bicycle& Bicycle::operator=(const Bicycle& other)
{
    if(this == &other)
    {
        Vehicle::operator=(other);
        gear = other.gear;
        hasLights = other.hasLights;
        hasLightReflectors = other.hasLightReflectors;
        hasBell = other.hasBell;
    }
    return *this;
}

Bicycle::~Bicycle()
{

}

//Getters
int Bicycle::GetGear() const
{
    return gear;
}
bool Bicycle::GetHasLights() const
{
    return hasLights;
}
bool Bicycle::GetHasLightReflectors() const
{
    return hasLightReflectors;
}
bool Bicycle::GetHasBell() const
{
    return hasBell;
}

//Setters
void Bicycle::SetGear(int gears)
{
    gear = gears;
}

void Bicycle::SetHasLights(bool hLight)
{
    hasLights = hLight;
}
void Bicycle::SetHasLightReflectors(bool hLightReflector)
{
    hasLightReflectors = hLightReflector;
}
void Bicycle::SetHasBell(bool hBell)
{
    hasBell = hBell;
}

//MotorVehicle
MotorVehicle(): Vehicle(), powerOfTheEngineInHorsepower(0)
{

}

MotorVehicle(const char* brand, int yearOfMeintenance, int seats, double maxSpeed, Colour eColour, unsigned int powerOfTheEngineInHorsepower)
    : Vehicle(brand, yearOfMeintenance, seats, maxSpeed, eColour), powerOfTheEngineInHorsepower(newPowerOfTheEngineInHorsepower)
{

}

MotorVehicle(const MotorVehicle& other):Vehicle(other)
{
    SetPowerOfTheEngineInHorsepower(other.powerOfTheEngineInHorsepower);
}

MotorVehicle::~MotorVehicle()
{

}

MotorVehicle& MotorVehicle::operator=(const MotorVehicle& other)
{
    if(this == &other)
    {
        Vehicle::operator=(other);
        powerOfTheEngineInHorsepower = other.powerOfTheEngineInHorsepower;
    }
    return *this;
}

// Getters
unsigned int MotorVehicle::GetPowerOfTheEngineInHorsepower() const
{
    return powerOfTheEngineInHorsepower;
}

// Setter
void MotorVehicle::SetPowerOfTheEngineInHorsepower(unsigned int newPowerOfTheEngineInHorsepower);
{
    powerOfTheEngineInHorsepower = newPowerOfTheEngineInHorsepower;
}


// Car

Car(): MotorVehicle(), model(nullptr), numDoors(0), eTypeCoupe(None)
{

}

Car(unsigned int powerOfTheEngineInHorsepower, char* model, unsigned int numDoors, bool hasAuthomaticGearbox, TypeCoupe eTypeCoupe)
    : MotorVehicle(powerOfTheEngineInHorsepower), model(newModel), numDoors(newNumDoors), hasAuthomaticGearbox(newHasAuthomaticGearbox), eTypeCoupe(neweTypeCoupe)
{

}

Car::~Car()
{
    delete [] model;
}

Car& Car::operator=(const Car& other)
{
    if(this == &other)
    {
        MotorVehicle::operator=(other);
        model = other.model;
        numDoors = other.numDoors;
        hasAuthomaticGearbox = other.hasAuthomaticGearbox;
        eTypeCoupe = other.eTypeCoupe;
    }
    return *this;
}
Car(const Car& other): MotorVehicle(other)
{
    SetModel(other.model);
    SetNumDoors(other.numDoors);
    SetHasAuthomaticGearbox(other.hasAuthomaticGearbox);
    SeteTypeCoupe(other.eTypeCoupe);
}

// Getters
const char* Car::GetModel() const
{
    return model;
}
unsigned int Car::GetNumDoors() const
{
    return numDoors;
}
bool Car::GetHasAuthomaticGearbox() const
{
    return hasAuthomaticGearbox;
}
typeCoupe Car::GeteTypeCoupe() const
{
    return eTypeCoupe;
}

// Setter
void Car::SetModel(const char* newModel)
{
    delete[] model;
    if (newModel != nullptr)
    {
        size_t len = strlen(newModel);
        if (len != 0)
        {
            model = new char[len + 1];
            strcpy(model, newModel);
            return;
        }
    }
    model = new char[1];
    model[0] = '\0';
}
void Car::SetNumDoors(unsigned int newNumDoors)
{
    numDoors = newNumDoors;
}
void Car::SetHasAuthomaticGearbox(bool newHasAuthomaticGearbox)
{
    hasAuthomaticGearbox = newHasAuthomaticGearbox;
}
void Car::SeteTypeCoupe(typeCoupe neweTypeCoupe)
{
    eTypeCoupe = neweTypeCoupe;
}
