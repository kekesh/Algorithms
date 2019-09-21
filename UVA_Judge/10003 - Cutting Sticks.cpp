/* Cutting Sticks */

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
ll solve(ll start, ll end);
void init();

ll L, N, cuts[51];
ll memo[1001][1001];

int main() {
  setIO();
  while (1) {
    memset(memo, -1, sizeof(memo));
    init();
    cout << "The minimum cutting is " << solve(0, N + 1) << "." <<endl;
  }
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll solve(ll start, ll end) {

  if (start + 1 == end) {
    return 0;
  }

  if (memo[start][end] != -1) {
    return memo[start][end];
  }

  ll price = INFTY;

  FOR(i, start + 1, end) {
    ll q = solve(start, i) + solve(i, end) + (cuts[end] - cuts[start]);
    price = MIN(price, q);
  }

  return memo[start][end] = price;
}

inline void init() {
  cin >> L;
  if (L == 0) {
    exit(0);
  }
  cin >> N;
  cuts[0] = 0;
  FOR(i, 1, N + 1) { cin >> cuts[i]; }
  cuts[N + 1] = L;
}