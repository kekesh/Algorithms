#include <assert.h>
#include <math.h>
#include <complex>
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

ll D[1001];
ll C[1001][1001];

ll N, K;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> K;
		C[0][0] = 1;
		for (int n = 1; n <= N; n++) {
				C[n][0] = C[n][n] = 1;
				for (int k = 1; k <= N; k++) {
						C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
				}
		}
		D[0] = 1;
		D[1] = 0;
		D[2] = 1;
		D[3] = 2;
		D[4] = 9;
		ll ans = 0;
		for (int fixed = N - K; fixed <= N; fixed++) {
				assert(N - fixed <= 4);
				ll contrib = C[N][fixed] * D[N - fixed]; // k elements stay the same.
				// N - k elements are permuted, but we can't have any fixed points.
				// multiply by Derangements[N - k]
				ans += contrib;
		}
		cout << ans << endl;
}
