#include "Vector3d.h"
#include "Point3d.h"

#include <iostream>
#include <string>

class Employee
{	
private:
	int age {};
	std::string name {};

public:
	Employee(int _age, std::string _name)
	: age {_age}
	, name {_name}
	{}

	auto getAge() const -> const int& {return age;}
	auto getString() const -> const std::string& {return name;}
	auto returnName() -> const std::string&;
};

auto Employee::returnName() -> const std::string&
{
	return getString();
}


int main()
{
	std::cout << Employee{12, "jon"}.returnName();

	return 0;
}