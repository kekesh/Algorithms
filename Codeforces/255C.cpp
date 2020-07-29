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
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;

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

ll N, M, K;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll T;
		cin >> T;
		// abbc is the maximum

		while (T--) {
				cin >> N >> K;
				string s;
				cin >> s;
				vector<string> buckets(K, "");

				sort(s.begin(), s.end());

				if (s[0] != s[K - 1]) {
						cout << s[K - 1] << endl;
				} else {
						
					if (s[K] == s[N - 1]) {
							// everything's equal.

						int diff = N - K;
						cout << s[0];
						for (int i = 0; i < diff/K; i++) {
								cout << s[K];
						}
						if (diff % K != 0) {
								cout << s[K];
						}
						cout << endl;
					} else {
						cout << s[0];

						for (int i = K; i < N; i++) {
								cout << s[i];
						}
						cout << endl;
					}
				}
		}
}
