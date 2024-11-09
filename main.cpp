/*
    Lab 29: Project proposal and wireframe
        1. Proposal in .md form and uploaded in PDF format
        2. Pseudocode in .cpp

    Design Decisions:
        1. Decided global variables were not needed and would be more modular to omit.
*/

// HEADERS
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <random>

// data structures
#include <map>
#include <list>
#include <vector>
#include <array>

// Person object definition
#include "Person.h"

using namespace std;
// END HEADERS

// FUNCTIONS
// populate name container
vector<string> GetNamesFromFile(string);
// generate Person with random name/age
Person CreateRandomPerson(const vector<string> &, const vector<string> &);
// determine recovery/death for Person
void UpdateHealthStatus(Person &);
// TODO: FUNCTION: calculate number of new infections
// updates infections for each state within map
void UpdateStateInfections(map<string, array<list<Person>, 3>> &);
// END FUNCTIONS

// FIXED: determined global variables no longer needed and would only create coupling
// GLOBAL VARIABLES
// firstNames array, for random name generation
// const string FIRST_NAMES[100] = {};
// // lastNames array, for random name generation
// const string LAST_NAMES[100] = {};
// END GLOBAL

// MAIN
int main()
{
    const string FIRST_NAME_FILENAME = "firstNames.csv";
    const string LAST_NAME_FILENAME = "lastNames.csv";
    const string STATE_FILENAME = "statePopulationInfo.txt";
    const int SIMULATION_ITERATIONS = 52;
    string line = "";
    string data = "";
    string stateName = "";
    int population = 0;
    string temp = "";

    // read first and last name data from file && place into arrays && close file; EXIT if ERROR
    vector<string> firstNames = GetNamesFromFile(FIRST_NAME_FILENAME);
    vector<string> lastNames = GetNamesFromFile(LAST_NAME_FILENAME);

    // read state data from file (state abbrev:population); EXIT if ERROR
    // for each item from state file --> initialize map element with {State<string>: population<int>, infected<list> = null, recovered<list> = null, died<list> = null}
    map<string, array<list<Person>, 3>> states;
    // population map to use for calculations later
    map<string, int> statePopulations;

    // read in state information
    ifstream inFile(STATE_FILENAME);
    if (!inFile)
    {
        string errorMessage = "File: " + STATE_FILENAME + " could not be opened.";
        throw runtime_error(errorMessage);
    }
    // get each line from file and parse for state name and population
    while (getline(inFile, line))
    {
        stringstream ss(line);
        getline(ss, stateName, ':');
        ss >> population;
        statePopulations.insert({stateName, population}); // create population map

        // create array for each state map to hold infected/recovered/deceased
        array<list<Person>, 3> statusGroups = {};
        states.insert({stateName, statusGroups});
    }
    // close state data file
    inFile.close();

    // begin simulation of infection events
    // for 52 intervals
    // test single iteration for now
    for (int i = 0; i < 1; i++)
    {
        // for each state <map element>
        // for (auto it = states.begin(); it != states.end(); it++)
        // {
        //     // create infected person for each state
        //     Person infectedPerson = CreateRandomPerson(firstNames, lastNames);
        //     infectedPerson.setStatus("infected");
        //     it->second[0].push_back(infectedPerson);
        // }

        // CALL: function to determine recovery/death for each infected person for each state
        // REFACTORED: previous code refactored into function UpdateStateInfections
        UpdateStateInfections(states);

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
    }
    // output summary to console of infected/recovered/dead after 52 intervals

    // END MAIN
    return 0;
}

// generate Person with random name/age
Person CreateRandomPerson(const vector<string> &firstName, const vector<string> &lastName)
{
    int age = rand() % 100 + 1;
    string name = string(firstName.at(rand() % firstName.size()) + " " + lastName.at(rand() % lastName.size()));

    return Person(name, age, "infected");
}

// determine recovery/death for Person
void UpdateHealthStatus(Person &p)
{
    // update health status based on age
    if (p.getStatus() == "infected")
    {
        // calculate mortality;
        int mortalityRate = rand() % 100;

        // mortality rate < persons age == deceased, else, recovered
        if (mortalityRate < p.getAge())
        {
            p.setStatus("deceased");
        }
        else
        {
            p.setStatus("recovered");
        }
    }
}

// populate name container
vector<string> GetNamesFromFile(string fileName)
{
    // open file
    ifstream inputFile(fileName);

    // check file is open
    if (!inputFile.is_open())
    {
        string errorMessage = "File: " + fileName + " could not be opened.";
        throw runtime_error(errorMessage);
    }

    vector<string> names = {};
    string line = "";
    stringstream ss;
    string name = "";

    // read each line into stringstream and parse with ','
    while (getline(inputFile, line))
    {
        ss << line;
        while (getline(ss, name, ','))
        {
            names.push_back(name);
        }
    }
    inputFile.close(); // close the file

    return names;
}

// updates infections for each state within map
void UpdateStateInfections(map<string, array<list<Person>, 3>> &states)
{
    for (auto state : states) // for each state
    {
        int numRecovered = 0;
        int numDead = 0;
        int count = 0;
        Person patient;
        // output state
        cout << state.first << ": ";
        for (auto it = state.second[0].begin(); it != state.second[0].end();)
        {
            // update the health status of patient and set to variable incase of .erase
            UpdateHealthStatus(*it);
            patient = *it;
            // update list of recovered and deceased
            // place person into list determined by function
            // set it = erase since erase returns the next element
            if (it->getStatus() == "recovered")
            {
                state.second[1].push_back(*it);
                it = state.second[0].erase(it);
                numRecovered++;
            }
            else if (it->getStatus() == "deceased")
            {
                state.second[2].push_back(*it);
                it = state.second[0].erase(it);
                numDead++;
            }
            else
            {
                it++; // only increment if nothing is erased
            }

            if (count > 0)
            {
                cout << ","; // for next patient to list
            }
            cout << patient.getName() << " (" << patient.getStatus() << ")";
            count++;
        }
        if (!count) cout << "No updates."; // if no help updates to report

        cout << endl; // next state
    }
}