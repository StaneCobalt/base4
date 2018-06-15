#include "convertBase.h"
#include <iostream>
#include <stack>

ConvertBase::ConvertBase() { 
	this->base = 4;
}

ConvertBase::ConvertBase(unsigned base) { 
	this->base = base; 
}

unsigned ConvertBase::getBase() const { 
	return base;
}

void ConvertBase::setBase(unsigned base) {
	this->base = base;
}

void ConvertBase::toNewBase(unsigned input) {
	unsigned quotient = input/base;
	unsigned remainder = input%base;
	std::stack<char> output;
	
	output.push(getLetter(remainder));
	
	while(quotient > 0){
			remainder = quotient%base;
			output.push(getLetter(remainder));
			quotient /= base;
	}
	
	unsigned size = output.size();
	
	for(unsigned i = 0; i < size; i++){
		std::cout << output.top();
		output.pop();
	}
}

char ConvertBase::getLetter(unsigned n) {
	for(unsigned i = 0; i < base; i++){
		if(n == i) return 'A'+i;
	}
	return '\0';
}

/*	Formula used: z = d*q + r
	z = dividend (the input), d = divisor (the base), q = quotient, r = remainder
	example: 16/4 --> z = 16, d = 4, q = 4, r = 0 --> returns A
	4/4 --> z = 4, d = 4, q = 1, r = 0 --> returns A
	1/4 --> z = 1, d = 4, q = 0, r = 1 --> returns B
*/
