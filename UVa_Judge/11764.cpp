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
typedef unsigned long long ull;
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


//ofstream fout("output.out");
int main() {

	ll T;
	cin >> T;
	int j = 0;
	while (T--) {
		ll N;
		cin >> N;
		ll curr, prev;
		cin >> prev;
		ll lo, hi;
		lo = hi = 0;
		F0R(i, N - 1) {
			cin >> curr;
			if (prev < curr) {
				hi++;
			} else if (prev > curr) {
				lo++;
			}
			prev = curr;
		}

		cout << "Case " << ++j << ": " << hi << " " << lo << endl;

	}

	return 0;

}
