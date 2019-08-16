#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
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

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void solve() {
  ll ans = INF;
  pi anspair;

  FOR(a, 1, sqrt(n) + 1) {
    if (n % a == 0) {
      ll b = n / a;
      if (b - a < ans) {
        ans = b - a;
        anspair = make_pair(a, b);
      }
    }
  }
  
  cout << MIN(anspair.first, anspair.second) << " " << MAX(anspair.first, anspair.second) << endl;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() { cin >> n; }