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

typedef string str;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);

// Start of code.

int main() {
	int N;
	bool fst = true;
	while (cin >> N, N != 0) {
		if (!fst) cout << endl;
		fst = false;
		bool exists = false;
		for (int abcde = 01234; abcde <= 98765/N; abcde++) {
			int fghij = abcde * N;
			int mask = (abcde < 10000);
			int tmp = abcde;
			while (tmp) {
				mask |= 1 << (tmp % 10);
				tmp /= 10;
			}
			tmp = fghij;
			while (tmp) {
				mask |= 1 << (tmp % 10);
				tmp /= 10;
			}
			if (mask == (1 << 10) - 1) {
				exists = true;
				printf("%0.5d / %0.5d = %d\n", fghij, abcde, N);
			}
		}
		if (!exists) cout << "There are no solutions for " << N << "." << endl;
	}
	return 0;
}
