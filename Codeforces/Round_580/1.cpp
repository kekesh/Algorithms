#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
void init();
void solve();

ll N, M;
unordered_set<ll> nums_a;
unordered_set<ll> nums_b;

int main() {
  setIO();
  init();
}

void init() {
  cin >> N;
  ll x;
  F0R(i, N) {
    cin >> x;
    nums_a.insert(x);
  }
  cin >> M;
  F0R(i, M) {
    cin >> x;
    nums_b.insert(x);
  }
  unordered_set<ll>::iterator itr = nums_a.begin();
  unordered_set<ll>::iterator itr2 = nums_b.begin();

  while (itr != nums_a.end()) {
    itr2 = nums_b.begin();
    while (itr2 != nums_b.end()) {
      if (!nums_a.count(*itr + *itr2) && !nums_b.count(*itr + *itr2)) {
        cout << *itr << " " << *itr2 << endl;
        exit(0);
      }
      itr2++;
    }
    itr++;
  }
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {}