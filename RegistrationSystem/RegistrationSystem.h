#pragma once

struct Date // ���� �� ����� �����������
{
    enum Month
    {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };

    Date(int newYear = 1900, Month newMonth = January, int newDay = 1);

    int year;
    Month eMonth;
    int day;
};

enum Colour // ���� �� ���������� ��������
{
    None,
    Red,
    Blue,
};

class RegistrationSystem
{
protected:
    char* name;
    unsigned int EGN;
    char* regNum; // �������������� ����� ��� ������� ������ 'X(X)NNNNYY', ������:
    // X(X) - � ��������� �������� ���
    // NNNN - � ��������� ����� �� �������������
    // YY   - e ������� �� ������
    Date regDate;
    Colour eColour;

public:
    RegistrationSystem(const char* newName = "", unsigned int newEGN = 0, const char* newRegNum = "",
                       const Date& expDate = Date(), Colour neweColour = None);
    RegistrationSystem(const RegistrationSystem& other);
    ~RegistrationSystem();
    RegistrationSystem& operator=(const RegistrationSystem& other);
    void print();

    // Getters
    const char* GetName() const;
    unsigned int GetEGN() const;
    const char* GetRegNum() const;
    Date GetRegDate() const;
    Colour GeteColour() const;

    // Setters
    void SetName (const char* newName);
    void SetEGN(unsigned int newEGN);
    void SetRegNum (const char* newRegNum);
    void SetRegDate(const Date& newRegDate);
    void SeteColour(Colour neweColour);
};
