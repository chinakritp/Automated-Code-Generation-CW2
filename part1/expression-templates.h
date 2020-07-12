/*
 * expression-templates.h
 *
 *  Part 1: Expression Templates
 *  Author: Chinakrit Pipatupatum <cp4n17@soton.ac.uk>
 */

#ifndef EXPRESSION_TEMPLATES_H
#define EXPRESSION_TEMPLATES_H

template<int N>
struct LIT {
	static inline int eval(int v) {
		return N;
	}
};

struct VAR {
	static inline int eval(int v) {
		return v;
	}
};

template<class L, class R>
struct ADD {
	static inline int eval(int v) {
		return L::eval(v) + R::eval(v);
	}
};

template<class L, class R>
struct MINUS {
	static inline int eval(int v) {
		return L::eval(v) - R::eval(v);
	}
};

template<class L, class R>
struct MULTI {
	static inline int eval(int v) {
		return L::eval(v) * R::eval(v);
	}
};

template<class L, class R>
struct DIVIDE {
	static inline int eval(int v) {
		return L::eval(v) / R::eval(v);
	}
};

#endif /* EXPRESSION_TEMPLATES_H_ */
