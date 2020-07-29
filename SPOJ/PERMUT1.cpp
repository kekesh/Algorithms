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


ll T, N, K;
ll ways[22][199]; // dp[i][j] = # permutations of {1, ..., i} with j inversions

void preprocess() {
		ways[0][0] = ways[1][0] = 1;
		for (int i = 2; i <= 20; i++) {
				for (int j = 0; j <= i*(i - 1)/2; j++) {
						for (int x = 1; x <= i; x++) {
								if (j - x + 1 >= 0) ways[i][j] += ways[i - 1][j - (x - 1)];
						}
				}
		}
}

int main() {
		cin >> T;
		preprocess();
		while (T--) {
			cin >> N >> K;
			cout << ways[N][K] << endl;
		}
}
