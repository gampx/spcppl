#pragma once

#include <random>
#include <spcppl/assert.hpp>

typedef std::mt19937 impl__Random;

inline impl__Random& randomEngine() {
	static std::random_device device;
	static impl__Random engine(device());
	return engine;
}

inline int randomInteger() {
	std::uniform_int_distribution<int> d;
	return d(randomEngine());
}

inline int randomInteger(int to) {
	SPCPPL_ASSERT(to > 0);
	std::uniform_int_distribution<int> d(0, to - 1);
	return d(randomEngine());
}

inline int randomInteger(int from, int to) {
	return from + randomInteger(to - from);
}
