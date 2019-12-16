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

	int reserves[500];
	ll B, N;

	while (cin >> B >> N) {
		if (B == 0 || N == 0) break;

		F0R(i, B) {
			cin >> reserves[i];
		}
		bool isok = true;
		F0R(i, N) {
			ll D, C, V;
			cin >> D >> C >> V;
			reserves[D - 1] -= V;
			reserves[C - 1] += V;
		}
		F0R(i, B) {
			isok = isok && (reserves[i] >= 0);
		}
		if (isok) cout << "S" << endl;
		else cout << "N" << endl;

	}
	return 0;
}
