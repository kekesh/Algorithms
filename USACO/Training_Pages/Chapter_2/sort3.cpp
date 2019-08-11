/*
  ID: ekfrmd1
  LANG: C++11
  TASK: sort3
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

void init();
void solve();
void setIO();
inline void init();
int gcd(int a, int b);

ifstream fin("sort3.in");
ofstream fout("sort3.out");

ll N;
ll nums[1005];
ll total_ones, total_twos, total_threes;

struct Interval {
  ll start_index, end_index;
  ll num_ones, num_twos, num_threes;
};

int main() {
  setIO();
  init();
  fin.close();
  solve();
  fout.close();
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

inline void init() {
  fin >> N;
  F0R(i, N) { fin >> nums[i]; }
}

void solve() {
  F0R(i, N) {
    switch (nums[i]) {
      case 1:
        total_ones++;
        break;
      case 2:
        total_twos++;
        break;
      case 3:
        total_threes++;
        break;
    }
  }
  Interval ONES = {0, total_ones - 1};
  Interval TWOS = {total_ones, total_ones + total_twos - 1};
  Interval THREES = {total_ones + total_twos,
                     total_ones + total_twos + total_threes - 1};

  FOR(i, ONES.start_index, ONES.end_index + 1) {
    switch (nums[i]) {
      case 1:
        ONES.num_ones++;
        break;
      case 2:
        ONES.num_twos++;
        break;
      case 3:
        ONES.num_threes++;
        break;
    }
  }

  FOR(i, TWOS.start_index, TWOS.end_index + 1) {
    switch (nums[i]) {
      case 1:
        TWOS.num_ones++;
        break;
      case 2:
        TWOS.num_twos++;
        break;
      case 3:
        TWOS.num_threes++;
        break;
    }
  }

  FOR(i, THREES.start_index, THREES.end_index + 1) {
    switch (nums[i]) {
      case 1:
        THREES.num_ones++;
        break;
      case 2:
        THREES.num_twos++;
        break;
      case 3:
        THREES.num_threes++;
        break;
    }
  }

  ll answer = 0;
  answer += MIN(ONES.num_twos, TWOS.num_ones) +
            MIN(ONES.num_threes, THREES.num_ones) +
            MIN(TWOS.num_threes, THREES.num_twos);
  answer += 2 * (total_ones - MIN(ONES.num_twos, TWOS.num_ones) -
             MIN(ONES.num_threes, THREES.num_ones) - ONES.num_ones);

  fout << answer << endl;
}