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
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

void init();
void setIO();
void solve();
void print_answers();

ifstream fin("homework.in");
ofstream fout("homework.out");

// multiset<ll> bisquares;
double scores[100010];
double prefix[100010];
double weighted_gr[100010];

int N;

int main() {
  setIO();
  init();
  solve();
}

void solve() {
  double maxavg = -1;
  int ind = -1;
  F0Rd(i, N) {
    double tempavg = weighted_gr[i];
    if (maxavg < tempavg) {
      maxavg = tempavg;
    }
  }
}

void init() {
  fin >> N;
  F0R(i, N) { fin >> scores[i]; }
  prefix[N - 1] = scores[N - 1];
  F0Rd(i, N - 1) { prefix[i] = prefix[i + 1] + scores[i]; }
  int min = 10e7;
  F0Rd(i, N) {
    if (scores[i] < min) {
      min = scores[i];
    }
    weighted_gr[i] = (prefix[i] - min) / (N - i - 1);
  }
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}
