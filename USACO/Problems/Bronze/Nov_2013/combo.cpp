/* ID: ekfrmd1
   LANG: C++
   TASK: combo
*/
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

void init();
void solve();
int dist(int a, int b);

ifstream fin("combo.in");
ofstream fout("combo.out");

int N;
ll a, b, c, x, y, z;

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> N;
  fin >> a >> b >> c;
  fin >> x >> y >> z;
  a %= N;
  b %= N;
  c %= N;
  x %= N;
  y %= N;
  z %= N;
}

int main() {
  setIO();
  init();
  solve();
}

/* Principle of Inclusion-Exclusion */
void solve() {
  if (N <= 4) {
    fout << N*N*N << endl;
    exit(0);
  }

  
  int answer = 5*5*5 + 5*5*5;
  int minx = ((min(a, x) - 2) % N + N) % N;
  int miny = ((min(b, y) - 2) % N + N) % N;
  int minz = ((min(c, z) - 2) % N + N) % N;
  
  int maxx = ((min(a, x) + 3) % N + N) % N;
  int maxy = ((min(b, y) + 3) % N + N) % N;
  int maxz = ((min(c, z) + 3) % N + N) % N;
  
  
  if (minx == maxx && miny == maxy && minz == maxz) {
    fout << N*N*N << endl;
    exit(0);
  }

  for (int i = minx; i != maxx; i = (i + 1) % N) {
    for (int j = miny; j != maxy; j = (j + 1) % N) {
      for (int k = minz; k != maxz; k = (k + 1) % N) {
        
        if (dist(i, a) <= 2 && dist(i, x) <= 2 && dist(j, b) <= 2 &&
            dist(j, y) <= 2 && dist(k, c) <= 2 && dist(k, z) <= 2) {
            /* Overlap. */
          answer--;
        }
      }
    }
  }
  fout << answer << endl;
}

/* Computes modular distance. */
int dist(int a, int b) {
  return min(((a - b) % N + N) % N, ((b - a) % N + N) % N);
}