/* A bottom-up dynamic programming solution to the Classical Rod Problem,
   by Ekesh Kumar.

   Abridged problem statement: "Given a rod of length N along with an array
   of prices representing the value of a rod of length K, (1 <= K <= N),
   determine the best way to cut the rod in order to maximize profit
   (cuts are free)." */

/* This program prints the lengths of the sub-rods that one should sell
   in order to maximize profit. O(n^2) runtime. */

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
ll solve(ll rod_length);
void init();
void print_solution(ll rod_length);

ll N;
ll prices[10000]; /* Inputted by the user. */
ll dp[10000]; 
ll first_piece[10000]; /* Used to print the solution. */

int main() {
  setIO();
  init();
  solve(7);
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void init() {
  cin >> N;
  assert(N < 10000);
  F0R(i, N) { cin >> prices[i]; }
}

/* Bottom-up dynamic programming. */
ll solve(ll rod_length) {
  F0R(i, 12) { dp[i] = -INFTY; }

  /* dp[i] is the max profit we can get from a rod of length i. */
  dp[0] = 0;

  FOR(i, 1, N + 1) {
    FOR(j, 1, i + 1) {
      /* Iterate over the length of the left-most rod piece. */
      if (dp[i] < prices[j - 1] + dp[i - j]) {
        dp[i] = prices[j - 1] + dp[i - j];
        first_piece[i] = j;
      }
    }
  }
  print_solution(rod_length);
}

void print_solution(ll rod_length) {
  cout << first_piece[rod_length];
  while (rod_length -= first_piece[rod_length], rod_length > 0) {
    cout << " " << first_piece[rod_length];
  }
  cout << "\n";
}
