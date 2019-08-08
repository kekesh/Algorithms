/* ID: ekfrmd1
   LANG: C++
   TASK: sprime
*/

#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)

inline void init();
void sieve(ll bound);
void setIO();
ll solve();

ifstream fin("sprime.in");
ofstream fout("sprime.out");

ll N;
bitset<50000005> is_composite;
vector<ll> palindromes;

int main() {
  setIO();
  init();
  fin.close();
  sieve(pow(10, N) + 5);
  solve();
  fout.close();
  return 0;
}

ll num = 0;

ll solve() {
  if (num >= pow(10, N - 1) && num < pow(10, N)) {
    fout << num << endl;
    return num;
  }
  F0R(i, 10) {
    num = num * 10 + i;
    if (num == 2 || (num & 1 && !is_composite[num / 2])) {
      solve();
    }
    num /= 10;  // Backtracking
  }
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

inline void init() { fin >> N; }

/* O(n log log n) bit sieve */
/* Skip all even numbers. */
void sieve(ll bound) {
  is_composite[0] = true;
  /* We only need to check odd rs. Each odd number x maps to x/2. */
  for (int i = 3; i * i < bound; i += 2) {
    if (is_composite[i / 2] == false)
      for (int j = i * i; j < bound; j += 2 * i) {
        is_composite[j / 2] = true;
      }
  }
}