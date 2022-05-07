#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

ll count(int coins[], int goal, int array_size);

int main() {
  int coins[] = {41, 34, 46, 9, 37, 32, 42,
                 21, 7, 13, 1, 24, 3, 43, 2,
                 23, 8, 45, 19, 30, 29, 18, 35,
                 11};
  int array_size = 24;
  int goal = 250;
  cout << count(coins, goal, array_size) << "\n";
  return 0;
}

/* Bottom-up dynamic programming solution. */
ll count(int coins[], int goal, int array_size) {
  /* dp[i][j] represents the number of ways to achieve a sum of i
     with the first j coins. */
  ll dp[goal + 1][array_size];

  /* The number of ways to achieve a sum of 0 is 1 for 1 <= j <= array_size. */
  F0R(i, array_size) { dp[0][i] = 1; /* Base cases. */ }

  FOR(i, 1, goal + 1) {
    F0R(j, array_size) {
      /* Solutions including coins[j]. */

      /* dp[i - coins[j]][j] is the number of ways to sum to i - coins[j]
         using the first j coins. */
      ll x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;

      /* Solutions excluding coins[j] */

      /* dp[i][j - 1] represents the number of ways to sum to i with only
         the first j - 1 coins.  */
      ll y = (j > 0) ? dp[i][j - 1] : 0;

      dp[i][j] = x + y;
    }
  }
  return dp[goal][array_size - 1];
}
