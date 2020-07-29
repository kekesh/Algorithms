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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline bool check(ll mid, ll a, ll b, ll c) {
		int partition[3];
		partition[0] = partition[1] = partition[2] = 0;
		partition[0] += MIN(a, mid);
		a -= MIN(a, mid);
		if (partition[0] < mid) {
				ll delta = MIN(b, mid - partition[0]);
				partition[0] += delta;
				b -= delta ;
		}

		if (a > 0) {
				ll delta = MIN(a, mid);
				partition[1] += delta;
				a -= delta;
				if (partition[1] < mid) {
						ll delta = MIN(b, mid - partition[1]);
						partition[1] += delta;
						b -= delta;
						// it's full
						return (b + c <= mid);
				} else {
						return (a == 0 && b + c <= mid);
				}
		}
		return (b + c <= 2*mid);
}

int main() {
		ll t;
		scanf("%I64d", &t);
		while (t--) {
				ll a, b, c;
				scanf("%I64d %I64d %I64d", &a, &b, &c);
				
				ll lo = 1, hi = a + b + c;
				ll ans = a + b + c;
				while (lo <= hi) {
						ll mid = (lo + hi)/2;
						if (check(mid, a, b, c)) {
								// worsk
								hi = mid - 1;
								ans = mid;
						} else {
								lo = mid + 1;
						}
				}
				cout << ans << endl;
		}
}
