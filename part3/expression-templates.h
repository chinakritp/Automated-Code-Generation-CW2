/*
 * expression-templates.h
 *
 *  Part 3: Multiple Variables
 *  Author: Chinakrit Pipatupatum <cp4n17@soton.ac.uk>
 */

#ifndef EXPRESSION_TEMPLATES_H
#define EXPRESSION_TEMPLATES_H

template<int LOW, int UP>
class BOUNDS {
public:
	enum {
		lower = LOW,
		upper = UP
	};
};

template<int L, int R>
struct MIN {
	enum {
		minimum = ((L < R) ? L : R)
	};
};

template<int L, int R>
struct MAX {
	enum {
		maximum = ((L > R) ? L : R)
	};
};

template<int N>
struct LIT {
	enum {
		lower = N,
		upper = N
	};
	static inline int eval(int v[]) {
		return N;
	}
};

static int position = 0;

template<class B>
struct VAR {
	enum {
		lower = B::lower,
		upper = B::upper
	};
	static inline int eval(int v[]) {
		if(v[position] < B::lower || v[position] > B::upper) {
			throw "The input(s) is not in the specified input range (between bounds)";
		}else{
			int temp = position;
			position++;
			position = ((position > 2) ? 0 : position);
			return v[temp];
		}
	}
};

template<class L, class R>
struct ADD {
	enum {
		lower = L::lower + R::lower,
		upper = L::upper + R::upper
	};
	static inline int eval(int v[]) {
		return L::eval(v) + R::eval(v);
	}
};

template<class L, class R>
struct MINUS {
	enum {
		lower = L::lower - R::lower,
		upper = L::upper - R::upper
	};
	static inline int eval(int v[]) {
		return L::eval(v) - R::eval(v);
	}
};

template<class L, class R>
struct MULTI {
	enum {

		lower = MIN< MIN< L::lower * R::lower, L::lower * R::upper>::minimum, MIN< L::upper * R::lower , L::upper * R::upper >::minimum >::minimum,
		upper = MAX< MAX< L::lower * R::lower, L::lower * R::upper>::maximum, MAX< L::upper * R::lower , L::upper * R::upper >::maximum >::maximum
	};
	static inline int eval(int v[]) {
		return L::eval(v) * R::eval(v);
	}
};

template<class L, class R>
struct DIVIDE {
	enum {
		lower = MIN< MIN< L::lower / R::lower, L::lower / R::upper>::minimum, MIN< L::upper / R::lower , L::upper / R::upper >::minimum >::minimum,
		upper = MAX< MAX< L::lower / R::lower, L::lower / R::upper>::maximum, MAX< L::upper / R::lower , L::upper / R::upper >::maximum >::maximum
	};
	static inline int eval(int v[]) {
		return L::eval(v) / R::eval(v);
	}
};

#endif /* EXPRESSION_TEMPLATES_H_ */
