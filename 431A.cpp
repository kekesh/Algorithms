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



int main()
{
	ll a1, a2, a3, a4;
	string keyString;
	cin >> a1 >> a2 >> a3 >> a4 >> keyString;
	//string keyString = to_string(key);
	//cout << "key string is " << keyString << endl;
	vector <int> keyVec;

	for (int i = 0; i < keyString.length(); i++) {
		keyVec.push_back(keyString.at(i) - 48);
	}

	int countOne = 0, countTwo = 0, countThree = 0, countFour = 0;
	for (int i = 0; i < keyVec.size(); i++) {
		if (keyVec.at(i) == 1) {
			countOne++;
			//cout << "incrementing one" << endl;
		}
		else if (keyVec.at(i) == 2) {
			countTwo++;
			//cout << "incrementing two" << endl;
		}
		else if (keyVec.at(i) == 3) {
			countThree++;
			//cout << "incrementing three" << endl;
		}
		else if (keyVec.at(i) == 4) {
			//cout << "incrementing four" << endl;
			countFour++;
		}
	}

	ll sum = 0;
	sum += countOne * a1 + countTwo * a2 + countThree * a3 + countFour * a4;
	cout << sum << endl;

	//cout << a1 << " " << a2 << " " << key << endl;

}