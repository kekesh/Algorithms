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

void setIO();
inline void init();
bool check(ll candidate);
void solve();

ll t, N, C;
vector<ll> positions(1000005);

int main() {
  setIO();
  init();
  F0R(i, t) {
    cin >> N >> C;
    F0R(i, N) { cin >> positions[i]; }
    sort(positions.begin(), positions.begin() + N);
    solve();
  }
  return 0;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() { cin >> t; }

void solve() {
  /* Binary search the maximum minimum distance. */
  ll lo = 0;
  ll hi = positions[N - 1];
  ll ans = 0;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      /* It's a possible candidate, but let's look for better. */
      ans = mid;
      lo = mid + 1;
    } else {
      /* It doesn't work; need to decrease the distance. */
      hi = mid;
    }
  }
  cout << ans << endl;
}

bool check(ll candidate) {
  ll next_min = -1;
  ll prev_value = positions[0];
  ll count = 1;
  for (int i = 1; i < N; i++) {
    if (positions[i] - prev_value >= candidate) {
      count++;
      prev_value = positions[i];
    }
  }
  return (count >= C);
}