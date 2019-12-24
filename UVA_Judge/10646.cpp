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

struct Card {
  char rank, suit;
  Card(char r, char s) : rank(r), suit(s) {}
};


int main() {
  ll T;
  cin >> T;
  int j = 0;
  while (T--) {
    vector<Card> deck;
    vector<Card> hand;
    F0R(i, 27) {
      string st;
      cin >> st;
      Card c(st[0], st[1]);
      deck.pb(c);
    }

    F0R(i, 25) {
      string st;
      cin >> st;
      Card c(st[0], st[1]);
      hand.pb(c);
    }

    ll Y = 0;

    F0R(i, 3) {
      Card top = deck[deck.size() - 1];
      ll value;
      if (top.rank == 'A' || top.rank == 'K' || top.rank == 'Q' || top.rank == 'J' || top.rank == 'T') {
        value = 10;
      } else {
        value = top.rank - '0';
      }
      Y += value;
      deck.erase(deck.begin() + deck.size() - 1);
      F0R(j, 10-value) {
        deck.erase(deck.begin() + deck.size() - 1);
      }
    }

    if (Y < deck.size()) {
      cout << "Case " << ++j << ": " << deck[Y - 1].rank << deck[Y - 1].suit << endl;
    } else {
      Y -= deck.size();
      cout << "Case " << ++j << ": " << hand[Y - 1].rank << hand[Y - 1].suit << endl;
    }

  }
}

