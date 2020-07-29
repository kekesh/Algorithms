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

ll N, T, K;

int main() {
		cin >> T;
		while (T--) {
				cin >> N >> K;

				if (N == 0) {
						// sum of first (K - 1) perfect squares.
						unsigned long long ans = K;
						ans = (ans * K - K) % MOD;
						cout << ans << endl;
						continue;
				}

				// before discovery time.
				unsigned long long time = N * (N - 1) % MOD;
//				cout << "Before discovery time: " << time << endl;

				// we add LEN[1, N] for 1, 2, 4, 6, .......
				time = (time + N) % MOD;
				unsigned long long toadd = (N*(K / 2)) % MOD;
				time = (time + toadd) % MOD;
//				cout << "After adding all of the LEN[1, N]s: " << time << endl;


				// we add LEN[N, end] + LEN[end, N] for 3, 5, 7, ...
				unsigned long long asdf = (K - 1)/2;
				unsigned long long mul = (asdf * (asdf + 1)) % MOD;
				if (K >= 3) time = (time + mul) % MOD;
//				cout << "After adding LEN[N,end] + LEN[end,N]: " << time << endl;

				// for visit 2, 3, 5, 7, ... we need to add the time to go back from N to 1.
				if (K >= 1) time = (time + N*(K/2)) % MOD;

				cout << time << endl;
//				cout << "After adding LEN[N, 1]s: " << time << endl;

		}
}
