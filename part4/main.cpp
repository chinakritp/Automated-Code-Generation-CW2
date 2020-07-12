/*
 * main.cpp
 *
 *  Part 4: Integer Declarations
 *  Author: Chinakrit Pipatupatum <cp4n17@soton.ac.uk>
 */

#include <iostream>
#include <string>
using namespace std;
#include "expression-templates.h"

int main() {

	printf("The expression is x + (y-2) * (z-3)\n");
	Type< ADD< VAR< IntDecl< BOUNDS<0,5> > >, MULTI< MINUS< VAR< IntDecl< BOUNDS<2,7> > >, LIT<2> >, MINUS< VAR< IntDecl< BOUNDS<1,10> > >, LIT<3> > > > > exp;

	string type[4] = {"char","unsignedint","int","long"};

	int inputs[3];
	int outputs[3];
	int type_outputs[3];

	try {
		inputs[0] = 2;
		inputs[1] = 3;
		inputs[2] = 8;
		outputs[0] = exp.eval(inputs);
		type_outputs[0] = val_type;

		inputs[0] = 0;
		inputs[1] = 6;
		inputs[2] = 6;
		outputs[1] = exp.eval(inputs);
		type_outputs[1] = val_type;

		inputs[0] = 5;
		inputs[1] = 2;
		inputs[2] = 10;
		outputs[2] = exp.eval(inputs);
		type_outputs[2] = val_type;

		for(int i = 0; i < 3; i++) {
			printf("outputs %d: %d type: %s\n", i, outputs[i], type[type_outputs[i]].c_str());
		}
	}catch(char const* error) {
		printf("Exception: %s", error);
	}


	return 0;
}
