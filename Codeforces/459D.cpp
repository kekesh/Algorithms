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
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ll N, M, T;

ll fen[1000005];
ll input[1000005];
ll A[1000005];
ll B[1000005];

void update(int num, int idx) {
		for (int i = idx; i <= 1000003; i += (i & -i)) {
				fen[i] += num;
		}
}

ll sum(int idx) {
		ll ans = 0;
		for (int i = idx; i > 0; i -= (i & -i)) {
				ans += fen[i];
		}
		return ans;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		set<ll> tmp;
		unordered_map<ll, ll> compress;
		int idx = 2;

		F0R(i, N) {
				cin >> input[i];
				tmp.insert(input[i]);
		}
		for (auto v : tmp) compress[v] = idx++;

		unordered_map<ll, ll> prefix, suffix;

		F0R(i, N) {
				int j = (N - 1) - i;
				prefix[compress[input[i]]]++;
				suffix[compress[input[j]]]++;
				A[i] = prefix[compress[input[i]]];
				B[j] = suffix[compress[input[j]]];
		}

		ll ans = 0;
		for (int i = N - 1; i >= 0; i--) {
				ans += sum(A[i] - 1);
				update(1, B[i]);
		}
		cout << ans << endl;
}
