#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void init();
void solve();

ll N;
ll dp[100010][3];
ll team1[100010];
ll team2[100010];

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {
  /* dp starts by picking from team 1. */
  dp[0][0] = 0;
  dp[0][1] = team1[0];
  dp[0][2] = team2[0];

  for (int i = 1; i < N; i++) {
    dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    dp[i][1] = team1[i] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = team2[i] + max(dp[i - 1][0], dp[i - 1][1]);
  }
  ll ans = max(dp[N - 1][1], dp[N - 1][2]);
  cout << ans << endl;
  
}

int main() {
  init();
  setIO();
  solve();
}

void init() {
  cin >> N;
  F0R(i, N) { cin >> team1[i]; }
  F0R(i, N) {
    cin >> team2[i];
    dp[i][0] = dp[i][1] = dp[i][2] = -1;
  }
}