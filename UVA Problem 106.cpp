//#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
// Fermat vs. Pythagoras
// note: the O(n^3) solution is far too slow 
// we can improve runtime w/ Euclid's Formula

// Abbrevriations: PPT - primitive pythagorean triple.
//				   PT - pythagorean triple.


// Euclid's formula asserts that for coprime m,n and odd m-n (m^2-n^2, 2mn, m^2+n^2) form a PPT.

int gcd(int a, int b);

typedef long long INT;
INT N;

using namespace std;

int main()
{


	while (scanf("%lld",&N) == 1) {
		//int N;
		vector<int> numbers;
		int numSolutions = 0;
		//cin >> N;
		//cout << "N is " << N << endl;

		for (int n = 1; n*n < N; n++) {
			for (int m = n + 1; m*m <= N; m += 2) {
				int a = m * m - n * n;
				int b = 2 * m*n;
				int c = m * m + n * n;


				// EUCLID'S FORMULA DOES NOT PRODUCE EVERY PT; ONLY EVERY PPT.
				// wasted 3 hours because of ^

				if ((gcd(m, n) == 1) && (m - n) % 2 == 1 && (c <= N)) {
					//cout << "incrementing when (m, n) = " << m << " , " << n << endl;
					//cout << "incrementing when (a, b, c) = " << a << " , " << b << " , " << c << endl;
					numSolutions++;
					numbers.push_back(a);
					numbers.push_back(b);
					numbers.push_back(c);

					int constant = 1;
					while (c * constant <= N) {
						numbers.push_back(a*constant);
						numbers.push_back(b*constant);
						numbers.push_back(c*constant);
						constant++;
					}

				}
			}
		}

		//cout << "printing contents of size " << endl;

		//sort contents and erase duplicates
		sort(numbers.begin(), numbers.end());
		numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

		//cout << "size: " << numbers.size() << endl;

		//for (int k = 0; k < numbers.size(); k++) {
			//cout << numbers.at(k) << endl;
		//}

		int p = N - numbers.size();

		cout << numSolutions << " " << p << endl;
		//cout << "p = " << p << endl;

		numbers.clear();
	}

}
// euler's formula for gcd
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

//15139, 133926
