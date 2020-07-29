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
 
const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
 
void print_path(const vl& P, int u) {
		if (P[u] == u) {
				cout << u << " ";
				return;
		}
		print_path(P, P[u]);
		cout << u << " ";
}	

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		ll N, M;
		cin >> N >> M;
		vector<vector<pl>> A(N + 1);
		F0R(i, M) {
				ll a, b, w;
				cin >> a >> b >> w;
				A[a].pb(mp(b, w));
				A[b].pb(mp(a, w));
		}
		vl d(N + 1, INF);
		vl P(N + 1, 0);
		priority_queue<pl, vector<pl>, greater<pl>> pq;
		d[1] = 0;
		P[1] = 1;
		pq.push(mp(0, 1));

		while (!pq.empty()) {
				pl next = pq.top();
				pq.pop();
				ll u = next.s, dist = next.f;
				if (dist > d[u]) {
						continue;
				}
				if (u == N) break;

				for (auto v : A[u]) {
						if (d[v.f] > dist + v.s) {
								d[v.f] = dist + v.s;
								P[v.f] = u;
								pq.push(mp(d[v.f], v.f));
						}
				}
		}
		if (d[N] == INF) {
				cout << -1 << endl;
				return 0;
		}

		print_path(P, N);
		cout << endl;

}
		
