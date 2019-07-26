#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
const ll INF = 1e18;

void setIO() {
const int MX = 100001;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/* Code starts here. */

void init();
ll dp[101];

ll N;

int main() {
  

  dp[0] = 1;
  dp[1] = 1;
  init();

  cin >> N;
  int x;
  F0R(i, N) {
    cin >> x;
    printf("%llu\n", dp[x]);
  }

  return 0;
}


void init() {

   FOR(i, 2, 100) {
       dp[i] = i * dp[i - 1];
   }

}

