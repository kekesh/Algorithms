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
#define pow(a,b) ceil(pow(a,b))
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
inline void init();
void solve();
ll sum(ll num);

ll N;
ll a, b;

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void solve() {
  ll copy = N;
  if (copy < 10) {
    cout << N << endl;
    exit(0);
  }

  // N > 10.
  ll a = 0, b = 0;
  //+ 9*10^i.
  int i = 0;
  int k = 9;

  while (a + pow(10, i) < N) {
    while (a + k * pow(10, i) > N) {
      k--;
    }
    a += k * pow(10, i);
    i++;
  }
  b = N - a;
  cout << sum(a) + sum(b) << endl;
}

ll sum(ll num) {
  ll total = 0;
  while (num > 0) {
    total += num % 10;
    num /= 10;
  }
  return total;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void init() { cin >> N; }