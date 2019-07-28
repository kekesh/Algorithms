/* ID: ekfrmd1
   LANG: C++
   TASK: wormhole
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

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

void init();
void solve();
void setIO();

vector<pi> coords;
int ypos[1000010];
int N, max_y = -1;

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> N;
  F0R(i, N) {
    int x, y;
    fin >> x >> y;
    if (y > max_y) {
      max_y = y;
    }
    coords.push_back(make_pair(x, y));
  }
  fin.close();
}

void solve() {
  for (int i = 0; i < N; i++) {
    ypos[coords.at(i).second]++;
  }

    
  int sum = 0;
  for (int i = 0; i <= max_y; i++) {
    if (ypos[i] == 0) {
        continue;
    } else {
        sum += (ypos[i] - 1);
    }
  }
  fout << sum << endl;
  fout.close();
}
