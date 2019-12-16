/* Dollars */

#include "competitive.h"

void setIO();
inline void init();
ll solve(ll amount);

ll coins[13] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll dp[30005][13];

int main() {
  setIO();
  double amount;
  memset(dp, 0, sizeof(dp));
  solve(30004);
  while (cin >> amount, amount != 0) {
    ll x = (amount * 100) + 0.5;
    ll ans = dp[x][11];
    printf("%*.2f", 6, amount);
    printf("%*lld\n", 17, ans);
  }

  return 0;
}

ll solve(ll amount) {
  if (amount < 0) {
    cout << "here" << endl;
    return 0;
  }

  F0R(i, 12) { dp[0][i] = 1; }

  FOR(i, 1, amount + 1) {
    F0R(j, 12) {
      ll x = (i - coins[j]) >= 0 ? dp[i - coins[j]][j] : 0;
      ll y = (j - 1 >= 0) ? dp[i][j - 1] : 0;
      dp[i][j] = x + y;
    }
  }
  return dp[amount][11];
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}