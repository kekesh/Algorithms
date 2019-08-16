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
void solve();

ll N;
string A;
string B;

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {
  ll ans = 0;
  F0R(i, N) {
      if (A[i] != B[i]) ans++;
  }

  F0R(i, N - 1) {
    if (A[i] != B[i] && A[i + 1] != B[i + 1] && A[i] == B[i + 1] &&
        A[i + 1] == B[i]) {
      ans--;

      if (A[i] == '0') {
        A[i] = '1';
      } else {
        A[i] = '0';
      }
      if (A[i + 1] == '0') {
        A[i + 1] = '1';
      } else {
        A[i + 1] = '0';
      }
    }
  }
  cout << ans << endl;
}

inline void init() { cin >> N >> A >> B; }