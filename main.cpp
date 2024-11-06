/*
    Lab 29: Project proposal and wireframe
        1. Proposal in .md form and uploaded in PDF format
        2. 
*/

// HEADERS
#include <string>
#include <iostream>
#include <iomanip>

// data structures
#include <map>
#include <list>

// Person object definition
#include "Person.h"
// END HEADERS

// FUNCTIONS
// generate Person with random name/age
// determine recovery/death for Person
// calculate number of new infections
// END FUNCTIONS

// GLOBAL VARIABLES
// firstNames array, for random name generation
// lastNames array, for random name generation
// END GLOBAL

// MAIN
// read first and last name data from file (state abbrev: population) && place into global arrays && close file; EXIT if ERROR

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
