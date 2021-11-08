// File: car.cpp
// Dan Aossey, Transy U
// CS 3074, Fall 2021
//
// Implementation: CAR Class
//
#include "car.h"
// createCar func
CAR createCar(double weightLimit, int carCapacity){
  CAR newCar;
  newCar.currentCapacity = 0;
  newCar.maxCapacity = carCapacity;
  newCar.currentWeight = 0;
  newCar.MaxWeight = weightLimit;
  return newCar;
}
// getCurrentWeight func
double getCurrentWeight(CAR rideCar){
  return rideCar.currentWeight;
}
// getCurrentCapacity func
int getCurrentCapacity(CAR rideCar){
  return rideCar.currentCapacity;
}
// addRider func
CAR addRider(CAR rideCar){
  ++rideCar.currentCapacity;
  return rideCar;
}
// subRider func
CAR subRider(CAR rideCar, int loss){
  rideCar.currentCapacity = rideCar.currentCapacity - loss;
  return rideCar;
}

// add riderWeight func
CAR addRiderWeight(CAR rideCar, double weight){
  rideCar.currentWeight = rideCar.currentWeight + weight;
  return rideCar;
}
