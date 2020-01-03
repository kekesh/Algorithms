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
  int x1, x2, y1, y2;
  while (cin >> x1 >> y1 >> x2 >> y2, x1 + x2 + y1 + y1) {
    if (x1 == x2 && y1 == y2) cout << 0 << endl;
    else if (x1 == x2 || y1 == y2) cout << 1 << endl;
    else if ((x1 - y1 == x2 - y2) || (y1 + x1 == y2 + x2)) cout << 1 << endl;
    else cout << 2 << endl;
  }
  return 0;
}
