
enum class Gender
{
	None,
	Male,
	Female,
};

class Person
{
public:
	Person(const char* _name, Gender _eGender, bool _isAlive, double _power)
		: name(nullptr), eGender(_eGender), isAlive(_isAlive), power(_power)
	{
		//setName(_name);
	}
	Person()
	{
	}

	Person(const Person& other)
	{
	}
	Person& operator=(const Person& other)
	{
		return *this;
	}

	const char* GetName() const
	{
		return name;
	}

	void SetAlive(bool _isAlive)
	{
		isAlive = _isAlive;
	}

	bool IsAlive()
	{
		return isAlive;
	}

private:
	const char* name;
	Gender eGender;
	bool isAlive;
	double power;
};

template<typename T>
class Vector
{
public:
	Vector(T* _data, size_t _size)
	{
		if (_data != nullptr && _size > 0)
		{
			data = new T[_size];
			size = capacity= _size;
			for (size_t i = 0; i < _size; i++)
			{
				data[i] = _data[i];
			}
		}
		else
		{
			data = nullptr;
			size = capacity = 0;
		}
	}

	Vector()
	{
		data = nullptr;
		size = capacity = 0;
	}

	Vector(const Vector& other)
	{
		if (other.data != nullptr && other.size > 0)
		{
			data = new T[other.size];
			size = capacity = other.size;
			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}
		else
		{
			data = nullptr;
			size = capacity = 0;
		}
	}

	Vector& operator=(const Vector& rhs)
	{
		if (this == &rhs) return *this;

		if (rhs.data != nullptr && rhs.size > 0)
		{
			data = new T[rhs.size];
			size = capacity = rhs.size;
			for (size_t i = 0; i < size; i++)
			{
				data[i] = rhs.data[i];
			}
		}
		else
		{
			data = nullptr;
			size = capacity = 0;
		}

		return *this;
	}

	~Vector()
	{
		delete[] data;
	}

	T& operator[](size_t idx)
	{
		return data[idx];
	}

	const T& operator[](size_t idx) const
	{
		return data[idx];
	}

	void push_back(const T& element)
	{
		if ((size + 1) > capacity)
		{
			if (capacity == 0)
			{
				capacity = 1;
			}
			resize(capacity * 2);
		}

		data[size] = element;
		size++;
	}

	size_t GetSize()
	{
		return size;
	}

	using predicate = bool(*)(const T&);
	size_t findAll(predicate cond)
	{
		size_t counter = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (cond(data[i]) == true)
			{
				counter++;
			}
		}
		return counter;
	}
private:
	T* data;
	size_t size;
	size_t capacity;

	void resize(size_t newCapacity)
	{
		T* temp = new T[newCapacity];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		capacity = newCapacity;
	}
};
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

class Home
{
public:
	Home(const char* _name, Vector<Person*> _member)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		members = _member;
		numberOfHouses++;
	}

	Home()
	{
		name = new char[1];
		*name = '\0';
		numberOfHouses++;
	}

	Home(const Home& other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		members = other.members;
		numberOfHouses++;
	}

	~Home()
	{
		delete[] name;
		numberOfHouses--;
	}

	Home& operator=(const Home& rhs)
	{
		if (this == &rhs) return *this;

		delete[] name;
		name = new char[strlen(rhs.name) + 1];
		strcpy(name, rhs.name);
		members = rhs.members;

		return *this;
	}

	Home& operator+=(Person& other)
	{
		members.push_back(&other);
		return *this;
	}

	Home operator+(Person& other)
	{
		Home res(*this);
		res += other;
		return res;
	}

	bool isMember(const char* name)
	{
		for (size_t i = 0; i < members.GetSize(); i++)
		{
			if (strcmp(name, members[i]->GetName()) == 0)
			{
				return true;
			}
		}
		return false;
	}

	void killPerson(const char* name)
	{
		for (size_t i = 0; i < members.GetSize(); i++)
		{
			if (strcmp(name, members[i]->GetName()) == 0)
			{
				members[i]->SetAlive(false);
			}
		}
	}

	size_t numberOfAlivePersons()
	{
		size_t counter = 0;
		for (size_t i = 0; i < members.GetSize(); i++)
		{
			if (members[i]->IsAlive() == true)
			{
				counter++;
			}
		}
		return counter;
	}

	size_t numberOfDeathPersons()
	{
		size_t counter = 0;
		for (size_t i = 0; i < members.GetSize(); i++)
		{
			if (members[i]->IsAlive() == false)
			{
				counter++;
			}
		}
		return counter;
	}

private:
	char* name;
	Vector<Person*> members;
	static size_t numberOfHouses;
};

size_t Home::numberOfHouses = 0;

enum class Departement
{
	HumanRealtion,
	Sales,
	SoftwareDeveloppers,
};

class Employee
{
public:
	Employee( char* name, char* address, char* EGN,
			  Departement eDepartement, double salary)
	{
		// ...
	}
	Employee() {}

	double GetSalary()
	{
		return m_salary;
	}
private:
	char* m_name;
	char* m_address;
	char m_EGN[10 + 1];
	Departement m_eDepartement;
	double m_salary;

};

class Specialist : public Employee
{
public:
	Specialist(char* name, char* address, char* EGN,
		Departement eDepartement, double salary, const char* speaciality)
		: Employee(name, address, EGN, eDepartement, salary)
	{
		// ...
	}
private:
	const char* speciality;
};

class TeamLeader : public Specialist
{
public:
	TeamLeader(char* name, char* address, char* EGN,
		Departement eDepartement, double salary, const char* speaciality, Vector<Employee*> employees)
		: Specialist(name, address, EGN, eDepartement, salary, speaciality)
	{
		// ...
		m_employees = employees;
	}
private:
	Vector<Employee*> m_employees;
};

enum Languages{ ENGLISH, DUTCH, };
class Secretary : public Employee
{

public:
	Secretary(char* name, char* address, char* EGN,
		Departement eDepartement, double salary, Vector<Languages>& languages)
		: Employee(name, address, EGN, eDepartement, salary)
	{
		m_languages = languages;
	}
	Secretary() {} // to do : finish
	Secretary(const Secretary& other) {} // to do : finish
	Vector<Languages>& GetLanguages()
	{
		return m_languages;
	}

	void SetLanguages(Vector<Languages>& other)
	{
		m_languages = other;
	}

private:
	Vector<Languages> m_languages;
};


class Director
{
public:
	Director(const Secretary& secr, Vector<Employee*> employess)
		: m_secr(secr), m_employess(employess)
	{
	}
	double GetAllSalaries()
	{
		double allSalaries = 0.0;
		for (size_t i = 0; i < m_employess.GetSize(); i++)
		{
			allSalaries += m_employess[i]->GetSalary();
		}
		allSalaries += m_secr.GetSalary();
		return allSalaries;
	}
private:
	Secretary m_secr;
	Vector<Employee*> m_employess;
};

#include <iostream>

int main()
{
	Secretary secr;
	Employee e1;
	Employee e2;
	Vector<Employee*> employees;
	employees.push_back(&e1);
	employees.push_back(&e2);
	Director director(secr, employees);
	std::cout << director.GetAllSalaries();
	return 0;
}
