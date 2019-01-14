//#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;

using namespace std;

bool inSet(int a, vector<int> set);


int main()
{
	ll N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		vector <int> powersOfTwo;
		int maxPow = 1;
		powersOfTwo.push_back(maxPow);
		
		while (maxPow*2 <= x) {
			maxPow *= 2;
			//cout << "adding " << maxPow << " to the set " << endl;
			powersOfTwo.push_back(maxPow);
		}

		ll sum = x*(x + 1)/2;
		for (int k = 0; k < powersOfTwo.size(); k++) {
			sum -= (powersOfTwo.at(k) * 2);
		}
		cout << sum << endl;

	}
}

bool inSet(int a, vector<int> set) {
	for (int k = 0; k < set.size(); k++) {
		if (set.at(k) == a) {
			return false;
		}	
	}
	return true;
}