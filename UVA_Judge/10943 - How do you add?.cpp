#include <assert.h>
#include <math.h>
#include <stdio.h>
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
void dp();

ll binomial[215][215];  // i choose j
ll n, k;



inline void init() { cin >> n >> k; }

int main() {
  setIO();
  dp();
  init();
  while (n != 0 && k != 0) {
    cout << binomial[n + k - 1][k - 1] % 1000000 << endl;
    init();
  }
  return 0;
}

void dp() {
  FOR(n, 1, 210) {
    binomial[n][0] = 1;
    binomial[n][n] = 1;
  }
  FOR(n, 2, 210) {
    FOR(k, 1, n) {
      binomial[n][k] = (binomial[n - 1][k]+ (binomial[n - 1][k - 1]) % 1000000);
    }
  }
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}