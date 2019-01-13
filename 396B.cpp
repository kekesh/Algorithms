//#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b);
bool isPrime(ll p);
ll v(ll n);
ll u(ll n);

int main()
{
	int numTestCases;
	cin >> numTestCases;

	for (int z = 0; z < numTestCases; z++) {

		ll N;
		cin >> N;

		//vector<int> primes;

		//int abc = v(N);
		//int def = u(N);
		//int count = 0;
		//for (int i = 0; i < 200; i++) {
			//if (isPrime(i)) {
				//cout << i << " is prime" << endl;
				//count++;
			//}
		//}
		//cout << " total of " << count << endl;


		//int num = (v(N)*u(N)*v(N) - 2*v(N)*u(N)*v(N) + 2*v(N));
		//cout << "when N = " << N << " we have u(N) = " << u(N) << " and v(N) = " << v(N) << endl;
		ll num = u(N)*v(N) + 2 * N - 2 * u(N) - 2 * v(N) + 2;
		ll den = 2 * u(N)*v(N);
		ll factor = gcd(num, den);

		cout << num / factor << "/" << den / factor << endl;

		//int factor = gcd(num, den);
	}
}

ll v(ll n) {
	if (isPrime(n)) {
		return n;
	}
	if (n <= 1) {
		return 1;
	}
	if (isPrime(n - 1)) {
		return (n - 1);
	}
	else {
		return v(n - 1);
	}
}

ll u(ll n) {
	if (isPrime(n + 1)) {
		return (n + 1);
	}
	else {
		return u(n + 1);
	}
}


ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

//bool isOdd(int x) {
	//return x % 2 == 0 ? false : true;
//}

bool isPrime(ll p) {
	//AKS Primality Test; runtime O(log(n)^(12)).
	//cout << "Checking if p = " << p << " is prime." << endl;
	if (p <= 1) {
		return false;
	}
	if (p <= 3) {
		return true;
	}

	//so we can increment by 5
	if (p % 2 == 0 || p % 3 == 0) {
		return false;
	}

	//cout << "looping to " << sqrt(p) + 1 << endl;

	for (int i = 5; i < (int) sqrt(p) + 1; i += 2) {
		if (p % i == 0) {
			return false;
		}
	}
	
	//cout << "the number " << p << " is prime." << endl;
	
	return true;
}