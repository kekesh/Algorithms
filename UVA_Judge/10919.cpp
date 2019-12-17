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
#include <unordered_map>
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

// Start of code.


int main() {
  setIO();
  ll k, m;

  while (cin >> k) {
    if (k == 0) break;
    cin >> m;

    unordered_map<int, bool> registered;

    F0R(i, k) {
      ll x;
      cin >> x;
      registered[x] = true;
    }
    bool isok = true;
    F0R(i, m) {
      // for each category
      ll num_total, num_req;
      cin >> num_total >> num_req;
      F0R(j, num_total) {
        ll x;
        cin >> x;
        if (registered.count(x) && registered[x]) {
          num_req--;
        }
      }
      if (num_req > 0) {
        isok = false;
      }
    }

    if (isok) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
