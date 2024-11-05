
#include <string>
#include "Person.h"

// name and age
Person::Person(string n, int a)
    : name(n), age(a)
{
}

// setters and getters
void Person::setName(string n) { name = n; };
string Person::getName() const { return name; };
void Person::setAge(int a) { age = a; };
int Person::getAge() const { return age; }

Person::~Person() {}