/*
    Lab 29: Project proposal and wireframe
        1. Proposal in .md form and uploaded in PDF format
        2. Pseudocode in .cpp
*/

// HEADERS
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

// data structures
#include <map>
#include <list>
#include <vector>

// Person object definition
#include "Person.h"

using namespace std;
// END HEADERS

// FUNCTIONS
// generate Person with random name/age
Person &CreateRandomPerson();
// determine recovery/death for Person
void UpdateHealthStatus(Person &);
// calculate number of new infections
// populate name container
vector<string> &GetNamesFromFile(string);
// END FUNCTIONS

// GLOBAL VARIABLES
// firstNames array, for random name generation
const string FIRST_NAMES[100] = {};
// lastNames array, for random name generation
const string LAST_NAMES[100] = {};
// END GLOBAL

// MAIN
int main()
{
    const string FIRST_NAME_FILENAME = "firstNames.csv";
    const string LAST_NAME_FILENAME = "firstNames.csv";
    // read first and last name data from file && place into arrays && close file; EXIT if ERROR
    vector<string> firstNames = GetNamesFromFile(FIRST_NAME_FILENAME);
    vector<string> firstNames = GetNamesFromFile(LAST_NAME_FILENAME);

    // read state data from file (state abbrev: population,); EXIT if ERROR
    // for each item from state file --> initialize map element with {State<string>: population<int>, infected<list> = null, recovered<list> = null, died<list> = null}
    // close state data file

    // begin simulation of infection events
    // for 52 intervals
    // for each state <map element>
    // CALL: function to determine recovery/death for each infected person
    // place person into list determined by function
    // CALL: function calculate number of new infections
    // if new infections:
    // CALL: function to generate random Person
    // add to infected list
    // output state summary to console
    // sleep timer to let user read results
    // NEXT: state to process

    // all states processed, output current snapshot of all states to console
    // sleep timer to let user read summary
    // NEXT: iteration

    // output summary to console of infected/recovered/dead after 52 intervals

    // END MAIN
    return 0;
}

// generate Person with random name/age
Person &CreateRandomPerson()
{
}

// determine recovery/death for Person
void UpdateHealthStatus(Person & p)
{
}

// populate name container
vector<string> &GetNamesFromFile(string fileName)
{
    // open file
    ifstream inputFile("fileName");
    
    // check file is open
    if (!inputFile)
    {
        cerr << "File: " << fileName << " could not be opened.";
        return;
    }

    while (inputFile)
    {
        /* code */
    }
        
    vector<string> names = {};


}