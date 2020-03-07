#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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

// Start of code.

ll board[5][5];
unordered_set<int> seen;

bool check() {
  F0R(i, 5) {
    if (board[i][0] == INFTY && board[i][1] == INFTY && board[i][2] == INFTY && board[i][3] == INFTY && board[i][4] == INFTY) return true;
  }

  F0R(i, 5) {
    if (board[0][i] == INFTY && board[1][i] == INFTY && board[2][i] == INFTY && board[3][i] == INFTY && board[4][i] == INFTY) return true;
  }

  bool diagonalok = true;
  F0R(i, 5) {
    if (board[i][i] != INFTY) diagonalok = false;
  }
  if (diagonalok) return true;

  diagonalok = true;
  F0R(i, 5) {
    if (board[4 - i][i] != INFTY) diagonalok = false;
  }
  return diagonalok;
}

int main() {
  ll T;
  cin >> T;
  while (T--) {

    F0R(i, 2) {
      F0R(j, 5) {
        cin >> board[i][j];
        seen.insert(board[i][j]);
      }
    }
    board[2][2] = INFTY;
    cin >> board[2][0] >> board[2][1] >> board[2][3] >> board[2][4];
    F0R(i, 5) {
      if (i != 2) {
        seen.insert(board[2][i]);
      }
    }

    F0R(i, 2) {
      F0R(j, 5) {
        cin >> board[i + 3][j];
        seen.insert(board[i + 3][j]);
      }
    }

   bool won = false;
   int numturns = INFTY;
   F0R(i, 75) {
    ll nxt;
    cin >> nxt;
    if (seen.find(nxt) != seen.end()) {
      seen.erase(nxt);
      F0R(x, 5) {
        F0R(y, 5) {
          if (board[x][y] == nxt) {
            board[x][y] = INFTY;
            won = check();
            if (won) numturns = min(numturns, (i + 1));
          }
        }
      }
    }
   }

   cout << "BINGO after " << numturns << " numbers announced" << endl;


  }

return 0;
}

