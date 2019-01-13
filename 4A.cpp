//#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
typedef long long ll;

using namespace std;

//ll gcd(ll a, ll b);
//bool isPrime(ll p);
//ll v(ll n);
//ll u(ll n);

int main()
{
	ll N;
	cin >> N;

	if (N < 3) {
		cout << "NO" << endl;
	}
	else if (N % 2 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


}