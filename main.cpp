// HEADERS
// data structures
// Person object definition

// FUNCTIONS
// generate Person with random name/age
// determine recovery/death for Person
// calculate number of new infections

// GLOBAL VARIABLES
// firstNames array, for random name generation
// lastNames array, for random name generation

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


