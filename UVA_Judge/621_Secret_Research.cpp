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
		string st;
		cin >> st;
		int N = st.size();
		bool isok = true;
		if (N >= 1 && isok) {
			if (st == "1" || st == "4" || st == "78") { cout << "+" << endl; isok = false; }
		}
		if (N >= 2 && isok) {
			if (st[N - 2] == '3' && st[N - 1] == '5') { cout << "-" << endl; isok = false; }
			else if (st[0] == '9' && st[N - 1] == '4') { cout << "*" << endl; isok = false; }
		}
		if (N >= 3 && isok) {
			if (st[N-4] == '1' && st[N-3] == '9' && st[N-2] == '0') cout << "?" << endl;
		}
	}



	return 0;
}
