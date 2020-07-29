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


ll N, M;
ll A[300005];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		int ans = 0;
		unordered_set<int> s;

		F0R(i, N) {
				cin >> A[i];
				if (s.find(A[i]) != s.end()) {
						s.clear();
						ans++;
						continue;
				}
				s.insert(A[i]);
		}

		s.clear();

		if (ans > 0) cout << ans << endl;
		else {
				cout << -1 << endl;
			   	return 0;
		}

		int start = 0;
		int left = ans;
		F0R(i, N) {
				ll x = A[i];
				if (left == 1) {
						cout << i + 1 << " " << N << endl;
						return 0;
				}

				if (s.find(x) != s.end()) {
						// got it.
						s.clear();
						left--;
						cout << start + 1 << " " << i + 1 << endl;
						start = i + 1;
						continue;
				}
				s.insert(x);
		}

}
