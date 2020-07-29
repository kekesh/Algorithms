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


ll H, W;
ll dp[3001][3001];
pi parent[3001][3001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		string s1, s2;
		cin >> s1 >> s2;

		// dp[i][j] = LCS considering s1[1...i] and s2[1..j]

		// LCS(i, j) = 1 + LCS(i - 1, j - 1) if s1[i] == s2[j]
		// LCS(i, j) = MAX(LCS(i - 1, j), LCS(i, j - 1)) if s1[i] != s2[j]

		for (int i = 1; i <= (int) s1.size(); i++) {
				for (int j = 1; j <= (int) s2.size(); j++) {
						if (s1[i - 1] == s2[j - 1]) {
								dp[i][j] = 1 + dp[i - 1][j - 1];
								parent[i][j] = mp(i - 1, j - 1);
						} else {
								if (dp[i - 1][j] < dp[i][j - 1]) {
										dp[i][j] = dp[i][j - 1];
										parent[i][j] = mp(i, j - 1);
								} else {
										dp[i][j] = dp[i - 1][j];
										parent[i][j] = mp(i - 1, j);
								}
						}
				}
		}
		int N = s1.size();
		int M = s2.size();

		string ans = "";

		pi pos = mp(N, M);

		while (pos.f != 0 && pos.s != 0) {
				if (parent[pos.f][pos.s].f == pos.f - 1 && parent[pos.f][pos.s].s == pos.s - 1) {
						ans += s1[pos.f - 1];
				}
				pos = parent[pos.f][pos.s];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
}
