/*
  ID: ekfrmd1
  LANG: C++11
  TASK: money
*/

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
ll solve(ll target);

ifstream fin("money.in");
ofstream fout("money.out");

ll V, N;
ll len;
ll dp[10001];
ll coins[26];

inline void init() {
  cin >> V >> N;
  F0R(i, V) { cin >> coins[i]; }
}

int main() {
  setIO();
  init();
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;

  F0R(i, N + 1) {
    solve(i);
  }
  PRINT_ARRAY(dp, N);
}

ll solve(ll target) {

  if (target < 0) {
      return 0;

  }
  if (target == 0) {
    return 1;
  }
  
  if (dp[target] != -1) {
    return dp[target];
  }
  
  int count = 0;

  F0R(j, V) {
      if (target - coins[j] >= 0) {
        count += solve(target - coins[j]);
      }
  } 
  

  return dp[target] = count;

}


/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}