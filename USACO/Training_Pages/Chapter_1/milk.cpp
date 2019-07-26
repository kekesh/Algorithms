/* ID: ekfrmd1
   LANG: C++
   TASK: milk
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

void init();
void solve();

ifstream fin("milk.in");
ofstream fout("milk.out");

int N, M;
set<pi> offers; /* Stored internally as a red-black tree. */

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    fin >> x >> y;
    offers.insert(make_pair(x, y));
  }

}

int main() {
  setIO();
  init();
  solve();
}

/* A greedy algorithm. */
void solve() {
  int purchased = 0;
  int cost = 0;
  set<pi>::iterator it = offers.begin();

  while (purchased != N) {
    if ((*it).second + purchased <= N) {
      cost += (*it).first * (*it).second;
      purchased += (*it).second;
      it++;
    } else {
      cost += (N - purchased) * (*it).first;
      purchased += (N - purchased);
    }
  }
  fout << cost << endl;
}
