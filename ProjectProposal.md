# Project Proposal: Contagion
+ A simplified simulation of a contagious virus spreading throughout societies.
+ Simulation lasts 52 periods with each period representing one week for a total of 1 year.

## General Overview
+ The program tracks 50 states, population size, and the number of people infected/recovered/died.
+ A certain number of people are likely to become infected based on the size of the state's population, those currently infected, and those recovered. 
+ A higher number of infected increases the likelihood of more infections, and a higher number of recovered decreases the likelihood of infections. 
+ Individuals over age 60 have a higher likelihood of dying, and individuals under 40 have a higher likelihood of recovering.
    - The likelihood is based on the distance of their age from those age limits.

## Implementation
+ States are represented as map elements {State<string>: population<int>, infected<list>, recovered<list>, died<list>}
+ For each iteration, a random infection value is assigned and multiplied times the number of infected people to determine the number of new infections.
    - A reduction in the number of new infections is based on the number of recovered individuals.
