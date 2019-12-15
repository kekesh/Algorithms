#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;

typedef pair<int, int> pi;
const ll INFTY = 10e8;

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

template <class T>
void ckmin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void ckmax(T &a, T b) {
  a = max(a, b);
}

int arr[5005];
bool visited[5005];

int main(void) {
	ll N;
	cin >> N;

	F0R(i, N) {
		cin >> arr[i+1];
	}

	int prevprev, prev, curr, fwd;

	F0R(i, N) {
		prevprev = arr[i+1];
		prev = arr[arr[i+1]];
		curr = arr[arr[arr[i+1]]];
		fwd = arr[arr[arr[arr[i+1]]]];
		if (prevprev == fwd && (fwd != curr) && (fwd != prev)) {
			cout << "YES" << endl; exit(0);
		}
	}
	cout << "NO" << endl;
	return 0;
}
