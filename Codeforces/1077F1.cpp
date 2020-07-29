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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ifstream fin("redistricting.in");
ofstream fout("redistricting.out");

template<class T> struct MinDeque { 
    int lo = 0, hi = -1;
    deque<pair<T,int>> d;
    
    void ins(T x) { // add to back
        while (sz(d) && d.back().f >= x) d.pop_back();
        d.pb({x,++hi});
    }
    
    void del() { // delete from front
        if (d.front().s == lo) {
				d.pop_front();
		}
    }

	int size() {
			return hi - lo + 1;
	}
    
    T get() { 
        return sz(d) ? d.front().f : mp(MOD,MOD);
    }
	void debug() {
			cout << "lo: " << lo << " and hi: " << hi << endl;
	}

};

ll n, k, x;
ll dp[301][301];
int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n >> k >> x;
		vl a(n);
		F0R(i, n) cin >> a[i];
		if (n / k > x) {
				cout << -1 << endl;
				return 0;
		}
		for (int i = 1; i <= n; ++i) {
//				cout << "i = " << i << endl;
				for (int j = 1; j <= x; j++) {
						if (j > i) {
								break;
						}
						// dp[i][j] = 
						int lb = MAX(0, i - (k - 1) - 1);
						ll maxi = 0;

						if ((i - 1) / k > j - 1) {
								dp[i][j] = -INF;
//								cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " (LB was " << lb << ")" << endl;
								continue;
						}

						for (int z = i - 1; z >= lb; z--) {
								maxi = MAX(maxi, dp[z][j - 1]);
						}
						dp[i][j] = a[i - 1] + maxi;
//						cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " (LB was " << lb << ")" << endl;
				}
		}
		int lb = MAX(0, n - k + 1);

		ll ans = 0;
		for (int i = n; i >= lb; --i) {
				ans = MAX(ans, dp[i][x]);
		}

		cout << ans << endl;
}
