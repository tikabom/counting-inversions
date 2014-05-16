/*
 * CountingInversions.hpp
 *
 *  Created on: May 16, 2014
 *      Author: tika
 */

#ifndef COUNTINGINVERSIONS_HPP_
#define COUNTINGINVERSIONS_HPP_


class CountingInversions {
public:
	int sortAndCount(int* input, long int start, long int end);
	int mergeAndCount(
			int* input, long int lStart, long int lEnd,
			long int rStart, long int rEnd);
};


#endif /* COUNTINGINVERSIONS_HPP_ */
