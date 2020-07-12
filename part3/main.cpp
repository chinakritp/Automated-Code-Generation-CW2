/*
 * main.cpp
 *
 *  Part 3: Multiple Variables
 *  Author: Chinakrit Pipatupatum <cp4n17@soton.ac.uk>
 */

#include <iostream>
#include <string>
using namespace std;
#include "expression-templates.h"

int main() {

	printf("The expression is x + (y-2) * (z-3)\n");
	ADD< VAR< BOUNDS<0,5> >, MULTI< MINUS< VAR< BOUNDS<2,7> >, LIT<2> >, MINUS< VAR< BOUNDS<1,10> >, LIT<3> > > > exp;

	int inputs[3];
	int outputs[3];

	try {
		inputs[0] = 2;
		inputs[1] = 3;
		inputs[2] = 8;
		outputs[0] = exp.eval(inputs);

		inputs[0] = 0;
		inputs[1] = 6;
		inputs[2] = 6;
		outputs[1] = exp.eval(inputs);

		inputs[0] = 5;
		inputs[1] = 2;
		inputs[2] = 10;
		outputs[2] = exp.eval(inputs);

		for(int i = 0; i < 3; i++) {
			printf("outputs %d: %d\n", i, outputs[i]);
		}
	}catch(char const* error) {
		printf("Exception: %s", error);
	}


	return 0;
}
