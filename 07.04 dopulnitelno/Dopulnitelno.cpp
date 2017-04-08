// 1. Structs
#include <cmath>
#include <stddef.h>
#include <cstring>
#include <iostream>
using namespace std;
struct Point
{
	int x, y;
};

void InitPoint(Point p, int x, int y)
{
	p.x = x;
	p.y = y;
}

int distance(const Point& p1, const Point* p2)
{
	return static_cast<int>(sqrt(pow(p1.x - p2->x, 2) + pow(p1.y - p2->y, 2)));
}

struct Rectangle
{
	size_t width;
	size_t height;

	Rectangle(size_t width, size_t height) : width(width), height(height) {}

	size_t Perimeter() { return 2 * width + 2 * height; }
};

size_t Area(Rectangle& rec)
{
	return rec.height * rec.width;
}

class CRectangle
{
public:
	//protected:
private:
};

// 2. Class
enum class OrderType
{
	Regular,
	Express,
	SuperExpress,
};

class Order
{
public:
	Order(const char* = "", const char* = "", OrderType = OrderType::Regular);
	Order(const Order&);
	~Order();

	void SetCustomerName(const char*);
	const char* GetCustomerName() const;

	void SetCustomerAddress(const char*);
	const char* GetCustomerAddress() const;

	long long int GetOrderId() const;

	void SetOrderType(OrderType);
	OrderType GetOrderType() const;

	Order& operator=(const Order&);
private:
	char* customerName;
	char* customerAddress;
	static long long int ordersCounter;
	const long long int orderId;
	OrderType eOrderType;
};

long long int Order::ordersCounter = 0;

Order::Order(const char* customerName, const char* customerAddress, OrderType newOrderType)
: customerName(nullptr), customerAddress(nullptr), eOrderType(newOrderType)
, orderId(ordersCounter++)
{
	SetCustomerName(customerName);
	SetCustomerAddress(customerAddress);
}

Order::Order(const Order& other)
: customerName(nullptr), customerAddress(nullptr), orderId(ordersCounter++), eOrderType(other.eOrderType)
{
	SetCustomerName(other.customerName);
	SetCustomerAddress(other.customerAddress);
}

Order::~Order()
{
	delete[] customerName;
	delete[] customerAddress;
}

void Order::SetCustomerName(const char* str)
{
	delete[] customerName;

	if (str)
	{
		size_t len = strlen(str);
		if (len != 0)
		{
			customerName = new char[len + 1];
			strcpy(customerName, str);
		}
		else
		{
			customerName = new char[1];
			customerName[0] = '\0';
		}
	}
	else
	{
		customerName = new char[1];
		customerName[0] = '\0';
	}
}
const char* Order::GetCustomerName() const
{
	return customerName;
}

void Order::SetCustomerAddress(const char* str)
{
	delete[] customerAddress;

	if (str)
	{
		size_t len = strlen(str);
		if (len != 0)
		{
			customerAddress = new char[len + 1];
			strcpy(customerAddress, str);
		}
		else
		{
			customerAddress = new char[1];
			customerAddress[0] = '\0';
		}
	}
	else
	{
		customerAddress = new char[1];
		customerAddress[0] = '\0';
	}
}

const char* Order::GetCustomerAddress() const
{
	return customerAddress;
}

long long int Order::GetOrderId() const
{
	return orderId;
}

void Order::SetOrderType(OrderType newOrderType)
{
	eOrderType = newOrderType;
}

OrderType Order::GetOrderType() const
{
	return eOrderType;
}

Order& Order::operator=(const Order& rhs)
{
	if (this != &rhs)
	{
		SetCustomerName(rhs.customerName);
		SetCustomerAddress(rhs.customerAddress);
		eOrderType = rhs.eOrderType;
	}
	return *this;
}

// 3.1 Forward declaration
class Forwarded;
class UsingForward
{
public:
	UsingForward(Forwarded*, Forwarded&);
private:
	Forwarded* pMemb;
	Forwarded& refMemb;
};

// static functions
class Point3D
{
public:
	Point3D(int newX = 0, int newY = 0, int newZ = 0) : x(newX), y(newY), z(newZ) {}
	static size_t distance(const Point3D&, const Point3D&);

	friend ostream& operator<<(ostream& os, const Point3D& rhs);
private:
	int x, y, z;
};

size_t Point3D::distance(const Point3D& first, const Point3D& second)
{
	return static_cast<size_t>(sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2)));
}

