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
void init();


int main() {
  setIO();
  ll N;
  while (cin >> N, N > 0) {

	if (N <= 2) {
		cout << "0" << endl;
	} else {

	ll total = (1 << N);


	int a[N + 5];

	a[0] = a[1] = 1, a[2] = 2;

	FOR(i, 3, N + 2) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}

	cout << total - a[N + 1] << endl;
     }
  }
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

