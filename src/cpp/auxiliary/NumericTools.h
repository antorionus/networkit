/*
 * NumericTools.h
 *
 *  Created on: 15.02.2013
 *      Author: Christian Staudt (christian.staudt@kit.edu)
 */

#ifndef NUMERICTOOLS_H_
#define NUMERICTOOLS_H_

#include <limits>



namespace Aux {

/**
 * Tools to deal with limited precision in numeric computations.
 */
namespace NumericTools {


static constexpr double machineEpsilon = std::numeric_limits<double>::epsilon();

static constexpr double acceptableError = 1e-12;

template <typename T>
bool willOverflow(const T& pX, const T& pValue, const T& pMax = std::numeric_limits<T>::max()) {
	return pMax - pValue < pX;
}

template <typename T>
bool willUnderflow(const T& pX, const T& pValue, const T& pMin = std::numeric_limits<T>::min()) {
	return pMin + pValue > pX;
}


/**
 * Test doubles for equality within a given error.
 */
bool equal(double x, double y, double error = acceptableError);

/**
 * Test doubles for equality within a given error.
 */
bool le(double x, double y, double error = acceptableError);

/**
 * Test doubles for equality within a given error.
 */
bool ge(double x, double y, double error = acceptableError);

} /* namespace NumericTools */

} /* namespace NetworKit */
#endif /* NUMERICTOOLS_H_ */