// struct vs class
// Kanonichno predstavqne - golqmata chetvorka
class Foo
{
public:
	Foo();
	Foo(const Foo&);
	~Foo();
	Foo& operator=(const Foo&);
private:
	//const int constant;
	//Point& ref;
};

// Initializer list order
class MultiDimensionalPoint
{
public:
	MultiDimensionalPoint()
		: numberOfDimensions(2), coordinates(new int[numberOfDimensions])
	{
	}

	MultiDimensionalPoint(int* newCoordinates, size_t newNumberOfDimension)
		: numberOfDimensions(newNumberOfDimension), coordinates(new int[numberOfDimensions])
	{
		for (size_t i = 0; i < numberOfDimensions; i++)
		{
			coordinates[i] = newCoordinates[i];
		}
	}

private:
	int* coordinates;
	size_t numberOfDimensions;
};

//3. Dynamic memory
class OrderList
{
public:
	OrderList();
	OrderList(const Order* newOrders, size_t numberOfOrders);
	OrderList(const OrderList&);

private:
	Order* orders;
	size_t numberOfOrdes;
	size_t ordersCapacity;
};

// 4. Operators overloading
#include <iostream>
using namespace std;
class CPoint
{
public:
	CPoint(int newX = 0, int newY = 0) : x(newX), y(newY){}

	//~CPoint();
	//CPoint(const CPoint&);
	//CPoint& operator=(const CPoint&);

	// Getters & Setters
	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(int newX) { x = newX; }
	void SetY(int newY) { y = newY; }

	// Addition
	CPoint& operator +=(const CPoint& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	CPoint& operator +=(const Point& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	const CPoint operator +(const CPoint& rhs)
	{
		return CPoint(*this) += rhs;
	}

	CPoint& operator++() // Prefix
	{
		*this += 1;
		return *this;
	}

	const CPoint operator++(int) // Postfix
	{
		CPoint copy(*this);
		++(*this);
		return copy;
	}

	// Subtraction
	CPoint& operator -=(const CPoint& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	const CPoint operator -(const CPoint& rhs)
	{
		return CPoint(*this) -= rhs;
	}

	CPoint& operator--() // Prefix
	{
		*this -= 1;
		return *this;
	}

	const CPoint operator--(int) // Postfix
	{
		CPoint copy(*this);
		--(*this);
		return copy;
	}

	ostream& operator <<(ostream& os)
	{
		os << x << ", " << y;
		return os;
	}

	istream& operator >>(istream& is)
	{
		is >> x >> y;
		return is;
	}

	friend ostream& operator <<(ostream& os, const CPoint& rhs)
	{
		os << rhs.x << ", " << rhs.y;
		return os;
	}

	friend istream& operator >>(istream& is, CPoint& rhs)
	{
		is >> rhs.x >> rhs.y;
		return is;
	}

private:
	int x, y;
};

const CPoint operator+(const Point& lhs, CPoint rhs)
{
	return CPoint(lhs.x + rhs.GetX(), lhs.y + rhs.GetY());
}

const Point operator+(const Point& lhs, Point rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y };
}

ostream& operator<<(ostream& os, const Point3D& rhs)
{
	os << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
	return os;
}


int main()
{
	// 1. Structs
	Point p1;
	p1.x = 0;
	p1.y = 0;
	Point p2 = { 3, 4 };
	Point* pp2 = &p2;
	cout << "Distance from (" << p1.x << ", " << p1.y << ") to (" << pp2->x << ", " << p2.y << ") is " << distance(p1, pp2) << endl;
	Rectangle rec(3, 4);
	cout << "Area of rectangle with widht = " << rec.width << ", height = " << rec.height << " is " << Area(rec) << endl;
	Rectangle rec2 = { 5, 6 };

	// 2. Classes
	// 2.1 Static function
	Point3D p13d;
	Point3D p23d(1, 3, 4);
	cout << "Distance between " << p13d << " and " << p23d << " is " << Point3D::distance(p13d, p23d) << endl;
	// 3. Dynamic memory

	// 4. Operators overloading
	CPoint cp1(3, 4);
	CPoint cp2(0, 2);
	cp1 += cp2;
	cp2 = cp1 + CPoint(3, 4);
	++++cp2;
	cp1++;
	cout << cp2 << endl;
	cout << CPoint(4, 5) << endl;
	CPoint cp3;
	//cin >> cp3;
	cout << cp3 << endl;
	return 0;
}
