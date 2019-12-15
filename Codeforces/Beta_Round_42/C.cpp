#include <assert.h>
#include <math.h>
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

const ll INF = 1e18;

// Debugging macros
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"


int cnt[3];

int main(void) {

	ll N, x;
	cin >> N;
	F0R(i, N) {
		cin >> x;
		cnt[x%3]++;
	}
	ll ans = 0;

	// pair 0's with 0's.
	ans += cnt[0]/2;
	// pair 1's with 2's.
	ans += MIN(cnt[1], cnt[2]);
	cout << ans << endl;
	return 0;

}
