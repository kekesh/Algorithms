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
ll solve(ll curr_length);

ll N, A, B, C;
ll dp[4005];
int main() {
  setIO();
  init();
  memset(dp, -1, sizeof(dp));
  cout << solve(N) << endl;
  ;
  return 0;
}

ll solve(ll curr_length) {
  if (curr_length < 0) {
    return -INFTY;
  }
  if (curr_length == 0) {
    return 0;
  }
  if (dp[curr_length] != -1) {
    return dp[curr_length];
  }
  return dp[curr_length] =
             MAX(1 + solve(curr_length - A),
                 MAX(1 + solve(curr_length - B), 1 + solve(curr_length - C)));
}
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() { cin >> N >> A >> B >> C; }