/*
  ID: ekfrmd1
  LANG: C++11
  TASK: holstein
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
void init();

ifstream fin("holstein.in");
ofstream fout("holstein.out");

ll V, daily_req[26], G, feed[16][26];
bitset<16> answerbits;

void init() {
  fin >> V;
  F0R(i, V) { fin >> daily_req[i]; }
  fin >> G;

  F0R(i, G) {
    F0R(j, V) { fin >> feed[i][j]; }
  }
}

int main() {
  ll answer = INFTY;
  setIO();
  init();

  // Loop to 2^G.
  F0R(i, 1 << G) {
    ll temp[26] = {0};
    bitset<16> bit(i);
    F0R(b, G) {
      if (bit[b]) {
        F0R(j, V) { temp[j] += feed[b][j]; }
      }
    }

    bool finished = true;
    F0R(j, V) {
      if (temp[j] < daily_req[j]) {
        finished = false;
        break;
      }
    }

    if (finished && bit.count() < answer &&
        bit.to_ulong() > answerbits.to_ulong()) {
      /* Found best answer. */
      answer = bit.count();
      answerbits = bit;
    }
  }
  fout << answer;
  F0R(i, G) {
    if (answerbits[i]) {
      fout << " " << i + 1;
    }
  }
  fout << "\n";
  return 0;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}