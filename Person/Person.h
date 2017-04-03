#pragma once
#include <cstring>
#include <iostream>

using namespace std;

enum Sex
    {
        male,
        female,
    };

class Person
{
private:
    char* name;
    int ID;
    Sex sex;

public:

    //Person(){};
    Person(const char* name = "Rdkvs", int ID = 452903472, Sex newSex = female);
    Person(const Person& other); // copy konstruktor
    Person& operator = (const Person&);
    ~Person();
    void print ();

    void copy (const Person& other);
    void destroy ();

    const char* getName() const;
    void setName (const char* newName);

    int getID();
    void setID (int newID);

    Sex getSex();
    void setSex (Sex newSex);
};

