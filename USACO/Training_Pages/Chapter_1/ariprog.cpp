/* ID: ekfrmd1
   LANG: C++
   TASK: ariprog
*/
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void init();
void setIO();
void solve();
void print_answers();

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

// multiset<ll> bisquares;
bool bisquares[125010];
vector<ll> bisquares_ordered;
multiset<pair<ll, ll>> answers;
set<ll> seen;
ll N, M;

int main() {
  setIO();
  init();
  solve();
  print_answers();
}

void solve() {
  ll maxi = bisquares_ordered.at(bisquares_ordered.size() - 1);

  ll count = 0;
  F0R(i, bisquares_ordered.size()) {
    FOR(j, i + 1, bisquares_ordered.size()) {
      ll a0 = bisquares_ordered.at(i);
      ll diff = bisquares_ordered.at(j) - a0;
      ll length = 1;
      /* A number that is the sum of two squares cannot be congruent to 3 mod 4.
       */

      /* Since each a0 is a bisquare by definition, it must be 0, 1, or 2 mod 4.
       */
      /* If a0 is 1 mod 4, diff must be 0 mod 4 (otherwise, we'll exit the
       * sequence). */
      /* If a0 is 2 mod 4, diff must be 0 mod 4 (otherwise, we'll exit the
       * sequence). */
      /* If a0 is 0 mod 4, diff can be 0 mod 4, 1 mod 4, or 2 mod 4. */

      if (a0 + diff * (N - 1) > maxi) {
        continue;
      }

      if (a0 % 4 == 0 && diff % 4 == 3) {
        continue;
      } else if (a0 % 4 == 0 && diff % 4 == 1 && N >= 4) {
        continue;
      } else if (a0 % 4 == 1 && diff % 4 == 1 && N >= 3) {
        continue;
      } else if (a0 % 4 == 1 && diff % 4 == 2 && N >= 2) {
        continue;
      } else if (a0 % 4 == 1 && diff % 4 == 3 && N >= 3) {
        continue;
      } else if (a0 % 4 == 2 && diff % 4 == 1 && N >= 2) {
        continue;
      } else if (a0 % 4 == 2 && diff % 4 == 3 && N >= 4) {
        continue;
      }
      count++;

      while (bisquares[a0 + diff]) {
        length++;
        a0 += diff;
        if (length == N) {
          answers.insert(make_pair(diff, bisquares_ordered.at(i)));
          break;
        }
      }
    }
  }
}

void print_answers() {
  if (answers.size() == 0) {
    fout << "NONE" << endl;
  } else {
    multiset<pair<ll, ll>>::iterator itr = answers.begin();

    while (itr != answers.end()) {
      fout << (*itr).second << " " << (*itr).first << endl;
      itr++;
    }
  }
}

void init() {
  /* 250^2 operations */
  ll loop_ct = 0;
  fin >> N >> M;
  FOR(p, 0, M + 1) {
    FOR(q, p, M + 1) {
      loop_ct++;
      if (!bisquares[p * p + q * q]) {
        bisquares[p * p + q * q] = 1;
        bisquares_ordered.push_back(p * p + q * q);
      }
    }
  }
  sort(bisquares_ordered.begin(), bisquares_ordered.end());
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}