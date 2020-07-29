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
typedef vector<ll> vll;

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

string s;


int main() {
		ll N, L, R, X;
		cin >> N >> L >> R >> X;
		vector<ll> A(N);
		F0R(i, N) cin >> A[i];
		ll count = 0;
		for (int bitmask = 0; bitmask < (1 << N); bitmask++) {
				ll mini = INF;
				ll maxi = -INF;
				ll sum = 0;
				for (int j = 0; j < N; j++) {
						if (bitmask & (1 << j)) {
								// included
								sum += A[j];
								mini = MIN(mini, A[j]);
								maxi = MAX(maxi, A[j]);
						}
				}

				if (sum >= L && sum <= R && maxi - mini >= X) {
						count++;
				}
		}
		cout << count << endl;
}
