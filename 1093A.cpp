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
	ll N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int count = 0;
		while (x > 6) {
			x -= 6;
			count++;
		}
		count++;
		cout << count << endl;
	}
}