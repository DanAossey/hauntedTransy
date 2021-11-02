#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "car.h"
//#include <pthread.h>

using namespace std;

void* print_message_function(void* ptr);
void createWeights(int* weights, int size);

int main() {
	//pthread_t thread1, thread2;
	//char* message1 = "Thread 1";
	//char* message2 = "Thread 2";
	//int iret1, iret2;
	const int MAXPEOPLE = 100;
	int weights[MAXPEOPLE];
	int totalCrowd;
	int carCapacity;
	int carWeightLimit;
	
	cout << endl << "Please enter the total number of students (max of 100): ";
	cin >> totalCrowd;
	cout << endl << "Please enter the number of people you wish to have in one car: ";
	cin >> carCapacity;
	cout << endl << "Please enter the weight limit of the car: ";
	cin >> carWeightLimit;

	createWeights(weights, totalCrowd);

	//iret1 = pthread_create(&thread1, NULL, print_message_function, (void*)message1);
	//iret2 = pthread_create(&thread2, NULL, print_message_function, (void*)message2);
	//pthread_join(thread1, NULL);
	//pthread_join(thread2, NULL);
}



void* print_message_function(void* ptr) {
	char* message;
	message = (char*)ptr;
	printf("%s \n", message);
}

void createWeights(int* weights, int size) {

	for (int i = 0; i < size; i++) {
		weights[i] = rand() % 200 + 100;
	}
}