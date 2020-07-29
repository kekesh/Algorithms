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
typedef vector<string> vs;
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
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


bitset<1'000'001> is_prime;
//bool is_prime[1000001];
//vector<bool> is_prime(1'000'001, true);

void sieve() {
		is_prime.flip();
//		memset(is_prime, true, sizeof(is_prime));
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i <= 1'000'000; ++i) {
//				if (i % 1000 == 0) cout << "i = " << i << endl;
				if (is_prime[i] && (long long) i * i <= 1'000'000) {
						for (int j = i * i; j <= 1'000'000; j += i) {
								is_prime[j] = false;
						}
				}
		}
}

bool check(ll l, ll a, ll b, ll k) {
		ll count = 0;
		bool ok = true;
		for (int i = a; i <= b && ok; ++i) {
//				cout << "Next iteration" << endl;
//				cout << "Inserting " << i << endl;
				count += is_prime[i];
				if (i >= a + l - 1) {
//						cout << "Checking if current interval is OK." << endl;
						ok &= count >= k;
//						cout << "Evicting " << i - l + 1 << endl;
						count -= is_prime[i - l + 1];
				}

		}
		return ok;	
}

int main() {
		ll a, b, k;
		cin >> a >> b >> k;
		sieve();
//		cout << "Done" << endl;

		ll lo = 1, hi = b - a + 1;
		ll ans = -1;
		while (lo <= hi) {
				ll m = (lo + hi)/2;
//				cout << "Checking " << m << endl;
				if (check(m, a, b, k)) {
						ans = m;
						hi = m - 1;
				} else {
						lo = m + 1;
				}
		}
		cout << ans << endl;
}
