#include "Person.h"


void Person::copy(const Person& other)
{
    this -> name = new char [strlen(other.name) + 1];
    strcpy (name, other.name);

    this -> sex = other.sex;

    this -> ID = other.ID;
}

Person::Person(const char* newName, int newID, Sex newSex)
{
    setName(newName);
    setSex(newSex);
    setID(newID);
}

void Person::destroy()
{
    delete [] this -> name;
}

Person::~Person()
{
    destroy();
}

Person::Person(const Person& other)
{
    copy(other);
}

Person& Person :: operator = (const Person& other)
{
    if (this != &other)
    {
        destroy();
        copy (other);
    }
    return *this;
}

const char* Person::getName() const
{
    return this -> name;
}
void Person::setName (const char* newName)
{
    delete [] this -> name;
    if (newName != NULL)
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

int Person::getID()
{
    return this -> ID;
}
void Person::setID (int newID)
{
    ID = newID;
}

Sex Person::getSex()
{
    return this -> sex;
}
void Person::setSex (Sex newSex)
{
    sex = newSex;
}
const char* GetSex(Sex sex)
{
    switch(sex)
    {
        case male: return "male";
        case female: return "female";
    }
}
void Person::print()
{
    cout << name << " " << ID << " " << GetSex(sex) << endl;
}
