// Person definition

#include <string>
#include "Person.h"

// name and age
Person::Person(string n, int a)
{
    setName(n);
    setAge(a);
}

// setters and getters
void Person::setName(string n) { name = n; };
string Person::getName() const { return name; };
void Person::setAge(int a) { age = a; };
int Person::getAge() const { return age; }

// overloaded operators
bool Person::operator<(const Person &g) const { return name < g.name; }

Person::~Person() {}