#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "car.h"
#include "people.h"

using namespace std;

void* thread(void* arg);
void createWeights(int* weights, int size);
bool safteyCheck(CAR tempCar, PERSON* rider);
sem_t mutex;
int carhold;
double weightLimit;
CAR rideCar;
PERSON crowd[100];
int totalCrowd;

int main () {
  const int MAXPEOPLE = 100;
  pthread_t peeps[MAXPEOPLE];
  int weights[MAXPEOPLE];
  int people[MAXPEOPLE];
  sem_init(&mutex, 0, 1);	
  cout << endl << "Please enter the total number of students (max of 100): ";
  cin >> totalCrowd;
  cout << endl << "Please enter the number of people you wish to have in one car: ";
  cin >> carhold;
  cout << endl << "Please enter the weight limit of the car: ";
  cin >> weightLimit;
  createWeights(weights, totalCrowd);
  for (int i = 0; i < totalCrowd; i++){
    crowd[i] = makePerson(i, weights[i]);
  }
  rideCar = createCar(weightLimit, carhold);
  while(1){
  for (int i = 0; i < totalCrowd; i++){
    people[i] = pthread_create(&peeps[i], NULL, thread, (void*) &crowd[i]);
    pthread_join (peeps[i], NULL);
  }
  }

  return 0;
}

// thread func - the function passed into the threads representing each student
void* thread(void* arg){
  // sem_wait checks the mutex semaphor to see if the thread can run and if not avialble goes into busy wait
  sem_wait(&mutex);
    PERSON *rider;
    CAR tempCar;
    double previousWeight = getCurrentWeight(rideCar);
    rider = (PERSON*) arg;
    printf("Rider %i \n ", rider->name);
    printf("%lf \n", rider->weight);
    tempCar = rideCar;
    tempCar = addRider(tempCar);
    tempCar = addRiderWeight(tempCar, rider->weight);
    if (safteyCheck(tempCar, rider)){
      rideCar = tempCar;
    }
    else{
      cout << "Rejected cause ur too fat dumb ass" << endl;
    }
    if (getCurrentCapacity(rideCar) == carhold){
      printf("Car Full \n");
      printf("Car weight: %lf \n", getCurrentWeight(rideCar));
      sleep(5);
      cout << endl << "Boo" << endl;
      sleep(5);
      rideCar = createCar(weightLimit, carhold);
    }
    sem_post(&mutex);
}
// create Weights func -  creates an array of random weights to be used in the crowd of students going to haunted transy
void createWeights(int* weights, int size) {
  srand(time(NULL) + totalCrowd);
  for (int i = 0; i < size; i++) {
    weights[i] =  rand() % 200 + 100;
  }
}
// safteyCheck func - supposed to run through the saftey algorithum but currently makes me wann blow my fuking brains out all over the lab
bool safteyCheck(CAR tempCar, PERSON* rider){
  double tempWeight = getCurrentWeight(tempCar);
  double tempCapacity = getCurrentCapacity(tempCar);
  
  if (tempWeight > weightLimit){
    return false;
  }

  if (tempCapacity == carhold){
    return true;
  }
  
  for (int i = 0; i < totalCrowd; i++){
    if (tempCapacity == carhold){
      return true;
    }
    if (rider->name != getName(crowd[i])){
      tempWeight = tempWeight + getWeight(crowd[i]);
      tempCar = addRiderWeight(tempCar,getWeight(crowd[i]));
      tempCar = addRider(tempCar);
      if(tempWeight <= weightLimit && safteyCheck(tempCar, &crowd[i])){
	return true;
      }
    }
  }
  return false;
}



