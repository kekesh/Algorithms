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


int main() {
	string st;

	int j = 0;
	while (cin >> st, st != "#") {

		string ans;

		if (st == "HELLO") ans = "ENGLISH";
		else if (st == "HOLA") ans = "SPANISH";
		else if (st == "HALLO") ans = "GERMAN";
		else if (st == "BONJOUR") ans = "FRENCH";
		else if (st == "CIAO") ans = "ITALIAN";
		else if (st == "ZDRAVSTVUJTE") ans = "RUSSIAN";
		else ans = "UNKNOWN";

		cout << "Case " << ++j << ": " << ans << endl;
	}


	return 0;

}
