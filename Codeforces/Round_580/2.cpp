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
#include <unordered_set>
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
void solve();

ll N;
ll nums[100010];
ll non_pos_count;
ll max_non_pos;

int main() {
  setIO();
  init();
  solve();
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void init() {
  cin >> N;
  ll num;
  max_non_pos = -INFTY;
  F0R(i, N) {
    cin >> nums[i];
    if (nums[i] <= 0) {
      non_pos_count++;
      if (nums[i] > max_non_pos) {
        max_non_pos = nums[i];
      }
    }
  }
}

void solve() {
  bool flag = false;
  if (non_pos_count & 1) {
    flag = true;
  }

  ll cost = 0;
  F0R(i, N) { cost += MIN(abs(nums[i] - 1), abs(nums[i] + 1)); }

  if (flag) {
    /* Odd number of non-positives. */
    cost -= abs(max_non_pos + 1); /* Subtract distance to -1 */
    cost += abs(max_non_pos - 1); /* Add distance to +1. */
  }
  cout << cost << endl;
}

