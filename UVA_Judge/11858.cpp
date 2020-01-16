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

// Start of code.

ll merge(vector<ll>& arr, int l, int m, int r) {
	vector<ll> B(r - l + 1);
	int i = l, j = m + 1, k = 0;
	ll invs = 0;

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			B[k++] = arr[i++];
		} else {
			B[k++] = arr[j++];
			invs += (m - i + 1);
		}
	}
	while (i <= m) B[k++] = arr[i++];
	while (j <= r) B[k++] = arr[j++];

	FOR(i, l, r + 1) {
		arr[i] = B[i - l];
	}
	return invs;
}


ll mergesort(vector<ll>& arr, int l, int r) {
	ll inv = 0;
	if (r > l) {
		int m = l + (r - l)/2;
		inv += mergesort(arr, l, m);
		inv += mergesort(arr, m + 1, r);
		inv += merge(arr, l, m, r);
	}
	return inv;
}

ll inv_count(vector<ll>& arr) {
	return mergesort(arr, 0, arr.size() - 1);
}

int main() {
	ll N;
	while (cin >> N) {
		vector<ll> arr(N);
		F0R(i, N) cin >> arr[i];
		cout << inv_count(arr) << endl;
	}
	return 0;
}
