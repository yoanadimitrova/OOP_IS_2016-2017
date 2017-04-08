#include "Player.h"

Player::Player(Position newPosition,
               unsigned int newNumber,
               double newSalary)
{
   SetPosition(newPosition);
   SetNumber(newNumber);
   SetSalary(newSalary);
}

Player::Player()
{
   SetPosition(None);
   SetNumber(0);
   SetSalary(0.0);
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    SetPosition(other.ePosition);
    SetNumber(other.number);
    SetSalary(other.salary);
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs)
    {
        SetPosition(rhs.ePosition);
        SetNumber(rhs.number);
        SetSalary(rhs.salary);
    }
    return *this;
}

Position Player::GetPosition()const
{
    return ePosition;
}

unsigned int Player::GetNumber()const
{
    return number;
}

double Player::GetSalary()const
{
    return salary;
}

void Player::SetPosition(Position newPosition)
{
    ePosition = newPosition;
}
void Player::SetNumber(unsigned int newNumber)
{
    number = newNumber;
}

void Player::SetSalary(double newSalary)
{
    salary = newSalary;
}
