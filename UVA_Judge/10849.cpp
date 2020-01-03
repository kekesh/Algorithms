#include <iostream>
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
#define pow(a, b) ceil(pow(a, b))
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


int main(void) {
  ll C;
  cin >> C;
  while (C--) {
    ll T, N;
    cin >> T >> N;
    while (T--) {
      ll r, c, rf, cf;
      cin >> r >> c >> rf >> cf;
      if (r == rf && c == cf) cout << 0 << endl;
      else if ((r + c == rf + cf) || (r - c) == (rf - cf)) cout << 1 << endl;
      else if (((r + c) % 2) != ((rf + cf) % 2)) cout << "no move" << endl;
      else cout << 2 << endl;
    }
  }

}

