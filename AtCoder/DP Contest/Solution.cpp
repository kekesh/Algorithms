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


ll N, dp[301][301];
ll ones;


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		F0R(i, N) {
				cin >> A[i];
				if (A[i] == 1) ones++;
		}

		// dp[i][j] = expected rolls to eat i sushi, j of which were in lone piles.
		// dp[i][j] = dp[i - 1][j] * (/i)
		for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= i; j++) {
						// p1 = probability of eating from a group of more than one sushi.
						ld p1 = (i - 1 - j)/(i - 1);

						// p2 = probability of eating from a group of one sushi alone.
						ld p2 = (j + 1)/(i - 1); 
						dp[i][j] = dp[i - 1][j] * p1 + dp[i - 1][j - 1] * p2;
				}
		}
}
