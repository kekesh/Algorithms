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

int fenwick[200000];

void insert(int idx, int value) {
		while (idx < 200000) {
				fenwick[idx] = max(fenwick[idx], value);
				idx += (idx & -idx);
		}
}

ll query(int idx) {
		ll s = 0;
		while (idx > 0) {
				s = MAX(s, fenwick[idx]);
				idx -= (idx & -idx);
		}
		return s;
}

int main() {
		ll n;
		cin >> n;
		vl a(n);
		set<ll> s;
		F0R(i, n) cin >> a[i], s.insert(a[i]);
		unordered_map<int, int> mapper;
		int start = 2;
		for (const auto& v : s) mapper[v] = start++;

		stack<int> result;
		for (int i = n - 1; i >= 0; i--) {
				insert(mapper[a[i]], i + 1);
				ll q = query(mapper[a[i]] - 1);
				ll num = (q == 0 ? -1 : q - i - 2);
				result.push(num);
		}
		while (!result.empty()) {
				cout << result.top() << " ";
				result.pop();
		}
		cout << endl;

}
