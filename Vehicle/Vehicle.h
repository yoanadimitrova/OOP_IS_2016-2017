#pragma once

enum Colour
{
    None,
    Red,
    Blue,
};
#include <iostream>

class Vehicle
{
public:
    Vehicle(const char* brand, int yearOfMeintenance, int seats, double maxSpeed, Colour eColour);
    Vehicle();
    ~Vehicle();
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& rhs);


    // Getters
    const char* GetBrand() const;
    int GetYearOfMeintenance() const;
    int GetSeats() const;
    double GetMaxSpeed() const;
    Colour GetColour() const;

    // Setter
    void SetBrand(const char* newBrand);
    void SetYearOfMeintenance(int newYearOfMeintenance);
    void SetSeats(int newSeats);
    void SetMaxSpeed(double newMaxSpeed);
    void SetColour(Colour neweColour);

    friend std::ostream& operator<<(std::ostream& out, const Vehicle& rhs);
    friend std::istream& operator>>(std::istream& in, Vehicle& rhs);

protected:
//private:
    char* brand;
    int yearOfMeintenance;
    int seats;
    double maxSpeed;
    Colour eColour;
};


class Bicycle:public Vehicle{
protected:
    int gear;
    bool hasLights;
    bool hasLightReflectors;
    bool hasBell;

    public:
    Bicycle();
    ~Bicycle();
    Bicycle& operator=(const Bicycle& other);
    Bicycle(const Bicycle& other);

    // Getters
    int GetGear() const;
    bool GetHasLights() const;
    bool GetHasLightReflectors() const;
    bool GetHasBell() const;

    // Setter
    void SetGear(int gears);
    void SetHasLights(bool hLight);
    void SetHasLightReflectors(bool hLightReflector);
    void SetHasBell(bool hBell);
};

class MotorVehicle:public Vehicle
{
protected:
    unsigned int powerOfTheEngineInHorsepower;

public:
    MotorVehicle();
    ~MotorVehicle();
    MotorVehicle& operator=(const MotorVehicle& other);
    MotorVehicle(const MotorVehicle& other);

    // Getters
    unsigned int GetPowerOfTheEngineInHorsepower() const;

    // Setter
    void SetPowerOfTheEngineInHorsepower(unsigned int newPowerOfTheEngineInHorsepower);
};

class Car:public MotorVehicle{
    enum TypeCoupe
    {
        None,
        Sedan,
        Hatchback,
        Liftback,
        StationWagon,
        Coupe,
        Convertible,
        Limousine,
        SportUtilityVehicle,
        CrossoverUtilityVehicle,
        PickupTruck,
    };

protected:
    char* model;
    unsigned int numDoors;
    bool hasAuthomaticGearbox;
    TypeCoupe eTypeCoupe;

    public:
    Car();
    ~Car();
    Car& operator=(const Car& other);
    Car(const Car& other);

    // Getters
    const char* GetModel() const;
    unsigned int GetNumDoors() const;
    bool hasAuthomaticGearbox() const;
    TypeCoupe GeteTypeCoupe() const;


    // Setter
    void SetModel(const char* newModel);
    void SetNumDoors(unsigned int newNumDoors);
    void SetHasAuthomaticGearbox(bool newHasAuthomaticGearbox);
    void SeteTypeCoupe(typeCoupe neweTypeCoupe);
};

class Truck:public MotorVehicle
{
    enum TypeOfTheLoad
    {
        None,
        type1,
        type2,
    };

protected:
    unsigned int maxWeightOfTheLoad;


public:
    Truck();
    ~Truck();
    Truck& operator=(const Truck& other);
    Truck(const Truck& other);

    // Getters
    unsigned int GetMaxWeightOfTheLoad() const;
    TypeOfTheLoad GeteTypeCoupe() const;

    // Setter
    void SetMaxWeightOfTheLoad(unsigned int newMaxWeightOfTheLoad);
    void SeteTypeOfTheLoad(TypeOfTheLoad neweTypeOfTheLoad);

};

