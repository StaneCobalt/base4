#include <iostream>
#include <stack>

void toBase4(unsigned z, unsigned d);
char getLetter(unsigned n);

int main(int argc, char** argv){
	unsigned input;
	std::cout << "Enter an integer(+): ";
	std::cin >> input;
	toBase4(input, 4);
	std::cout << std::endl;
	return 0;
}

void toBase4(unsigned z, unsigned d){
	unsigned q = z/d, r = z%d;
	std::stack<char> output;
	output.push(getLetter(r));
	while(q > 0){
			r = q%d;
			output.push(getLetter(r));
			q /= d;
	}
	int size = output.size();
	for(int i = 0; i < size; i++){
		std::cout << output.top();
		output.pop();
	}
}

char getLetter(unsigned n){
	if (n == 0) return 'A';
	else if (n == 1) return 'B';
	else if (n == 2) return 'C';
	else if (n == 3) return 'D';
	return '\0';
}
/*	Formula used: z = d*q + r
	z = dividend, d = divisor, q = quotient, r = remainder
	example: 16/4 --> z = 16, d = 4, q = 4, r = 0 --> returns A
	4/4 --> z = 4, d = 4, q = 1, r = 0 --> returns A
	1/4 --> z = 1, d = 4, q = 0, r = 1 --> returns B
*/

/*	Pattern:
	4^0 4^1 4^2 4^3 ... 4^n
	0 = A
	1 = B
	2 = C
	3 = D
	4 = BA
	5 = BB
	...
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
