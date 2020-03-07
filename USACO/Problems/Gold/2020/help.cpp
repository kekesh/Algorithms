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
typedef vector<pi> vii;
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
const int INFTY = 2147483643;

// Start of code.
ifstream fin("help.in");
ofstream fout("help.out");

ll N;

vector<pair<int, int>> intervals;

int main() {
	fin >> N;

	F0R(i, N) {
		ll a, b;
		fin >> a >> b;
		intervals.pb(mp(a, b));
	}
	// bruteforce solution.
	ll sum = 0;
	for (int i = 0; i < (1 << N); i++) {
//		cout << "{";
		vector<pair<int, int>> subset;
		sum++;
		for (int j = 0; j < N; j++) {
			if (((1 << j) & i)) {
				subset.pb(intervals[j]);
//				cout << "(" << intervals[j].first << "," << intervals[j].second << "), ";
			}
		}
//		cout << "}" << endl;
	}
	fout << sum % MOD << endl;
	fout.close();

	return 0;
}
