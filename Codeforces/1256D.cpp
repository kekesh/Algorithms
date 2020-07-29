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


ll dp[200005][3];
bool possible[200005][3];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int q;
		cin >> q;
		while (q--) {
				ll N, K;
				cin >> N >> K;
				string s;
				cin >> s;
				ll shift = 0;
				int i;
				while (shift < N && s[shift] == '0') {
						shift++;
				}

				for (i = 0; i < N - 1 && K > 0; i++) {
						if (s[i] == '1' && s[i + 1] == '0') {
								// s[i + 1] -> s[shift].
								ll cost = i + 1 - shift;
								if (K > cost) {
										swap(s[i + 1], s[shift]);
										shift++;
										K -= cost;
								} else {
										swap(s[i + 1], s[i + 1 - K]);
										K = 0;
								}
						}
				}
				cout << s << endl;
		}
}
