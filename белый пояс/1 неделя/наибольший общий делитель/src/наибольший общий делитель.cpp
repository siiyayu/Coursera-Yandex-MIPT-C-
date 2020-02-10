//============================================================================
// Name        : наибольший.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector <int> x, y;
	int k, c;
	int d = 2;
	int i = 0;
	for (k = a; k != b; k = b) {
		c = k;
		while (c != 1) {
			if (c%d == 0) {
				x[i] = d;
				c = c/d;
				i += 1;
			} else d +=1;
			}
	}
	for (i = 0; i < x.size(); ++i) {
		cout << x[i] << ' ';
	}
	return 0;
}
