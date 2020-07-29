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

ll N, H, L, R;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		vector<ll> A(N), B(N), C(N);
		F0R(i, N) cin >> A[i];
		F0R(i, N) cin >> B[i];
		F0R(i, N) C[i] = A[i] - B[i];
		// a_i + a_j > b_i + b_j
		// count all (i,j) such that c_i + c_j > 0
		sort(C.begin(), C.end());

//		cout << "Printing transformed array\n";
/*		F0R(i, N) {
				cout << C[i] << " ";
		}
		cout << endl;
*/
		ll cnt = 0;
		for (int i = 0; i < N; i++) {
				if (C[i] > 0) {
//						cout << "when i = " << i << " we count the number of elements >= " << -C[i] << endl;
						// Count the number of elements geq -C[i]
						int lo = 0;
						int hi = i;
						int ans = -1;

						// binary search the smallest index k such that A[k] >= -C[i].
						while (lo <= hi) {
								int m = lo + (hi - lo)/2;
//								cout << "Checking " << C[m] << endl;
								if (C[m] <= -C[i]) {
										// we've gone too far down.
										lo = m + 1;
								} else {
										// C[m] >= -C[i]
										hi = m - 1; // good.. can we do better?
										ans = m;
								}
						}
//						cout << "Adding " << i - ans << endl;
						cnt += (i - ans);
				}
		}
		cout << cnt << endl;


}
