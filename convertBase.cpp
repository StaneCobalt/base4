#include <iostream>
#include <vector>

void base10ToNewBase(unsigned number, unsigned base);
char getLetter(unsigned n);

int main(int argc, char** argv){
	unsigned input;
	std::cout << "Enter a number: ";
	std::cin >> input;
	base10ToNewBase(input, 4);
	std::cout << std::endl;
	return 0;
}

void base10ToNewBase(unsigned number, unsigned base){
	//Formula used: z = d*q + r
	//z = dividend, d = divisor, q = quotient, r = remainder
	// example: 16/4 -> z = 16, d = 4, q = 4, r = 0 -> returns A
	// 4/4 -> z = 4, d = 4, q = 1, r = 0 -> returns A
	// 1/4 -> z = 1, d = 4, q = 0, r = 1 -> returns B
	unsigned quotient = number/base;
	unsigned remainder = number%base;
	std::vector<char> output;
	char c;
	c = getLetter(remainder);
	output.push_back(c);
	while(quotient > 0){
			remainder = quotient%base;
			c = getLetter(remainder);
			output.push_back(c);
			quotient /= base;
	}
	int size = output.size();
	for(int i = 0; i < size; i++){
		std::cout << output.back();
		output.pop_back();
	}
}

char getLetter(unsigned n){
	if (n == 0) return 'A';
	else if (n == 1) return 'B';
	else if (n == 2) return 'C';
	else if (n == 3) return 'D';
	else return ' ';
}
/*
0 = A
1 = B
2 = C
3 = D
4 = BA
5 = BB
6 = BC
7 = BD
8 = CA
9 = CB
10 = CC
11 = CD
12 = DA
13 = DB
14 = DC
15 = DD
16 = BAA
...
31 = BDD
...
60 = DDA
61 = DDB
62 = DDC
63 = DDD
64 = BAAA
*/
