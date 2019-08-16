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
void solve();

ll N;
bool seen[150005];
vector<ll> nums(150005);

int main() {
  setIO();
  solve();
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void solve() {
  cin >> N;
  ll ans = 0;
  ll curr;

  F0R(i, N) { cin >> nums[i]; }
  sort(nums.begin(), nums.begin() + N);

  F0R(i, N) {
    int curr = nums[i];
    if (curr != 1 && !seen[curr - 1]) {
      seen[curr - 1] = true;
      ans++;
    } else if (!seen[curr]) {
      seen[curr] = true;
      ans++;
    } else if (!seen[curr + 1]) {
      seen[curr + 1] = true;
      ans++;
    }
  }
  cout << ans << endl;
}