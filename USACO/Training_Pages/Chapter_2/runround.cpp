/*
  ID: ekfrmd1
  LANG: C++11
  TASK: runround
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
bool is_runaround(ll num, ll len);
ll process(ll num, ll len);

ifstream fin("runround.in");
ofstream fout("runround.out");

ll N;
ll len;

inline void init() { cin >> N; }

int main() {
  setIO();
  init();

  ll target = N + 1;
  ll len = to_string(target).size();

  while (!(is_runaround(target, len))) {
    target = process(target, len);

    len = to_string(target).size();
  }
  cout << target << endl;

  return 0;
}

ll process(ll num, ll len) { 
  
  ll num_arr[len + 1];
  int i = len;
  ll temp = num;
  bool flag = false;
  ll digits[10];
  memset(digits, 0, sizeof(digits));
  while (i > 0) {
    num_arr[--i] = temp % 10;
    if (digits[temp % 10] > 0) flag = true;
    digits[temp % 10]++;
    temp /= 10;
  }

  if (!flag && digits[(num_arr[len - 1] + 1) % 10] > 0) {
    num += 1;
    flag = true;
  }

  if (flag) {
    F0R(i, len) {
      FOR(j, i + 1, len) {
        if (num_arr[i] == num_arr[j]) {
          num += pow(10, len - j - 1);
        }
      }
    }
    return num;
  }

  // No equal digits.


  return num + 1; 
  
}

bool is_runaround(ll num, ll len) {
  if (len == 1) {
    return true;
  }

  bool visited[len + 1];
  bool digits[10];
  memset(visited, false, sizeof(digits));
  int i = len;
  ll temp = num;
  int num_arr[len + 1];

  while (i > 0) {
    num_arr[--i] = temp % 10;

    if ((temp % 10) % len == 0) {
      return false;
    }
    temp /= 10;
  }

  memset(digits, false, sizeof(digits));
  int count = 0;

  int prev = -1;
  while (1) {
    if (visited[i] == true) {
      if (i == 0 && count == len) {
        return true;
      }
      return false;
    }
    int x = num_arr[i];
    if (digits[x] == true) {
      return false;
    }
    digits[x] = true;
    visited[i] = true;
    count++;

    i = (i + x) % len;
    prev = x;
  }

  return false;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}