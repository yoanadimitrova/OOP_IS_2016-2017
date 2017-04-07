#include <iostream>

using namespace std;
// Предефиниране на оператори

class Point
{
public:
    Point (int x = 0, int y = 0) : x(x), y(y)
    {

    }

Point& operator+=(const Point& rhs) // най-важен
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

const Point operator+(const Point& rhs) // за тук използваме оператора +=
{
    return Point (this -> x, this -> y) += rhs; // return Point (this) += rhs; когато имаме копи конструктор
}
//префиксен оператор
Point& operator++ ()
{
    *this += Point (1,1);
    return *this;
}
//постфиксен оператор
const Point& operator++ (int) // ток подаваме int, за да се знае дали е префиксна версия или постфиксна
{
    Point copy (this ->x, this -> y);
    ++(*this);
    return copy; //ръщаме копието, което сме създали преди да увеличим
}

//предефиниране на оператор за извеждане и въвеждане в конзолата; чрез приятелски ф-ии, които имат влияние върху private полетата
friend ostream& operator <<(ostream& out, Point& rhs) //за извеждане в конзолата
{
    out << rhs.x << ", " << rhs.y ;
    return out;
}
friend istream& operator >>(istream& in, Point& rhs) //за въвеждане в конзолата
{
    in >> rhs.x >> rhs.y;
    return in;
}

private:
    int x, y;
};

int main()
{
    /*
    int a = 0;
    cout << a;
    Point a;
    */
    //a++; извлича и след това увеличава
   // ++a; увеличава и след това извлича стойността
   // +++++a; е валидно, защто увеличава стойността и след това я връща
   /* int b, c, d;
    b = (c = (d = 1)); // дясна асоциативност
    (a += 2) = 3;
    a = (a += 2);
   // (a + 2) = 1; //дава грешка за Point operator+(const Point& rhs)
   Point p1 (1,2);
   Point p2 (1,2);
   (p1 + p2) = ; */
   Point p;
   cin >> p;
   cout << p;
    return 0;
}