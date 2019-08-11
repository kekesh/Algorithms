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

void setIO();
inline void init();
int cut_rod(int p[], int n);

int main() {
  setIO();
  int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  int N = 1;
  cout << "Answer: " << cut_rod(p, 10) << endl;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/* Recursive top-down solution to the rod cutting problem.
   This is really inefficient; the same subproblems are solved
   multiple times.  */
int cut_rod(int p[], int n) {
  if (n == 0) {
    return 0;
  }
  int answer = -10e6;

  FOR(i, 1, n + 1) {
    cout << "i = " << i << endl;
    answer = MAX(answer, p[i - 1] + cut_rod(p, n - i));
  }
  return answer;
}