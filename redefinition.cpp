#include <iostream>

using namespace std;

class Point
{
public:
    Point (int x = 0, int y = 0) : x(x), y(y)
    {

    }

Point& operator+=(const Point& rhs) // 
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

const Point operator+(const Point& rhs)
{
    return Point (this -> x, this -> y) += rhs; 
}

Point& operator++ ()
{
    *this += Point (1,1);
    return *this;
}

const Point& operator++ (int) 
{
    Point copy (this ->x, this -> y);
    ++(*this);
    return copy;
}

friend ostream& operator <<(ostream& out, Point& rhs) 
    out << rhs.x << ", " << rhs.y ;
    return out;
}
friend istream& operator >>(istream& in, Point& rhs)
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
   
   /* int b, c, d;
    b = (c = (d = 1)); 
    (a += 2) = 3;
    a = (a += 2);
   // (a + 2) = 1; 
   Point p1 (1,2);
   Point p2 (1,2);
   (p1 + p2) = ; */
   Point p;
   cin >> p;
   cout << p;
    return 0;
}
