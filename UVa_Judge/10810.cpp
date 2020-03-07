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


ll merge(vector<ll> &A, int l, int m, int r) {
	vector<ll> B(r - l + 1);
	ll i = l, j = m + 1, k = 0;
	ll inversions = 0;

	while (i <= m && j <= r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		} else {
			B[k++] = A[j++];
			// A[j] > A[i].
			inversions += (m - i + 1);
		}
	}

	while (i <= m) B[k++] = A[i++];
	while (j <= r) B[k++] = A[j++];

	for (int i = l; i <= r; i++) {
		A[i] = B[i - l];
	}

	return inversions;
}


ll mergesort(vector<ll> &A, int l, int r) {

	ll inversions = 0;

	if (r > l) {
		int m = l + (r - l)/2;
		inversions += mergesort(A, l, m);
		inversions += mergesort(A, m + 1, r);
		inversions += merge(A, l, m, r);
	}

	return inversions;
}


ll inversion_count(vector<ll>& A) {
	return mergesort(A, 0, A.size() - 1);
}

int main() {

	ll N;
	while (cin >> N, N != 0) {
		vector<ll> arr(N);
		F0R(i, N) cin >> arr[i];
		cout << inversion_count(arr) << endl;

	}
	return 0;
}
