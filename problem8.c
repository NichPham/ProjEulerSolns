/* 
* Find the thirteen adjacent digits in the 1000-digit number that have the 
* greatest product. What is the value of this product?
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* The number the problem specifically asks for */
#define DEFAULT_NUMBER "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450"

/* 
 * General solution to the problem. First argument is the size of the subset.
 * Second optional argument is the number to parse over
 */
int main(int argc, char** argv) {
	if (argc != 2 && argc != 3) {
		printf("Usage: problem8 size [number]\n");
		return 1;
	}

	int size = atoi(argv[1]);
	char* num;
	if (argc == 2) {
		num = DEFAULT_NUMBER;
	} else {
		num = argv[2];
	}

	if (size > strlen(num)) {
		size = strlen(num);
	}

	//Load first subset
	int i;
	int prod = 1;
	int maxprod;
	int digit;
	for(i = 0; i < size; i++) {
		digit = num[i] - '0';
		prod = prod * digit;
	}
	maxprod = prod;

	// Iterate through rest of number
	// Take current product divide out first digit in subset then multiply in next digit
	// Keep track of zeroes as sets containing them are zero 
	char* first = num;
	int firstdigit;
	int zerocount = 0;
	for (i = size; i < strlen(num); i++) {
		digit = num[i] - '0';
		firstdigit = first[0] - '0';
		if (firstdigit == 0) {
			zerocount--;
			firstdigit = 1;
		} else if (zerocount > 0) {
			firstdigit = 1; 
		}

		if (digit != 0) {
			prod = (prod / firstdigit) * digit;
		} else {
			zerocount++;
			prod = 1;
		}

		if (prod > maxprod) {
			maxprod = prod;
		}

		first++;
	}

	printf("The greatest product of the %d adjacent digits in the number is %d\n", size, maxprod);

	return 0;
}