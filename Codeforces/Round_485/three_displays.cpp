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
void init();



ll solve(ll curr_size, ll curr_font, ll start);
ll N;
ll font_sizes[3001];
ll rent_costs[3001];
ll dp[3][3001];

int main() {
  setIO();
  init();
  memset(dp, -1, sizeof(dp));
  ll x = solve(-INFTY, 0, 0);
  if (x == INFTY) {
    cout << "-1" << endl;
  } else {
    cout << x << endl;
  }
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll solve(ll curr_size, ll curr_font, ll start) {
  if (curr_font == 3) {
    return 0;
  }

  if (dp[curr_font][start] != -1) {
    return dp[curr_font][start];
  }

  ll best = INFTY;
  FOR(i, start, N) {
    if (curr_size < font_sizes[i]) {
      best =
          MIN(best, rent_costs[i] + solve(font_sizes[i], curr_font + 1, i + 1));
    }
  }

  if (curr_size != -INFTY) {
    dp[curr_font][start] = best;
  }

  return best;
}

void init() {
  cin >> N;
  F0R(i, N) { cin >> font_sizes[i]; }
  F0R(i, N) { cin >> rent_costs[i]; }
}