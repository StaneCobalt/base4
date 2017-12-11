#include <iostream>
#include <vector>

struct Base4{
	Base4() = default;
	void base10ToNewBase(unsigned number, unsigned base);
	bool isMultipleOf4(unsigned number);
	bool multipleCalled;
};

int main(int argc, char** argv){
	unsigned input;
	std::cout << "Enter a number: ";
	std::cin >> input;
	Base4 b4;
	b4.base10ToNewBase(input, 4);
	std::cout << std::endl;
	return 0;
}

void Base4::base10ToNewBase(unsigned number, unsigned base) {
	int basePower = 0;
	unsigned powerValue = 1;
	for (unsigned i = 0; i < 16; i++) { //goes up to the 15th power
		basePower = i;
		powerValue = 1;
		std::cout << "Base Power: " << basePower;
		while (basePower > 0) {
			powerValue *= base; // 1 4 16 64 256 ... 1,073,741,824
			basePower--;
		}
		std::cout << " Power Value: " << powerValue << "\n";
		if (number <= powerValue) {
			basePower = i;
			break;
		}
	}

	if (number > powerValue) std::cout << "Number is too large\n";
	else {
		int baseSize = basePower;
		std::cout << "Top Base Power: " << baseSize << "\n";
		std::vector<int> numbers;
		
		int n;
		for (int i = 0; i < baseSize; i++){
			std::cout << number << " ";
			n = number%4;
			if(isMultipleOf4(number) && !multipleCalled){
				n = 1;
				multipleCalled = true;
			}
			numbers.push_back(n);
			if(number == 4) break;
			else number /= 4;
		}

		std::cout << "Vector Size: " << numbers.size() << "\n";
		unsigned size = numbers.size();
		for (unsigned i = 0; i < size; i++) {
			n = numbers.back();
			numbers.pop_back();
			if (n == 0) std::cout << "A";
			else if (n == 1) std::cout << "B";
			else if (n == 2) std::cout << "C";
			else if (n == 3) std::cout << "D";
		}
	}
}

bool Base4::isMultipleOf4(unsigned number){
	unsigned base = 4, baseTotal = 1;
	for(int i = 0; i < 16; i++){
		baseTotal *= base;
		if(number == baseTotal) return true;
	}
	return false;
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
63 = DDD
*/

//z = d*q + r
//z = dividend, d = divisor, q = quotient, r = remainder
