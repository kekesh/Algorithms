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
void solve2();
void solve();

ll m, s;

inline void init() { cin >> m >> s; }

int main() {
  setIO();
  init();
  if (m == 1 && s <= 9) {
    cout << s << " " << s << endl;
    exit(0);
  }
  if (m * 9 < s || 1 > s) {
    cout << "-1 -1" << endl;
  } else {
    solve();
    solve2();
  }
}

void solve() {
  int min_num[m + 5];
  ll target = s;
  ll digits_left = m;
  F0R(i, m) {
    //cout << "i = " << i << endl;
    if (i != 0 && (digits_left - 1) * 9 >= target) {
      min_num[i] = 0;
      digits_left--;
    } else if ((digits_left - 1) * 9 >= target - 1) {
      min_num[i] = 1;
      digits_left--;
      target--;
    } else if (9 * digits_left == target) {
      min_num[i] = 9;
      target -= 9;
      digits_left--;
    } else {
      min_num[i] = (target % 9);
      target -= (target % 9);
      digits_left--;
    }
  }
  F0R(i, m) {
    cout << min_num[i];
  }
  cout << " ";
}

void solve2() {
  int max_num[m + 5];
  ll target = s;
  ll digits_left = m;
  F0R(i, m) {
    //cout << "i = " << i << endl;
    if (target == 0) {
      max_num[i]  = 0;
      digits_left--;
    } else if (target > 9) {
      max_num[i] = 9;
      target -= 9;
      digits_left--;
    } else {
      max_num[i] = target;
      target -= target;
      digits_left--;
    }
  }

  F0R(i, m) {
    cout << max_num[i];
  }
  cout << "\n";
}


void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}