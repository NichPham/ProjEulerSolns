/*
* Find greatest prime factor of given number (specifically 600851475143)
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* Return true if num is prime false otherwise */
int primetest(long long num) {
	if (num == 3 || num == 1) {
		return 1; 
	} else if (num % 2 == 0 || num % 3 == 0) {
		return 0;
	}

	long double root = sqrt(num);
	int i;
	for (i = 5; i <= root; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return 0;
		}
	}

	return 1;
}

/* 
* Every integer has a unique prime factorization so run through every prime
* starting from 2 and divide them out when they factor the given number
*/
int main(int argc, char** argv) {
	long long num = 1;
	if (argc == 2) {
		long long num = atol(argv[1]);
	} else {
		long long num = 600851475143; 
	}

	// Factor out 2's
	while (num % 2 == 0) {
		num = num / 2;
	}

	// Factor out the rest, last one is greatest prime factor
	int factor = 3;
	while (!primetest(num)) {
		if (primetest(factor) && num % factor == 0){
			num = num / factor;
		} else {
			factor += 2; 
		}
	}

	if (num == 1) {
		num = factor;
	}

	printf("The greatest factor is %lli\n", num);

	return 0; 
}