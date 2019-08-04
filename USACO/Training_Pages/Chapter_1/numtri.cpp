/* ID: ekfrmd1
   LANG: C++
   TASK: numtri
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)

using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int dp[2][1001][2];
int triangle[1001][1001];

int main() {
  int N;

  fin >> N;

  FORd(i, 0, N) {
    F0R(j, N - i) {
      int x;
      fin >> x;
      triangle[i][j] = x;
    }
  }

  for (int j = 0; j < N; j++) {
    dp[0][j][0] = triangle[0][j];
    dp[0][j][1] = triangle[0][j];
  }

  dp[0][0][0] = -1;     /* Can't go left at corner. */
  dp[0][N - 1][1] = -1; /* Can't go right at other corner. */

  FOR(z, 1, N - 1) {
    F0R(i, N) {
      if (i == 0) {
        dp[1][i][0] = -1;
      } else {
        dp[1][i][0] = triangle[z][i] + max(max(dp[0][i][0], dp[0][i + 1][0]),
                                           max(dp[0][i][1], dp[0][i + 1][1]));
      }
      if (i == N - z - 1) {
        dp[1][i][1] = -1;
      } else {
        dp[1][i][1] = triangle[z][i] + max(max(dp[0][i][0], dp[0][i + 1][0]),
                                           max(dp[0][i][1], dp[0][i + 1][1]));
      }
    }

    F0R(k, N) {
      dp[0][k][0] = dp[1][k][0];
      dp[1][k][0] = 0;
      dp[0][k][1] = dp[1][k][1];
      dp[1][k][1] = 0;
    }
  }

  ll ans = max(max(dp[0][0][1], dp[0][0][0]), max(dp[0][1][0], dp[0][1][1]));

  ans += triangle[N - 1][0];

  fout << ans << endl;

  return 0;
}