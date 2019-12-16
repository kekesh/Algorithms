#include <stdio.h>
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


ll a, b, c, d;

int main() {
  setIO();
  a = b = c = d = -1;
  while (1) {
    cin >> a >> b >> c >> d;

    if (a == 0 && b == 0 && c == 0 && d == 0) {
      break;
    }
    ll ans = 1080;
    ans += (a - b) >= 0 ? (a - b) * 9 : (a - b + 40) * 9;
    ans += (c - b) >= 0 ? (c - b) * 9 : (c - b + 40) * 9;
    ans += (c - d) >= 0 ? (c - d) * 9 : (c - d + 40) * 9;
    cout << ans << endl;
  }


  return 0;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}