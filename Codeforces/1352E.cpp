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

ll N, M, K, T;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> T;
		while (T--) {
				cin >> N;
				vl A(N);
				vl dp(N);
				int cnt[N + 5];
				memset(cnt, false, sizeof(cnt));

				F0R(i, N) {
						cin >> A[i], cnt[A[i]]++;
				}
				dp[0] = A[0];
				for (int i = 1; i < N; i++) {
						dp[i] = dp[i - 1] + A[i];
				}

				ll ans = 0;
				for (int l = 0; l < N; l++) {
						for (int r = l + 1; r < N; r++) {
								ll sum = dp[r];
								if (l - 1 >= 0) sum -= dp[l - 1];
								if (sum <= N && cnt[sum] > 0) {
										ans += cnt[sum];
										cnt[sum] = 0;
								} else if (sum > N) {
										break;
								}
						}
				}
				cout << ans << endl;
		}
}
