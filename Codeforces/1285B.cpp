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

typedef pair<int, int> pi;

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

// Start of code.

int main() {
	long long t;
	cin >> t;
	while (t--) {
	  	long long n, yasser = 0, adel = -1e18;
	  	cin >> n;
	  	vector<long long> a(n);
	  	for (int i = 0; i < n; ++i) cin >> a[i], yasser += a[i];
	  
	  	vector<long long> dp1(n), dp2(n);
	  	dp1[0] = a[0];
	  	dp2[1] = a[1];
			adel = max(a[0], a[1]);
	  
	  	for (int i = 1; i < n - 1; ++i) {
	  		dp1[i] = max(dp1[i - 1] + a[i], a[i]);
	  		adel = max(adel, dp1[i]);
	  	}
	  
	  	for (int i = 2; i < n; ++i) {
	  		dp2[i] = max(dp2[i - 1] + a[i], a[i]);
	  		adel = max(adel, dp2[i]);
	  	}
	  	cout << (yasser > adel ? "YES" : "NO") << endl;
	}
}
