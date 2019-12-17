#include <assert.h>
#include <math.h>
#include <string.h>
#include <queue>
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

int d(string a, string b) {

	int cnt = 0;
	F0R(i, a.size()) {
		if (a[i] != b[i]) cnt++;
	}
	return cnt;

}


int main() {

	ll T;
	cin >> T;

	while (T--) {
		string st;
		cin >> st;
		if (d("one", st) <= 1) cout << 1 << endl;
		else if (d("two", st) <= 1) cout << 2 << endl;
		else if (d("three", st) <= 1) cout << 3 << endl;
	}

	return 0;

}
