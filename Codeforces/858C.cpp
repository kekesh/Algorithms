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

inline bool vowel(char x) {
		return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

bool space[3001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		unordered_set<char> seen;
		int cc = 0, dc = 0;

		string s;
		cin >> s;

		for (int i = 0; i < (int) s.size(); i++) {
				if (!vowel(s[i])) {
						cc++;
						dc += (seen.find(s[i]) == seen.end());
						seen.insert(s[i]);
						if (cc >= 3 && dc >= 2) {
								space[i] = true;
								seen.clear();
								cc = dc = 1;
								seen.insert(s[i]);
						}
				} else {
						cc = dc = 0;
						seen.clear();
				}
		}

		string ans = "";
		for (int i = 0; i < (int) s.size(); i++) {
				if (space[i]) {
						ans += " ";
				}
				ans += s[i];
		}
		cout << ans << endl;
}
