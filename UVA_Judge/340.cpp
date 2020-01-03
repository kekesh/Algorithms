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
const ll INFTY = 10e8;

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
const int MX = 35005;
const ld PI = 4 * atan((ld)1);

// Start of code.

int main() {
	ll N;
	int code[1000], guess[1000];
	bool takencode[1000];
	bool takenguess[1000];
	int j = 0;
	while (cin >> N, N != 0) {
		cout << "Game " << ++j << ":" << endl;
		F0R(i, N) cin >> code[i];
		while (1) {
			bool allzeroes = true;

			F0R(i, N) {
				cin >> guess[i];
				if (guess[i] != 0) allzeroes = false;
			}

			if (allzeroes) {
				break;
			}
			memset(takencode, false, sizeof(takencode));
			memset(takenguess, false, sizeof(takenguess));

			int strong, weak;
			strong = weak = 0;

			F0R(i, N) {
				if (code[i] == guess[i]) {
					takencode[i] = takenguess[i] = true;
					strong++;
				}
			}

			F0R(i, N) {
				F0R(j, N) {
					if (!takencode[i] && !takenguess[j] && code[i] == guess[j]) {
						takencode[i] = takenguess[j] = true;
						weak++;
					}
				}
			}

			cout << "    (" << strong << "," << weak << ")" << endl;


		}
	}

	return 0;
}
