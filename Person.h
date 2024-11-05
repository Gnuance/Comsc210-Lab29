// Person.h

/*  
    Person class: modified from Goat.h in Lab24
*/

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public: 
    Person()                              { name = ""; age = 0; color = ""; }
    // write three more constructors
    // just name as an argument
    Person(string n)                      { name = n; age = 0; color = ""; }
    // name and age
    Person(string n, int a)               { name = n; age = a; color = ""; }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }

    // write overloaded < operator for the std::list
    // necessary for set to compare objects
    bool operator<(const Person &g) const   { return name < g.name; }
};

#endif