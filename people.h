// File: people.h
// Dan Aossey, Transy U
// CS 3074, Fall 2021
//
// Interface: Person Class

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct PERSON{
  int name;
  double weight;
};

// makePerson func - creates a new person structure based on bassed in values and returns it
PERSON makePerson(int personID, double weight);
// getWeight func - returns the weight of a passed in PERSON struct
double getWeight(PERSON dude);
// getName func - returns the name of a passed in PERSON struct
int getName(PERSON dude);
