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


ll N;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N;
		vl A(N);
		F0R(i, N) cin >> A[i];

		vl best_heights;

		ll best_sum = 0;
		for (int peak = 0; peak < N; peak++) {
				ll s = 0;
				vl heights(N, 0);
				heights[peak] = A[peak];
				s += heights[peak];

				for (int i = peak - 1; i >= 0; i--) {
						heights[i] = MIN(A[i], heights[i + 1]);
						s += heights[i];
				}

				for (int i = peak + 1; i < N; i++) {
						heights[i] = MIN(heights[i - 1], A[i]);
						s += heights[i];
				}

				if (s > best_sum) {
						best_sum = s;
						best_heights = heights;
				}
		}

		F0R(i, N) {
				cout << best_heights[i] << " ";
		}
		cout << endl;
}
