/* 
* What is the smallest positive number that is evenly divisible by all of the 
* numbers from 1 to 20?
*/

// Answer: 232792560

/*
* Find smallest positive integer that is evenly divisible by all number from 1 
* to user given number
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Check if multiple is evenly divisible by 1 to max
int check_multiple(int multiple, int max) {
	for (int i = 2; i <= max; i++) {
		if (multiple % i != 0) {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: problem5 number\n";
	}

	int max = atoi(argv[1]);
	int answer = 0;
	int multiple = max * 2;

	while (answer == 0) {
		if (check_multiple(multiple, max)) {
			answer = multiple;
		}
		multiple++;
	}

	printf("Smallest integer divisible by 1 to %d is %d", max, answer);

	return 0;
}