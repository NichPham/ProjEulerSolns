# What is the smallest positive number that is evenly divisible by all of the 
# numbers from 1 to 20?

import sys

if __name__ == '__main__':
	solution = 0
	num = 40
	while not solution:
		for i in range(11, 20):
			if num % i:
				break
		else:
			solution = num
		num += 20

	print "Solution is: " + str(solution)

# Solution: 232792560