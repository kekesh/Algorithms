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

ll N, M, K;

/* Min hours so far if we choose to skip/go on day i, hour j. */
ll dp[500][500][2]; 
char classes[501][501];

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void solve() {
  dp[1][0][0] = 0;
  dp[1][0][1] = 1;

  for (int day = 1; day <= N; day++) {
    for (int hour = 1; hour <= M; hour++) {
      char curr_hr = classes[day - 1][hour - 1];

      if (curr_hr == '0') {
        /* There's no class to skip. */
        if (hour > 0) {
          dp[day][hour][0] = MIN(dp[day][hour - 1][0], dp[day][hour - 1][1]);
          dp[day][hour][1] = INF; 
          /* We aren't allowed to skip when there's no class. */
        } else {
          dp[day][hour][0] = MIN(dp[day - 1][M][0], dp[day - 1][M][1]);
          dp[day][hour][1] = INF; /* Can't skip no class. */
        }
      } else if (curr_hr == '1') {
        /* There's class. We can skip or not skip. */
        if (hour > 0) {
            cout << "In here" << endl;
          dp[day][hour][0] = MIN(dp[day][hour - 1][0], dp[day][hour - 1][1]);
          dp[day][hour][1] = MIN(dp[day][hour - 1][0], dp[day][hour - 1][1]);
        } else {
          dp[day - 1][M][0] = MIN(dp[day - 1][M][0], dp[day - 1][M][1]);
          dp[day][hour][1] = MIN(dp[day][hour - 1][0], dp[day][hour - 1][1]);
        }

        
        /* Now we handle the case in which we're skipping. */
        /* We keep on subtracting until we find our next non-zero value. */
        bool flag = false;
        int temp_day = day;
        int temp_hour = hour;
        while (!flag) {
          temp_hour++;
          if (temp_hour > M) {
            temp_hour = 0;
            temp_day++;
          }
          if (temp_day > N) {
            break;
          }
          if (classes[temp_day][temp_hour] != 1) {
            dp[day][hour][1]--;
          }
        }
      }
    }
  }
  cout << MIN(dp[N][M][0], dp[N][M][1]) << endl; 
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() {
  cin >> N >> M >> K;
  F0R(i, N) {
    F0R(j, M) { cin >> classes[i][j]; }
  }
}