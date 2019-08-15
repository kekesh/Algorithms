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
int check(int start, int nmatches, int smallest);
ll solve();

ll N, sequence[10000];

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() {
  cin >> N;
  F0R(i, N) { cin >> sequence[i]; }
}

int main() {
  setIO();
  init();
  cout << solve() << "\n";
  return 0;
}

/* O(n^2) bottom-up DP solution. O(n) space complexity. */
ll solve() {
  /* The ith element of dp represents the longest decreasing subsequence
      if we end our sequence at sequence[i]. Taking the max over each element
      in this array will surely give our answer. */

  ll dp[N] = {0};
  ll answer = 1;
  /* By default, every longest decreasing subsequence is at least one (itself!)
   */
  F0R(i, N) { dp[i] = 1; }

  /* Now we initialize our DP array. */
  FOR(i, 1, N) {
    /* This inner for-loop checks every entry larger than sequence[i] where
        j < i. */
    F0R(j, i) {
      if (sequence[i] < sequence[j]) {
        dp[i] = MAX(dp[i], dp[j] + 1);
      }
    }
    answer = MAX(answer, dp[i]);
  }
  return answer;
}

/* The exponential solution. This is bad. */
int check(int start, int nmatches, int smallest) {
  int better, best = nmatches;

  FOR(i, start, N) {
    if (sequence[i] < smallest) {
      better = check(i, nmatches + 1, sequence[i]);
      if (better > best) {
        best = better;
      }
    }
  }
  return best;
}
