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



int main() {

	ll T;
	cin >> T;
	while (T--) {
		ll N;

		cin >> N;
		ll diff;
		bool isfirst = true;
		bool isok = true;
		F0R(i, N) {
			ll x, y;
			cin >> x >> y;
			if (isfirst) diff = (y - x);
			else if ((y - x) != diff) {isok = false; }
			isfirst = false;
		}

		string ans = isok? "yes" : "no";
		cout << ans << endl;

		if (T != 0) cout << "\n";

	}

	return 0;

}
