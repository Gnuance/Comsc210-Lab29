// Person.h

/*
    Person class: modified from Goat.h in Lab24
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string status;

public:
    Person();
    Person(string, int);
    Person(string, int, string);

    // setters and getters
    void setName(string);
    string getName() const;
    void setAge(int);
    int getAge() const;
    void setStatus(string);
    string getStatus() const;
    
    ~Person();

    // necessary to compare objects
    bool operator<(const Person &) const;
};

#endif