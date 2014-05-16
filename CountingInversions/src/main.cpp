/*
 * main.cpp
 *
 *  Created on: May 16, 2014
 *      Author: tika
 */

#include <iostream>
#include <cstdlib>
#include "CountingInversions.hpp"

using namespace std;

int main() {
	long int n = 10;

	int* input = new int[n];

	srand(time(NULL));

	int i;
	for(i = 0; i < n; i++) {
		input[i] = 1 + (rand() % 20);
		cout << input[i] << " ";
	}
	cout << endl;

	CountingInversions* c = new CountingInversions();
	int count = c->sortAndCount(input, 0, n-1);
	for(i = 0; i < n; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
	cout << count << endl;

	return 0;
}


