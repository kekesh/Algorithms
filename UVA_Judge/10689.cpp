#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
void solve();

ll T;
ll dp[100000];


int main() {
  setIO();
  cin >> T;
  F0R(i, T) {
	solve();
  }


}

void solve() {

	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	dp[0] = a;
	dp[1] = b;
	ll bound = 0;
	ll modulus = 0;
	/* Pisano Period */
	if (m == 1) {
		bound = 60;
		modulus = 10;
	} else if (m == 2) {
		bound = 300;
		modulus = 100;
	} else if (m == 3) {
		bound = 1500;
		modulus = 1000;
	} else if (m == 4) {
		bound = 15000;
		modulus = 10000;
	}
	dp[0] %= modulus;
	dp[1] %= modulus;

	FOR(i, 2, bound + 1) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % modulus;
	}
	cout << dp[n % bound] << endl;
}


void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

