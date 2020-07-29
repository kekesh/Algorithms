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
typedef vector<ll> vll;

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
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

string s;


bool ab[100005][2];

int main() {
		cin >> s;
		int N = (int) s.size();

		for (int i = 1; i < N; i++) {
				ab[i][0] |= (ab[i - 1][0] || (s[i - 1] == 'A' && s[i] == 'B'));
		}

		for (int i = N - 2; i >= 0; i--) {
				ab[i][1] |= (ab[i + 1][1] || (s[i] == 'A' && s[i + 1] == 'B'));
		}

		for (int i = 0; i < N - 1; i++) {
				if (s[i] == 'B' && s[i + 1] == 'A') {
						bool ok = false;
						if (i + 2 < N) ok |= ab[i + 2][1];
						if (i - 1 >= 0) ok |= ab[i - 1][0];
						if (ok) {
								cout << "YES" << endl;
								return 0;
						}
				}
		}
		cout << "NO" << endl;
}
