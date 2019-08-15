/* Wedding Shopping */

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
inline void init();
ll solve(ll row, ll current_money);
void init2();

ll N, M, C, K;
ll prices[21][21];
ll K_sizes[21];
ll dp[21][201];

int main() {
  setIO();
  init();
  F0R(i, N) {
    init2();
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, 0);
    if (ans == -INFTY) {
      cout << "no solution\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll solve(ll row, ll current_money) {
  if (dp[row][current_money] != -1) {
    return dp[row][current_money];
  }

  ll answer = -INFTY;

  if (current_money > M) {
    return -INFTY;
  }
  if (row == C) {
    return current_money;
  }

  ll num_cols = K_sizes[row];

  F0R(i, num_cols) {
    answer = MAX(answer, solve(row + 1, current_money + prices[row][i]));
  }
  return dp[row][current_money] = answer;
}

void init2() {
  cin >> M >> C;
  // M is money
  F0R(i, C) {
    cin >> K_sizes[i];
    F0R(j, K_sizes[i]) { cin >> prices[i][j]; }
  }
}

inline void init() { cin >> N; }