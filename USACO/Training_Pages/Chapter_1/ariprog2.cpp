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

bool is_bisquare[125010];
ll N, M;
int main() {
  setIO();
  init();
  solve();
  print_answers();
}

void init() {
  fin >> N >> M;
  FOR(p, 0, M + 1) {
    FOR(q, p, M + 1) { is_bisquare[p * p + q * q] = true; }
  }
}

void solve() {
  


}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}