// Person definition

#include "Person.h"

// name, age
Person::Person(string n, int a)
{
    setName(n);
    setAge(a);
}

// name, age, status
Person::Person(string n, int a, string s)
{
    setName(n);
    setAge(a);
    setStatus(s);
}

// setters and getters
void Person::setName(string n) { name = n; };
string Person::getName() const { return name; };
void Person::setAge(int a) { age = a; };
int Person::getAge() const { return age; }
void Person::setStatus(string s) { status = s; }
string Person::getStatus() const { return status; }

// overloaded operators
bool Person::operator<(const Person &g) const { return name < g.name; }