# Project Proposal: Contagion
    + A simplified simulation of a contagious virus spreading throughout societies.
        - The program tracks 50 states, population size, and the number of people infected/recovered/died.
        - A certain number of people are likely to become infected based on the size of the state's population, those currently infected, and those recovered.

## Overview
    + Each map element represents a state, and each state contains three lists of people: infected, dead, and recovered.
    + A higher number of infected increases the likelihood of more infections, and a higher number of recovered decreases the likelihood of infections. 
    + Individuals over age 60 have a higher likelihood of dying, and individuals under 40 have a higher likelihood of recovering.
        - The likelihood is based on the distance of their age from those numbers.
    + Every round, a random infection value is assigned and multiplied times the number of  infected people
