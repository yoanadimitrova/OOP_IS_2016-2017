#ifndef PLAYER_H
#define PLAYER_H

enum Position
{
    None,
    Goalkeeper,
    Defender,
    Midfielder,
    Striker,
};
class Player
{
    public:
        Player(Position newPosition,
               unsigned int newNumber,
               double newSalary);
        Player();
        ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        // Getters
        Position GetPosition()const;
        unsigned int GetNumber()const;
        double GetSalary()const;
        // Setters
        void SetPosition(Position newPosition);
        void SetNumber(unsigned int newNumber);
        void SetSalary(double newSalary);
    protected:
    private:
        Position ePosition;
        unsigned int number;
        double salary;
};

#endif // PLAYER_H
