// File: car.h
// Dan Aossey, Transy U
// CS 3074, Fall 2021
//
// Interface: CAR Class
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// CAR struct - holds the current weight and people sitting in the car as well as the max riders and weight of the car
struct CAR {
  double currentWeight;
  double MaxWeight;
  int currentCapacity;
  int maxCapacity;
};
// createCar func - creates a new CAR struct based on the passed in vals for weightLimit and carCapacity and returns that struct
CAR createCar(double weightLimit, int carCapacity);
// getCurrentWeight func - returns the Weight of a passed in CAR struct
double getCurrentWeight(CAR rideCar);
// getCurrentCapacity func - returns the current riders of a passed in CAR struct
int getCurrentCapacity(CAR rideCar);
// addRider func - adds one rider to the passed in CAR and returns an updated CAR
CAR addRider(CAR rideCar);
// subRider func - subtracts the input val of riders from the Car and returns the updated struct
CAR subRider(CAR rideCar, int loss);
// addRiderWeight - adds the passed in weight to the passed in CAR struct and returns the updated struct
CAR addRiderWeight(CAR rideCar, double weight);

