#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;

typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);
int arr[5] = {1, 2, 200, 4, 5};

namespace io {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  cin.sync_with_stdio(0);
  cin.tie(0);                   // fast I/O
  cin.exceptions(cin.failbit);  // ex. throws exception when you try to read
                                // letter into int
  if (sz(s)) {
    setIn(s + ".in"), setOut(s + ".out");
  }  // for USACO
}
}  // namespace io
using namespace io;

template <class T>
void ckmin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void ckmax(T &a, T b) {
  a = max(a, b);
}

ll T;

int main() {
  setIO();

  cin >> T;

  while (T--) {
    string curr_num;
    cin >> curr_num;
    ll N = curr_num.size();

    int prev_parity;
    int curr_parity;
    ll max_in_run = -1;
    ll maxi_index = -1;

    F0R(i, N) {
      if (i < 0) {
        cout << "NEGATIVE!!" << endl;
        exit(0);
      }
      if ((curr_num[i] - 48) & 1) {
        curr_parity = 1;  // odd
      } else {
        curr_parity = 0;  // even.
      }

      if (i == 0) {
        prev_parity = curr_parity;
      } else {
        if ((curr_num[i - 1] - 48) & 1) {
          prev_parity = 1;  // odd
        } else {
          prev_parity = 0;  // even.
        }
      }

      if (prev_parity == curr_parity) {
        max_in_run = MAX(max_in_run, (curr_num[i] - 48));
        maxi_index = i;
      }

      if (curr_parity != prev_parity && max_in_run > (curr_num[i] - 48)) {
        swap(curr_num[i], curr_num[maxi_index]);
        max_in_run = -1;
        if (i == 1)
          i = maxi_index - 1;
        else
          i = maxi_index - 2;
        maxi_index = -1;
      } else if (curr_parity != prev_parity) {
        max_in_run = curr_num[i] - 48;
        maxi_index = i;
      }
    }
    cout << curr_num << endl;
  }
}
