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

int main() {
		string s1, s2;
		cin >> s1 >> s2;
		int have[26], need[26];
		memset(have, 0, sizeof(have));
		memset(need, 0, sizeof(need));
		ll qs = 0;
		for (int i = 0; i < (int) s1.size(); i++) {
				if (s1[i] == '?') {
						qs++;
						continue;
				}
				have[s1[i] - 'a']++;
		}

		for (int i = 0; i < (int) s2.size(); i++) {
				need[s2[i] - 'a']++;
		}

		ll lo = 0, hi = 1e6 + 2;
		ll ans = lo;
		while (lo <= hi) {
				ll suitability = (lo + hi)/2;

				ll s = 0;
				for (char c = 'a'; c <= 'z' && s <= qs; c++) {
						ll delta = 1ll * need[c - 'a'] * suitability - have[c - 'a'];
						s += MAX(delta, 0);
				}

				if (s > qs) {
						hi = suitability - 1;
				} else {
						lo = suitability + 1;
						ans = suitability;
				}
		}

		queue<char> q;
		for (char c = 'a'; c <= 'z'; c++) {
				ll delta = 1ll * need[c - 'a'] * ans - have[c - 'a'];
				for (int i = 0; i < delta; i++) {
						q.push(c);
				}
		}
		for (int i = 0; i < (int) s1.size(); i++) {
				if (s1[i] == '?' && !q.empty()) {
						s1[i] = q.front();
						q.pop();
				} else if (s1[i] == '?') {
						s1[i] = 'a';
				}
		}
		cout << s1 << endl;
}
