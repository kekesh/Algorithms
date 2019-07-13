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

//ll gcd(ll a, ll b);
//bool isPrime(ll p);
//ll v(ll n);
//ll u(ll n);

int main()
{
	string N1, N2;
	cin >> N1 >> N2;
	//cout << "N1 is " << N1 << endl;
	//vector<bool> num1 = 

	vector<int> vec1, vec2;

	for (int i = 0; i < N1.length(); i++) {
		vec1.push_back((int) N1.at(i));
	}

	for (int i = 0; i < N2.length(); i++) {
		vec2.push_back((int)N2.at(i));
	}

	string ans = "";

	for (int i = 0; i < vec1.size(); i++) {
		if (!(vec1.at(i) == vec2.at(i))) {
			ans += "1";
		}
		else {
			ans += "0";
		}
	}
	cout << ans << endl;
}