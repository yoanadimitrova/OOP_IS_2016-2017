#include <iostream>
#include <cstring>
#include "RegistrationSystem.h"

using namespace std;

Date::Date(int newYear, Month newMonth, int newDay)
    : year(newYear), eMonth(newMonth), day(newDay)
{
}

RegistrationSystem::RegistrationSystem(const char* newName, unsigned int newEGN, const char* newRegNum,
                                       const Date& newRegDate, Colour neweColour)
{
    SetName(newName);
    SetEGN(newEGN);
    SetRegNum(newRegNum);
    SetRegDate(newRegDate);
    SeteColour(neweColour);
}

RegistrationSystem::RegistrationSystem(const RegistrationSystem& other)
    : name(nullptr), EGN(other.EGN), regNum(nullptr), regDate(other.regDate), eColour(other.eColour)
{
    SetName(other.name);
    SetRegNum(other.regNum);
}

RegistrationSystem::~RegistrationSystem()
{
    delete [] this -> name;
    //delete [] this -> regDate;
}

RegistrationSystem& RegistrationSystem::operator = (const RegistrationSystem& other)
{
    if (this != &other)
    {
        SetName(other.name);
        EGN = other.EGN;
        SetRegNum (other.regNum);
        regDate = other.regDate;
        eColour = other.eColour;
    }
    return *this;
}

const char* RegistrationSystem::GetName() const
{
    return this -> name;
}
void RegistrationSystem::SetName(const char* newName)
{
    delete [] this -> name;
    if (newName != nullptr)
    {
        int len = strlen (newName);
        this -> name = new char [len + 1];
        strcpy (name, newName);
    }
    else
    {
        this -> name = new char [1];
        this -> name[0] = '\0';
    }
}

unsigned int RegistrationSystem::GetEGN() const
{
    return this -> EGN;
}
void RegistrationSystem::SetEGN(unsigned int newEGN)
{
    EGN = newEGN;
}

const char* RegistrationSystem::GetRegNum() const
{
    return this -> regNum;
}
void RegistrationSystem::SetRegNum(const char* newRegNum)
{
    delete [] this -> regNum;
    if (newRegNum != nullptr)
    {
        int len = strlen (newRegNum);
        this -> regNum = new char [len + 1];
        strcpy (regNum, newRegNum);
    }
    else
    {
        this -> regNum = new char [1];
        this -> regNum[0] = '\0';
    }
}

Date RegistrationSystem::GetRegDate() const
{
    return this -> regDate;
}
void RegistrationSystem::SetRegDate(const Date& newRegDate)
{
    regDate = newRegDate;
}

Colour RegistrationSystem::GeteColour() const
{
    return this -> eColour;
}
void RegistrationSystem::SeteColour(Colour neweColour)
{
    eColour = neweColour;
}

void RegistrationSystem::print()
{
    cout << name << " " << EGN << " " << regNum << " " << endl;
}

// .h   static const char* GetColourAsString(Colour eColour);
static const char* GetColourAsString(Colour eColour)
{
    switch(eColour)
    {
        case None: return "None";
        case Red: return "Red";
        case Blue: return "Blue";
    }
}
