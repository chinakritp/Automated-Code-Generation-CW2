/*
 * main.cpp
 *
 *  Part 1: Expression Templates
 *  Author: Chinakrit Pipatupatum <cp4n17@soton.ac.uk>
 */

#include <iostream>
#include <string>
using namespace std;
#include "expression-templates.h"

int main() {

	printf("The expression is x + (x-2) * (x-3)\n");
	ADD< VAR, MULTI< MINUS< VAR, LIT<2> >, MINUS< VAR, LIT<3> > > > exp;

	int variable = 7;
	printf("with x = %d, the result is %d", variable, exp.eval(variable));

}


