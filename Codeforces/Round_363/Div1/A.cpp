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

void init();
void solve();

ll N;
ll a[100];
ll dp[100][3];

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < N; i++) {
    dp[i][0] = dp[i][1] = dp[i][2] = 1e10;
  }

  dp[0][0] = 1;
  if (a[0] == 1 || a[0] == 3) {
    dp[0][1] = 0;
  }
  if (a[0] == 2 || a[0] == 3) {
    dp[0][2] = 0;
  }

  for (int i = 1; i < N; i++) {
    /* We can always rest. */
    dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));

    if (a[i] == 1 || a[i] == 3) {
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    }

    if (a[i] == 2 || a[i] == 3) {
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  ll ans = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
  cout << ans << endl;
}

int main() {
  setIO();
  solve();
}