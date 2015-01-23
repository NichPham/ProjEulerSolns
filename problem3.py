import sys

# The problem asks for the prime factorization of a specific number
# Might as well write a general one

# Primality test assumes value is not multiple of 2 or 3
def prime_test(value):
	for i in range(5, int(value ** 0.5) + 1, 6):
		if value % i == 0:
			return False
	return True

def prime_factorization(value):
	factors = []
	if value <= 1:
		return []
	elif value % 2 == 0:
		factors.append(2)
		factors += prime_factorization(value / 2)
	elif value % 3 == 0:
		factors.append(3)
		factors += prime_factorization(value / 3)
	else:
		for i in range(5, int(value ** 0.5) + 1, 6):
			if value % i == 0 and prime_test(i) == True:
				factors.append(i)
				factors += prime_factorization(value / i)
				break
			elif value % (i + 2) == 0 and prime_test(i) == True:
				factors.append(i + 2)
				factors += prime_factorization(value / (i + 2))
				break
		else:
			factors.append(value)
	return factors

if __name__ == '__main__':
	if len(sys.argv) != 2 or str.isalnum(sys.argv[1]) == False:
		print "Error"
		exit(1)
	else:
		print prime_factorization(int(sys.argv[1]))