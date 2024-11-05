# Project Proposal: Contagion
+ A simplified simulation of a contagious virus spreading throughout societies.
+ Simulation lasts 52 periods with each period representing one week for a total of 1 year.

## General Overview
+ The program tracks the 50 states of the USA, population size, and the number of people infected/recovered/died.
+ A certain number of people are likely to become infected based on the size of the state's population, those currently infected, and those recovered. 
    - A larger population increases the likelihood of additional infections. 
    - A larger number of infected increases the likelihood of additional infections.
    - A larger number of recovered decreases the likelihood of infections. 
+ Individuals over age 60 have a higher likelihood of dying, and individuals under 40 have a higher likelihood of recovering.
    - The likelihood is based on the delta of their age from those age limits.

## Implementation
+ States are represented as map elements {State<string>: population<int>, infected<list>, recovered<list>, died<list>}
+ Each list item holds elements of type Person representing an individual.
    - Names/ages assigned randomly.
+ Age range for Person (years): 1-100

## Simulation Events
+ For each iteration, a random infection value is assigned and multiplied times the number of infected people and population size to determine the number of new infections.
    - A reduction in the number of new infections is based on the number of recovered individuals.
+ For each iteration, a previously infected individual MUST recover or pass away.

## Additional Notes
+ For the current version of this program:
    - The states are considered to be independent of one another, meaning that states are not impacted by the infection values of their neighboring states.
    - The deltas for likelihood of recovery/death do not take into account infancy; meaning, an infected person age 1 is most likely to recover from infection even though this does not resemble reality.

