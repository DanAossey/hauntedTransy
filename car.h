#include <iostream>

using namespace std;

struct CAR {
	int carCapacity;
	int weightLimit;
	int currentPassengers = 0;
	int currentWeight = 0;
};

bool updateCar(CAR currentCar, int weight) {

	if (currentCar.currentWeight + weight > currentCar.weightLimit || currentCar.currentPassengers == currentCar.carCapacity) {
		cout << endl << "Passenger could not be added";
		return false;
	}

	else {
		currentCar.currentWeight = currentCar.currentWeight + weight;
		++currentCar.carCapacity;
		return true;
	}
}
