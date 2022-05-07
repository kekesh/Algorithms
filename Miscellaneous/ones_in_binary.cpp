/* Given an integer N, return the number of occurrences of "1" in the 
   base 2 (binary) representation of N. */

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


int main() {
  ll N;
  cin >> N;
  ll count = 0;
  while (N > 0) {
      N &= (N-1), count++;
  }
  cout << "Answer: " << count << endl;
  return 0;
}
