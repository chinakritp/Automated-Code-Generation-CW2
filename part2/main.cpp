/*
 * main.cpp
 *
 *  Part 2: Bounds
 *  Author: Chinakrit Pipatupatum <cp4n17@soton.ac.uk>
 */

#include <iostream>
#include <string>
using namespace std;
#include "expression-templates.h"

int main() {

	const int lower_bounds = 0;
	const int upper_bounds = 5;
	printf("The expression is (x + 3) * (x + 5)\n");
	MULTI< ADD< VAR< BOUNDS< lower_bounds, upper_bounds > >, LIT<3> >, ADD< VAR< BOUNDS< lower_bounds, upper_bounds > >, LIT<5> > > exp;

	int variable = 3;
	printf("If bounds on x are (%d,%d), the bounds for expression will be (%d,%d)\n", lower_bounds, upper_bounds, exp.lower, exp.upper);
	printf("While x = %d", variable);

	try {
		printf(", the result is %d", exp.eval(variable));
	}catch(char const* error) {
		printf("\nException: %s", error);
	}


	return 0;
}
