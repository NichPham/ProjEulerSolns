/*
* The sum of all the multiples of 3 and 5 below a certain number (specifically 1000)
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char** argv) {
	if (argc != 2) { 
		printf("Usage: problem1 number\n");
		return 0;
	} else if (isalpha(*argv[1]) != 0) {
		printf("Input must be positive integer\n");
		return 0;
	}

	int max = atoi(argv[1]);
	int sum = 0;

	// Add all multiples of 3 including those that are also multiples of 5
	int i;
	for(i = 3; i < max; i += 3) {
		sum += i;
	}

	// Add multiples of 5 but omitting those already counted as multiples of 3
	for(i = 5; i < max; i += 5) {
		if (i % 3 != 0) {
			sum += i;
		}
	}

	printf("The sum of multiples of 3 and 5 less than %d is %d\n", max, sum);
}