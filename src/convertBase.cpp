#include "../include/convertBase.h"
#include <iostream>
#include <stack>

/* Default Constructor */
ConvertBase::ConvertBase() { 
	this->base = 4;
}

/* Initialized Constructor */
ConvertBase::ConvertBase(unsigned base) { 
	this->base = base; 
}

/* Accessor for base - read-only */
unsigned ConvertBase::getBase() const { 
	return base;
}

/* Mutator for base */
void ConvertBase::setBase(unsigned base) {
	this->base = base;
}

/*
 * Converts from decimal to a given base. Calls on getLetter() to get the result for each individual conversion.
 * Pre-Method: Base has been set by user, and user has supplied a number to convert.
 * Post-Method: Iterates through collected converted characters and outputs them.
*/
void ConvertBase::toNewBase(unsigned input) {
	unsigned quotient = input/base;
	std::stack<char> output;
	
	output.push(getLetter(input%base));
	
	while(quotient > 0){
			output.push(getLetter(quotient%base));
			quotient /= base;
	}
	
	while(!output.empty()){
		std::cout << output.top();
		output.pop();
	}
}

/*
 * Grabs a char starting with A for converting the number.
 * Example: If base 2 is chosen, the results will either be A for 0, or B for 1.
 * 	    If base 4 is chosen, the results could be A for 0, B for 1, C for 2, or D for 3
*/
char ConvertBase::getLetter(unsigned n) {
	return 'A'+n;
}

/*	Formula used: z = d*q + r
	z = dividend (the input), d = divisor (the base), q = quotient, r = remainder
	example: 16/4 --> z = 16, d = 4, q = 4, r = 0 --> returns A
	4/4 --> z = 4, d = 4, q = 1, r = 0 --> returns A
	1/4 --> z = 1, d = 4, q = 0, r = 1 --> returns B
	Result: BAA
*/
