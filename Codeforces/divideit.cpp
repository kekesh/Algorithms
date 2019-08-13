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

const ll INF = 1e18;

// Debugging macros
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
inline void init();
void solve();

ll q;
ll n;

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void solve() {
  F0R(i, q) {
    cin >> n;
    ll operations = 0;
    bool flag = true;
    
    while (n != 1 && flag) {
      flag = false;
      if (n % 2 == 0) {
        n /= 2;
        operations++;
        flag = true;
      } else if (n % 3 == 0) {
        n = 2 * n / 3;
        operations++;
        flag = true;
      } else if (n % 5 == 0) {
        n = 4 * n / 5;
        operations++;
        flag = true;
      }
    }

    if (n == 1) {
        cout << operations << endl;
    } else {
        cout << "-1" << endl;
    }
  } 
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() { cin >> q; }
