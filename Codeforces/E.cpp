#include <iostream>
#include <iomanip>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	long double C;
	cin >> C;
	// If x^2 + sqrt(x) = sqrt(x)(x^{3/2} + 1) = C, then 
	
	long double lo = 1, hi = 1e5;

	for (int t = 0; t < 100; ++t) {
		long double m = (lo + hi) / 2;
		if (m * m + sqrt(m) <= C) {
			lo = m;
		} else {
			hi = m;
		}
	}
	cout << setprecision(20) << lo << endl;
}
