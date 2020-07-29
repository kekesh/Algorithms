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

ll prefix[100005][2];
ll suffix[100005][2];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		string s;
		cin >> s;
		int N = s.size();
		// prefix[i][0] is the number of lowercase letters in s[0...i].
		// prefix[i][1] is the number of uppercase letters in s[0...i].

		if (islower(s[0])) {
				prefix[0][0] = 1;
		} else {
				prefix[0][1] = 1;
		}

		for (int i = 1; i < N; i++) {
				prefix[i][0] = prefix[i - 1][0];
				prefix[i][1] = prefix[i - 1][1];

				if (islower(s[i])) prefix[i][0]++;
				else prefix[i][1]++;
		}

		// suffix[i][0] is the number of lowercase letters in s[N-1 ... i]
		// suffix[i][1] is the number of uppercase letters in s[N-1 ... i]

		if (islower(s[N - 1])) {
				suffix[N - 1][0] = 1;
		} else {
				suffix[N - 1][1] = 1;
		}


		for (int i = N - 2; i >= 0; i--) {
				suffix[i][0] = suffix[i + 1][0];
				suffix[i][1] = suffix[i + 1][1];
				if (islower(s[i])) suffix[i][0]++;
				else suffix[i][1]++;
		}
		
		ll best_cost = INF;
		for (int k = 0; k < N; k++) {
				ll cost = 0;
				if (k > 0) cost += prefix[k - 1][0];
				if (k < N - 1) cost += suffix[k + 1][1];
				best_cost = MIN(best_cost, cost);
		}
		cout << best_cost << endl;
}
