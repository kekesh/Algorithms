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
	ll T, N;
	cin >> T;
	int case_no = 0;
	while (T--) {
		cin >> N;
		case_no++;
		cout << "Case " << (case_no) << ": ";
		if (N <= 1) cout << 0 << endl;
		else if (N == 2) cout << "1/2" << endl;
		else {
			ll p = N * (N - 1);
			ll q = 4;
			ll G = __gcd(p, q);
			if (G == 4) cout << p/4 << endl;
			else cout << p/G << "/" << q/G << endl;
		}
	}
	return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
