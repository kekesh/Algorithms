/*
  ID: ekfrmd1
  LANG: C++11
  TASK: subset
*/

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
inline void init();
int solve(int operations, string current);

string str;
inline void init() { cin >> str; }

int main() {
  setIO();
  init();
  cout << solve(0, str);
  return 0;
}

int solve(int operations, string current) {
  ll answer = INFTY;

  if (stoi(current) == 0) {
    return operations;
  }

  F0R(i, str.length()) {
    if (current[i] - 48 != 0) {
      int new_str_int = stoi(current) - (current[i] - 48);
      string new_str = to_string(new_str_int);
      cout << new_str << "\n";
      ll x = solve(operations + 1, new_str);
      answer = MIN(answer, x);
    }
  }
  return answer;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}