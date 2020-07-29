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
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ll N, A, B;
int AdjMat[1001][1001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> A >> B;
		if (A != 1 && B != 1) {
				cout << "NO" << endl;
				return 0;
		}
		// A == 1 or B == 1.
		if (A == 1 && B == 1 && (N == 3 || N == 2)) {
				cout << "NO" << endl;
				return 0;
		} else if (A == 1 && B == 1) {
				cout << "YES" << endl;

				for (int i = 0; i < N - 1; i++) {
						AdjMat[i][i + 1] = AdjMat[i+1][i] = 1;
				}

				F0R(i, N) {
						F0R(j, N) {
								cout << AdjMat[i][j];
						}
						cout << endl;
				}
				return 0;
		}

		bool flag = false;
		if (A != 1) {
				flag = true;
				swap(A, B);
		}
		cout << "YES" << endl;
		for (int i = 0; i < B - 1; i++) {
				for (int j = i + 1; j < N; j++) {
						AdjMat[i][j] = AdjMat[j][i] = 1;
				}	
		}

		F0R(i, N) {
				F0R(j, N) {
						if (!flag) cout << AdjMat[i][j];
						else {
								if (i == j) cout << 0;
								else cout << 1 - AdjMat[i][j];
						}
				}
				cout << endl;
		}


}
