/*
 * What is the 10 001st prime number?
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int primetest(int num) {
	if(num % 2 == 0 || num % 3 == 0) {
		return 0;
	}

	double root = sqrt(num);
	int i;
	for(i = 5; i <= root; i += 6) {
		if(num % i == 0 || num % (i+2) == 0) {
			return 0;
		}
	}

	return 1; 
}

/* Find the nth prime, n inputted by user */
int main(int argc, char** argv) {
	if (argc != 2) { 
		printf("Usage: problem7 number\n");
		return 0;
	} else if (isalpha(*argv[1])) {
		printf("Input must be positive integer\n");
		return 0;
	}

	int desired = atoi(argv[1]);

	/* First and Second primes */
	if (desired == 1) {
		printf("Prime number 1 is 2");
		return 0;
	} else if (desired == 2) {
		printf("Prime number 2 is 3");
		return 0;
	}

	int seqnum = 2;
	int n = 3;
	while (seqnum < desired) {
		n += 2;
		if(primetest(n)) {
			seqnum++;
		}
	}

	printf("Prime number %d is %d\n", desired, n);
	return 0;	
}