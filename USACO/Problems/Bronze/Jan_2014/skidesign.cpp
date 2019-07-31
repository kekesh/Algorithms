/* ID: ekfrmd1
   LANG: C++
   TASK: skidesign
*/

#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void init();
void setIO();
void solve();

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

ll N;
vector<ll> hills;
vector<ll> diffs;
ll delta[1001];

int main() {
  setIO();
  init();
  fin.close();
  sort(hills.begin(), hills.end());

  if (hills.at(hills.size() - 1) - hills.at(0) <= 17) {
    fout << "0" << endl;
  } else {
    solve();
  }

  fout.close();
  return 0;
}

void solve() {
  ll min = 1e10;
  FOR(i, hills.at(0), hills.at(hills.size() - 1)) {
    for (int i = hills.at(0); i < hills.at(hills.size() - 1) - 17; i++) {
      /* i is the base. i + 17 is the top. */

      ll temp = 0;
      vector<ll> copy = hills;
      FOR(k, 0, copy.size()) {
        if (copy.at(k) < i) {
          delta[k] = (i - copy.at(k));
          temp += delta[k] * delta[k];
        } else if (copy.at(k) > i + 17) {
          delta[k] = (copy.at(k) - i - 17);
          temp += delta[k] * delta[k];
        }
      }

      if (temp < min) {
        min = temp;
      }

      memset(delta, 0, sizeof(delta));
    }
  }
  fout << min << endl;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> N;
  F0R(i, N) {
    ll x;
    fin >> x;
    hills.push_back(x);
  }
}
