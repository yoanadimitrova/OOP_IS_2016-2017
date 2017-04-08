#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <stddef.h>

class Team
{
    public:
        Team(const char* newName,
             double newBudget,
             Player* newPlayers, size_t newNumberOfPlayers);
        Team();
        ~Team();
        Team(const Team& other);
        Team& operator=(const Team& other);
        const char* Getname()const;
        void Setname(const char* val);
        double Getbudget() const;
        void Setbudget(double val);
        const Player* Getplayers() const;
        void Setplayers(Player* val, size_t numberOfPlayers);

        void AddPlayer(const Player& newPlayer);
        void PrintInfo() const;
    protected:
    private:
        char* name;
        double budget;
        Player* players;
        size_t numberOfPlayers;
        size_t playersCapacity;

        void resize(size_t newCapacity);
};

#endif // TEAM_H
