#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const ll INF = 1e18;

// Debugging macros
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
inline void init();
void solve();

ll n;
ll arr[500005];
ll cnt[6];
ll dp[500005]; /* dp[index] represents the min number of elements we need
                 to remove for dp[0...index] to be a good array. */

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void solve() {
  dp[0] = 0;

  ll next_num;
  FOR(i, 1, n + 1) {
    cin >> next_num;
    int index;
    if (next_num == 4) {
      cnt[0]++;
      index = 0;
    } else if (next_num == 8) {
      cnt[1]++;
      index = 1;
    } else if (next_num == 15) {
      cnt[2]++;
      index = 2;
    } else if (next_num == 16) {
      cnt[3]++;
      index = 3;
    } else if (next_num == 23) {
      cnt[4]++;
      index = 4;
    } else if (next_num == 42) {
      cnt[5]++;
      index = 5;
    }

    if (cnt[5] > 0 && cnt[0] >= cnt[1] && cnt[1] >= cnt[2] && cnt[2] >= cnt[3] &&
        cnt[3] >= cnt[4] && cnt[4] >= cnt[5]) {
        F0R(j, 6) {
            cnt[j]--;
        }
        dp[i] = dp[i - 1] - 5;
    } else {
        dp[i] = 1 + dp[i - 1];
        if (index != 0 && cnt[index] > cnt[index - 1]) {
            cnt[index]--;
        }
    }
  }
  cout << dp[n] << "\n";
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() { cin >> n; }