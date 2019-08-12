/*
  ID: ekfrmd1
  LANG: C++11
  TASK: hamming
*/

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>

#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void setIO();
inline void init();
void solve();
int hdist(int x, int y);

ifstream fin("hamming.in");
ofstream fout("hamming.out");

ll N, B, D;
ll nums[70];

int main() {
  setIO();
  init();
  fin.close();
  solve();
  fout.close();
}

void solve() {
  int candidate = 0, size = 0;

  while (size < N && candidate < (1 << B) + 1) {
    bool flag = true;

    FOR(i, 0, size) {
      if (hdist(nums[i], candidate) < D) {
        flag = false;
        break;
      }
    }

    if (flag) {
      nums[size++] = candidate;
      if (size % 10 == 0 || size >= N) {
        fout << candidate << "\n";
      } else {
        fout << candidate << " ";
      }
    }
    candidate++;
  }
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

inline void init() { fin >> N >> B >> D; }

int hdist(int x, int y) {
  int z = x ^ y;
  int dist = 0;
  while (z) {
    if (z % 2 == 1) {
      dist++;
    }

    z >>= 1;
  }
  return dist;
} 