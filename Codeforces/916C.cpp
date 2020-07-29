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
bool is_prime[200000];

void sieve() {
		memset(is_prime, true, sizeof(is_prime));
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i <= 200000; i++) {
				if (is_prime[i] && (ll) i * i <= 200000) {
						for (int j = i * i; j <= 200000; j += i) {
								is_prime[j] = false;
						}
				}
		}
}


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> M;

		sieve();

		// First of all, let's place all of the edges in the MST.
		ll s = 2*(N - 2);
		int idx = s + 3;
		while (!is_prime[idx]) {
				idx++;
		}
		// idx is a prime number.
		if (M > 1) cout << 2 << " " << idx << endl;
		else cout << 2 << " " << 2 << endl;

		cout << 1 << " " << N << " " << 2 << endl;
		M--;

		for (int i = 2; i <= N - 2; i++) {
				cout << 1 << " " << i << " " << 2 << endl;
				M--;
		}

		// We've placed every edge, except one.
		// This last edge has to be so that, when added to s, it becomes a prime.

		/* At this point, idx is a prime number. */
		if (M > 0) cout << 1 << " " << N - 1 << " " << (idx - s) << endl;
		if (M > 0) M--;

		// If we're a tree, then we're done. Otherwise, we need everything else to be more than idx. 
		// We've exhausted all edges of the form (1, x).

		for (int i = 2; i <= N && M > 0; i++) {
				for (int j = i + 1; j <= N && M > 0; j++) {
						cout << i << " " << j << " " << idx + 1 << endl;
						M--;
				}
		}
}
