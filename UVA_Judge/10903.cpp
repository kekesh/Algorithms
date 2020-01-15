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

int gamesplayed[101];
int gameswon[101];

int main() {
  ll n, k;
  bool fst = true;
  while (cin >> n, n) {
    if (!fst) cout << endl;
    fst = false;
    cin >> k;
    int num_games = k * n * (n - 1);
    num_games /= 2;
    memset(gamesplayed, 0, sizeof(gamesplayed));
    memset(gameswon, 0, sizeof(gameswon));
    F0R(i, num_games) {
      ll fst, snd;
      string fsth, sndh;
      cin >> fst >> fsth >> snd >> sndh;
      if (fsth == sndh) {
        continue;
      }
      else if ((fsth == "rock" && sndh == "scissors") || (fsth == "paper" && sndh == "rock") || (fsth == "scissors" && sndh == "paper")) {
        gameswon[fst]++;
        gamesplayed[fst]++;
        gamesplayed[snd]++;
      } else {
        gameswon[snd]++;
        gamesplayed[fst]++;
        gamesplayed[snd]++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (gamesplayed[i + 1] == 0) {
        cout << "-" << endl;
      } else {
        long double avg = (long double) gameswon[i + 1]/gamesplayed[i + 1];
        printf("%.3Lf\n", avg);
      }
    }

  }


return 0;
}
