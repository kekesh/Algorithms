/*
  ID: ekfrmd1
  LANG: C++11
  TASK: nocows
*/

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
inline void init();
ll fn(ll n, ll k);

ifstream fin("nocows.in");
ofstream fout("nocows.out");

ll N, K;
ll dp[205][105];
bool visited[205][105];
bool seen[205][105][205][105];


int main() {
  setIO();
  init();
  visited[1][1] = true;
  dp[1][1] = 1;
  ll ans = fn(N, K);
  cout << "Answer: " << ans << endl;



  return 0;
}

inline void init() { cin >> N >> K; }
// f(9, 4) -> expected: 6.
ll fn(ll n, ll k) {

  if (n % 2 == 0) {
    return 0;
  }
  if (2 * k - 1 > n) {
    return 0;
  }
  if (k == 1) {
    return (n == 1 ? 1 : 0);
  }
  if (visited[n][k]) {
    return dp[n][k];
  }

  ll ans = 0;
  for (int i = 1; i < (n + 1)/2; i += 2) {
    FOR(j, 1, k) {
	ans += fn(i, j) * fn(n - i - 1, k - 1);
	ans += fn(i, k - 1) * fn(n - i - 1, j);
		ans += fn(i, k - 1) * fn(n - i - 1, k - 1);
 }
  }
  visited[n][k] = true;

  return dp[n][k] = ans;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}
