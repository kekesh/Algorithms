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



int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, K;
		cin >> N >> K;
		vector<ll> a(N);
		F0R(i, N) cin >> a[i];
		vector<ll> suffix(N, 0);
		vector<ll> maxi(N, 0);
		suffix[N - 1] = a[N - 1];
		for (int i = N - 2; i >= 0; i--) {
				suffix[i] = suffix[i + 1] + a[i];
				if (i + K <= N - 1) suffix[i] -= a[i + K];
		}

		maxi[N - 1] = suffix[N - 1];
		for (int i = N - 2; i >= 0; i--) {
				maxi[i] = MAX(suffix[i], maxi[i + 1]);
		}

		ll best = 0;
		ll L = -1;
		ll R = -1;
		ll want = 0;
		for (int i = 0; i < N; i++) {
				ll candidate = suffix[i];
				if (i + K < N) candidate += maxi[i + K];
				if (best < candidate) {
						L = i;
						want = candidate - suffix[i];
						best = candidate;
				}
		}

		for (int i = L + K; i < N; i++) {
				if (suffix[i] == want) {
						R = i;
						break;
				}
		}
		cout << L+1 << " " << R+1 << endl;
}
