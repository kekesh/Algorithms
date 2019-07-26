/* ID: ekfrmd1
   LANG: C++
   TASK: barn1
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

ifstream fin("barn1.in");
ofstream fout("barn1.out");

int M, S, C;
vector<int> stalls;
vector<int> differences;

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> M >> S >> C;
  for (int i = 0; i < C; i++) {
    int x;
    fin >> x;
    stalls.push_back(x);
  }
  sort(stalls.begin(), stalls.end());

  for (int i = 1; i < C; i++) {
    differences.push_back(stalls.at(i) - stalls.at(i - 1));
  }
  sort(differences.begin(), differences.end());
}

int main() {
  setIO();
  init();
  solve();
}

/* Greedy algorithm. */
void solve() {
  int answer = stalls.at(stalls.size() - 1) - stalls.at(0);  // N = 1 case;

  if (M >= C) {
    answer = C;
  } else {
    for (int i = 1; i < M; i++) {
      /* This loop constructs the ith case. */
      /* Remove the (i + 1)th largest gap. */
      answer -= differences.at(differences.size() - 1);
      differences.erase(differences.end() - 1);
    }
    answer += M;
  }
  fout << answer << endl;
}