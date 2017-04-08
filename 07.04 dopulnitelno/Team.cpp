#include "Team.h"
#include <cstring>

Team::Team(const char* newName,
     double newBudget,
     Player* newPlayers, size_t newNumberOfPlayers)
 {
    name = nullptr;
    players = nullptr;
    Setname(newName);
    Setbudget(newBudget);
    Setplayers(newPlayers, numberOfPlayers);
 }

Team::Team()
{
    name = nullptr;
    players = nullptr;
    Setname("");
    Setbudget(0.0);
    Setplayers(nullptr, 0);
}

Team::~Team()
{
    delete[] name;
    delete[] players;
}

Team::Team(const Team& other)
{
    name = nullptr;
    players = nullptr;
    Setname(other.name);
    Setbudget(other.budget);
    Setplayers(other.players, other.numberOfPlayers);
    resize(other.playersCapacity);
}

Team& Team::operator=(const Team& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Setname(rhs.name);
    Setbudget(rhs.budget);
    Setplayers(rhs.players, rhs.numberOfPlayers);
    resize(rhs.playersCapacity);
    return *this;
}

const char* Team::Getname()const
{
    return name;
}

void Team::Setname(const char* val)
{
    delete[] name;

    if(val != nullptr)
    {
        size_t len = strlen(val);
        if(len > 0)
        {
            name = new char[len+1];
            strcpy(name, val);
            return;
        }
    }

    name = new char[1];
    name[0] = '\0';
}

double Team::Getbudget() const
{
    return budget;
}

void Team::Setbudget(double val)
{
   budget = val;
}

const Player* Team::Getplayers() const
{
    return players;
}

void Team::Setplayers(Player* val, size_t newNumberOfPlayers)
{
    delete[] players;

    if(players != nullptr && numberOfPlayers > 0)
    {
        numberOfPlayers = playersCapacity = newNumberOfPlayers;
        players = new Player[numberOfPlayers];
        for(size_t i = 0; i < numberOfPlayers; i++)
        {
            players[i] = val[i];
        }
        return;
    }
    players = nullptr;
    numberOfPlayers = playersCapacity = 0;
}

void Team::resize(size_t newCapacity)
{
    if(players == nullptr) return;

    if(newCapacity > playersCapacity)
    {
        Player* temp = new Player[newCapacity];
        for(size_t i = 0; i < numberOfPlayers; i++)
        {
            temp[i] = players[i];
        }
        playersCapacity = newCapacity;
        delete[] players;
        players = temp;
    }
}

void Team::AddPlayer(const Player& newPlayer)
{
    if(players == nullptr) return;

    if((numberOfPlayers + 1) > playersCapacity)
    {
        resize(2 * playersCapacity);
    }

    players[numberOfPlayers] = newPlayer;
    numberOfPlayers++;

}

void Team::PrintInfo() const
{
    if(players == nullptr) return;

    for(size_t i = 0; i < numberOfPlayers; i++)
    {
       // players[i].
    }

}
