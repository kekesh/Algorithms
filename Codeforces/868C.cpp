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
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

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
 
const int MOD = 1000000007;  // 998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);

ll N, M;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, K;
		cin >> N >> K;
		set<int> in;
		F0R(i, N) {
				int b = 0;
				F0R(j, K) {
						char c;
						cin >> c;
						if (c == '1') {
								b |= (1 << (K - j - 1));
						}
				}
				in.insert(b);
		}
		if (in.find(0) != in.end()) {
				cout << "YES" << endl;
				return 0;
		}

		for (int i = 0; i < K; i++) {
				int mask = (1 << i);
				if (in.find(mask) != in.end()) {
						// exists
						for (auto v : in) {
								if ((v & (1 << i)) == 0) {
										cout << "YES" << endl;
										return 0;
								}
						}
				}
		}

		if (K & 1) {
				cout << "NO" << endl;
				return 0;
		}

		if (K == 2) {
				if (in.find(2) != in.end() && in.find(1) != in.end()) {
						cout << "YES" << endl;
						return 0;
				} else {
						cout << "NO" << endl;
						return 0;
				}
		} else {
				// k == 4
				// 1100 and 0011
				// 1010 and 0101
				// 1001 and 0110
				
				bool ok = false;
				ok |= (in.find(12) != in.end() && in.find(3) != in.end());
				ok |= (in.find(10) != in.end() && in.find(5) != in.end());
				ok |= (in.find(9) != in.end() && in.find(6) != in.end());
				if (ok) cout << "YES" << endl;
				else cout << "NO" << endl;
		}
}
