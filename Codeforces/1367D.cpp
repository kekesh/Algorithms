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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll T;
		cin >> T;
		while (T--) {
				string s;
				cin >> s;
				sort(s.begin(), s.end(), greater<int>());
				ll m;
				cin >> m;
				vl b(m);
				ll c = 0;
				map<char, int> freq;
				F0R(i, m) cin >> b[i], c += (b[i] == 0);
				for (const auto& c : s) freq[c]++;
				string ans(m, ' ');
				int next_idx = 0;
				while (freq[s[next_idx]] < c) {
						next_idx++;
				}

				bool done = false;
				while (!done) {
						vl zeros;
						done = true;

						for (int i = 0; i < m; i++) {
								if (b[i] == 0) {
										done = false;
										zeros.pb(i);
										b[i] = INF;
								}
						}
						if (done) {
								break;
						}
						// b[zero] == zero.
						for (int i = 0; i < (int) zeros.size(); i++) {
								ans[zeros[i]] = s[next_idx];
						}

						ll c = 0;
						for (int i = 0; i < m; i++) {
								if (b[i] != INF) {
										for (int j = 0; j < (int) zeros.size(); j++) {
												b[i] -= abs(i - zeros[j]);
												c += (b[i] == 0);
										}
								}
						}
						freq[s[next_idx]] = 0;
						while (freq[s[next_idx]] < c) {
								next_idx++;
						}
				}
				cout << ans << endl;
		}
}
