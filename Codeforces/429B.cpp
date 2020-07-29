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
 
const int MOD = 1000000007;  // 998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);


ll A[1001][1001];
ll dp1[1001][1001];
ll dp2[1001][1001];
ll dp3[1001][1001];
ll dp4[1001][1001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, M;
		cin >> N >> M;
		F0R(i, N) F0R(j, M) cin >> A[i][j];

		// dp2 is top left to bottom right
		dp2[0][0] = A[0][0];
		for (int i = 1; i < M; i++) {
				dp2[0][i] = dp2[0][i - 1] + A[0][i];
		}
		for (int i = 1; i < N; i++) {
				dp2[i][0] = dp2[i - 1][0] + A[i][0];
		}
		for (int i = 1; i < N; i++) {
				for (int j = 1; j < M; j++) {
						dp2[i][j] = MAX(dp2[i - 1][j], dp2[i][j - 1]) + A[i][j];
				}
		}
/*		cout << "Printing dp2 (top left to bottom right)" << endl;
		F0R(i, N) {
				F0R(j, M) {
						cout << dp2[i][j] << " ";
				}
				cout << endl;
		}
*/
		// dp1 is bottom left to top right
		dp1[N - 1][0] = A[N - 1][0];
		for (int i = 1; i < M; i++) {
				dp1[N - 1][i] = dp1[N - 1][i - 1] + A[N - 1][i];
		}
		for (int i = N - 2; i >= 0; i--) {
				dp1[i][0] = dp1[i + 1][0] + A[i][0];
		}
		for (int r = N - 2; r >= 0; r--) {
				for (int c = 1; c < M; c++) {
						dp1[r][c] = MAX(dp1[r + 1][c], dp1[r][c - 1]) + A[r][c];
				}
		}

/*		cout << "Printing dp1 (bottom left -> top right)" << endl;
		F0R(i, N) {
				F0R(j, M) {
						cout << dp1[i][j] << " ";
				}
				cout << endl;
		}
*/
		// dp3 is top right to bottom left
		dp3[0][M - 1] = A[0][M - 1];
		for (int r = 1; r < N; r++) {
				dp3[r][M - 1] = dp3[r - 1][M - 1] + A[r][M - 1];
		}
		for (int c = M - 2; c >= 0; c--) {
				dp3[0][c] = dp3[0][c + 1] + A[0][c];
		}

		for (int r = 1; r < N; r++) {
				for (int c = M - 2; c >= 0; c--) {
						dp3[r][c] = MAX(dp3[r - 1][c], dp3[r][c + 1]) + A[r][c];
				}
		}

/*		cout << "Printing dp3 (top right -> bottom left)" << endl;
		F0R(i, N) {
				F0R(j, M) {
						cout << dp3[i][j] << " ";
				}
				cout << endl;
		}
	*/	
		// dp4 is from bottom right to top left.
		dp4[N - 1][M - 1] = A[N - 1][M - 1];
		for (int r = N - 2; r >= 0; r--) {
				dp4[r][M - 1] = dp4[r + 1][M - 1] + A[r][M - 1];
		}
		for (int c = M - 2; c >= 0; c--) {
				dp4[N - 1][c] = dp4[N - 1][c + 1] + A[N - 1][c];
		}

		for (int r = N - 2; r >= 0; r--) {
				for (int c = M - 2; c >= 0; c--) {
						dp4[r][c] = MAX(dp4[r + 1][c], dp4[r][c + 1]) + A[r][c];
				}
		}
/*		cout << "Printing dp4 (bottom right to top left)" << endl;
		F0R(i, N) {
				F0R(j, M) {
						cout << dp4[i][j] << " ";
				}
				cout << endl;
		}
*/

		ll best = 0;
		FOR(i, 1, N - 1) {
				FOR(j, 1, M - 1) {
						ll c1 = dp1[i][j - 1] + dp3[i][j + 1]; // p1 goes through to the right.
						ll c2 = dp2[i - 1][j] + dp4[i + 1][j]; // p2 goes downwards.
						best = MAX(best, c1 + c2);

						c1 = dp1[i + 1][j] + dp3[i - 1][j];
						c2 = dp2[i][j - 1] + dp4[i][j + 1];

						best = MAX(best, c1 + c2);
				}
		}
		cout << best << endl;
}
