//============================================================================
// Name        : CountingInversions.cpp
// Author      : tika
// Version     :
// Copyright   : 
// Description : Counting inversions
//============================================================================

#include <iostream>
#include "CountingInversions.hpp"

using namespace std;

/*int CountingInversions::mergeAndCount(
		int* input, int* left, int* right,
		long int lSize, long int rSize) {

	int splitCount = 0;
	int i, j, k;
	i = j = 0;

	cout << "lsize: " << lSize << endl;
	cout << "rsize: " << rSize << endl;

	cout << "\narray: ";
	for(k = 0; k < lSize + rSize; k++) {
		if(j == rSize) {
			input[k] = left[i++];
		}
		else if(i == lSize) {
			input[k] = right[j++];
		}
		else if(left[i] <= right[j]) {
			input[k] = left[i++];
		}
		else {
			splitCount += (lSize - i);
			input[k] = right[j++];
		}
		cout << input[k] << " ";
	}
	cout << endl;

	return splitCount;
}

int CountingInversions::sortAndCount(
		int* input, long int n) {
	if(n == 1) {
		return 0;
	}

	long int lSize, rSize;
	rSize = n / 2;
	if(n % 2 == 0) {
		lSize = n / 2;
	}
	else {
		lSize = n / 2 + 1;
	}

	int* left = new int[lSize];
	int* right = new int[rSize];

	int i, j;
	j = 0;
	cout << "\nleft: ";
	for(i = 0; i < lSize; i++) {
		left[j] = input[i];
		cout << left[j++] << " ";
	}
	cout << endl;
	j = 0;
	cout << "\nright: ";
	for(i = lSize; i < n; i++) {
		right[j] = input[i];
		cout << right[j++] << " ";
	}
	cout << endl;

	int lCount, rCount, splitCount;
	lCount = CountingInversions::sortAndCount(left, lSize);
	rCount = CountingInversions::sortAndCount(right, rSize);
	splitCount = CountingInversions::mergeAndCount(input, left, right, lSize, rSize);

	return lCount + rCount + splitCount;
}*/

int CountingInversions::mergeAndCount(
		int* input, long int lStart, long int lEnd,
		long int rStart, long int rEnd) {
	int splitCount = 0;
	int n = lEnd - lStart + 1 + rEnd - rStart + 1;

	int* output = new int[n];

	int i, j, k;
	i = lStart;
	j = rStart;

	for(k = lStart; k <= rEnd; k++) {
		if(j > rEnd) {
			output[k] = input[i++];
		}
		else if(i > lEnd) {
			output[k] = input[j++];
		}
		else if(input[i] <= input[j]) {
			output[k] = input[i++];
		}
		else {
			output[k] = input[j++];
			splitCount += (lEnd - i + 1);
		}
	}

	for(k = lStart; k <= rEnd; k++) {
		input[k] = output[k];
	}

	return splitCount;
}

int CountingInversions::sortAndCount(int* input, long int start, long int end) {
	long int n = end - start + 1;

	if(n == 1) {
		return 0;
	}

	int lCount, rCount, splitCount;

	lCount = CountingInversions::sortAndCount(input, start, start + n/2 - 1);
	rCount = CountingInversions::sortAndCount(input, start + n/2 , end);
	splitCount = CountingInversions::mergeAndCount(input, start, start + n/2 - 1, start + n/2, end);

	return lCount + rCount + splitCount;
}
