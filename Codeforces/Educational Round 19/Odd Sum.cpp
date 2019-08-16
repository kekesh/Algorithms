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
void solve();

ll nums[100005];
ll N;
ll sum;
ll max_neg_odd = -INFTY;
ll min_pos_odd = INFTY;

int main() {
  setIO();
  solve();
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {
  cin >> N;
  F0R(i, N) {
    cin >> nums[i];
    if (nums[i] > 0) {
      sum += nums[i];
    }

    if (nums[i] < 0 && nums[i] & 1 && max_neg_odd < nums[i]) {
      max_neg_odd = nums[i];
    }
    if (nums[i] > 0 && nums[i] & 1 && min_pos_odd > nums[i]) {

      min_pos_odd = nums[i];
    }
  }
  if (sum & 1) {
    cout << sum << endl;
  } else {
    cout << sum - min(abs(min_pos_odd), abs(max_neg_odd)) << endl;
  }
}
