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
const int INFTY = 1e7;

ll N;
ll dp[100001];
int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);	
		cin >> N;
		vector<vi> AdjList(N);

		F0R(i, N - 1) {
				ll to;
				cin >> to;
				AdjList[to - 1].pb(i + 1);
		}

		queue<int> q;
		q.push(0);
		vector<int> d(N + 1, 2000000);
		unordered_map<int, int> cnt;
		d[0] = 0;
		cnt[d[0]]++;
		ll maxd = 0;
		while (!q.empty()) {
				int u = q.front();
				q.pop();
				F0R(i, (int) AdjList[u].size()) {
						int v = AdjList[u][i];
						if (d[v] == 2000000) {
								d[v] = d[u] + 1;
								cnt[d[v]]++;
								maxd = MAX(maxd, d[v]);
								q.push(v);
						}
				}
		}
		ll ans = 0;
		for (int i = 0; i <= maxd; i++) {
				if (cnt[i] & 1) ans++;
		}
		cout << ans << endl;
}
