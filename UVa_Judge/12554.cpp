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

	const string lyrics[] = {"Happy", "birthday", "to", "you",
			   "Happy", "birthday", "to", "you",
			   "Happy", "birthday", "to", "Rujia",
			   "Happy", "birthday", "to", "you"};
	string people[101];
	ll N;
	cin >> N;
	F0R(i, N) {
		cin >> people[i];
	}

	int start = 0;
	int end = 0;
	ll mod = N;
	while (N > 0) {
		int k = start;

		F0R(j, 16) {
			cout << people[k] << ": " << lyrics[j] << endl;
			k = (k + 1) % mod;
		}
		start += 16;
		N -= 16;
	}

	return 0;

}
