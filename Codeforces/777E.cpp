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

struct ring {
		ll a, b, h;
};

bool cmp(const ring& lhs, const ring& rhs) {
		return rhs.b < lhs.b;
}

ll N;

// maxi[i] = max height using first i towers when last tower had.

int maxi[1001][1001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N;
		vector<ring> A(N);
		set<int> s;
		map<int, int> m;
		F0R(i, N) {
				cin >> A[i].a >> A[i].b >> A[i].h;
				s.insert(A[i].a);
				s.insert(A[i].b);
		}
		int asdf = 1;
		for (auto v : s) m[v] = asdf++;
		F0R(i, N) {
				A[i].a = m[A[i].a];
				A[i].b = m[A[i].b];
		}

		sort(A.begin(), A.end(), cmp);
//		memset(maxi, -INFTY, sizeof(maxi));

		maxi[1][A[0].a] = A[0].h;
		maxi[1][0] = 0;

		for (int i = 2; i <= N; i++) {
				for (int j = 1; j <= asdf; j++) {
						maxi[i][j] = maxi[i - 1][j];
						if (j < A[i - 1].b) {
								maxi[i][A[i - 1].b] = MAX(maxi[i][A[i - 1].b], maxi[i][A[i - 1].b] + A[i - 1].h);
						}
						cout << "maxi[" << i << "][" << j << "] = " << maxi[i][j] << endl;
				}
		}
//		cout << "Done. Answer: " << ans << endl;
}
