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
void solve2();
void init();

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll N = 11;
ll prices[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
ll dp[11];

int main() {
  setIO();
  solve();
  return 0;
}


void solve() {
  F0R(i, 12) { dp[i] = -INFTY; }
  dp[0] = 0;

  FOR(i, 1, N + 1) {
    FOR(j, 1, i + 1) { dp[i] = MAX(dp[i], prices[j - 1] + dp[i - j]); }
  }
  PRINT_ARRAY(dp, 11);
}
