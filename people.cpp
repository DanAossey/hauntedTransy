// File: people.cpp
// Dan Aossey, Transy U
// CS 3074, Fall 2021
//
// Implementation: Person Class

#include "people.h"

// makePerson func
PERSON makePerson(int personID, double weight){
  PERSON newPerson;
  newPerson.name = personID;
  newPerson.weight = weight;
  return newPerson;
}
// getWeight func
double getWeight(PERSON dude){
  return dude.weight;
}
// getName func
int getName(PERSON dude){
  return dude.name;
}
