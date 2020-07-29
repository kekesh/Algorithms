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
const ld PI = 4 * atan((ld)1);

ll A[100005];
ll dp[100005][2];
map<ll, ll> m;
ll N;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);


		vector<pi> arr;
		cin >> N;
		F0R(i, N) {
				cin >> A[i];
				m[A[i]]++;
		}

		for (auto p : m) {
				arr.pb(mp(p.f, p.s));
		}

		// dp[i][1] = max up to i if u take element
		// dp[i][0] = max up to i if u don't take element.
		for (int i = 1; i <= (int) arr.size(); i++) {
				ll num = arr[i - 1].f;
				ll freq = arr[i - 1].s;
				dp[i][0] = MAX(dp[i - 1][1], dp[i - 1][0]);
				
				if (i >= 1 && arr[i - 2].f + 1 != arr[i - 1].f) {
					dp[i][1] = MAX(dp[i - 1][0] + num * freq, dp[i - 1][1] + num * freq);
				} else {
					dp[i][1] = dp[i - 1][0] + num * freq;
				}
		}

		cout << MAX(dp[(int) arr.size()][0], dp[(int) arr.size()][1]) << endl;
}
