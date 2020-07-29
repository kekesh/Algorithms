#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>
 
using namespace std;
 
using ll = long long;
using vl = vector<ll>;

const ll INF = 1e18 + 1;

long double solve(long long a, long long b, long long c) {
		long double afovercf = 1;
		for (int i = a + 1; i <= c; i++) {
				afovercf *= i;
		}

		long double cminusbfoveraminusbf = 1;
		for (int i = a - b + 1; i <= c - b; i++) {
				cminusbfoveraminusbf *= i;
		}
		return cminusbfoveraminusbf/afovercf;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, M, H;
		cin >> N >> M >> H;
		vl A(M);
		ll s = 0;
		for (int i = 0; i < M; i++) cin >> A[i], s += A[i];
		// 4 people total; 3 people in a team.
		// (2 choose 2) / (3 choose 2) = 0.666667. 

		if (N > s) {
				cout << -1 << endl;
				return 0;
		}
		cout << 1 - solve(s - A[H - 1], N - 1, s - 1) << endl;
//		long double den = choose(s - 1, N - 1);
//		long double num = choose(s - A[H - 1], N - 1); 

}
