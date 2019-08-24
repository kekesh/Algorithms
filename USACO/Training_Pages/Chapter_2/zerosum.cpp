/*
  ID: ekfrmd1
  LANG: C++11
  TASK: zerosum
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
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void solve();
void setIO();
inline void init();
void dec_to_ternary(ll num);
void print_ans();

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

ll N;
ll pows[11] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
ll rep[10];
set<string> all_answers;

int main() {
  setIO();
  init();
  F0R(i, pows[N - 1]) {
    memset(rep, 0, sizeof(rep));
    dec_to_ternary(i);
    stack<ll> s;
    s.push(1);
    FOR(i, 2, N + 1) {
      switch (rep[i - 2]) {
        case 0:  // Add
          s.push(i);
          break;
        case 1:
          s.push(-i);
          break;
        case 2:
          ll x = s.top();
          s.pop();
          x *= 10;
          if (x > 0) {
            x += i;
          } else {
            x -= i;
          }
          s.push(x);
      }
    }
    stack<ll> copy = s;
    ll sum = 0;
    while (!s.empty()) {
      sum += s.top();
      s.pop();
    }
    if (sum == 0) {
      string ans = "";
      FOR(i, 1, N + 1) {
        ans += to_string(i);
        if (i == N) {
          break;
        }
        if (rep[i - 1] == 0) {
          ans += "+";
        } else if (rep[i - 1] == 1) {
          ans += "-";
        } else if (rep[i - 1] == 2) {
          ans += " ";
        }
      }
      // RB tree will automatically sort
      all_answers.insert(ans);
      
    }
  }
  print_ans();
  return 0;
}

void print_ans() {
    set<string>::iterator it = all_answers.begin();
    while (it != all_answers.end()) {
        fout << *it++ << endl;
    }

}

void dec_to_ternary(ll num) {
  F0Rd(i, 9) {
    rep[i] += num / pows[i];
    num -= rep[i] * pows[i];
  }
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

inline void init() { fin >> N; }
