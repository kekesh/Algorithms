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

	ll T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;

		int arr[150];
		ll p = 0;
		F0R(i, N) {
			string st;
			cin >> st;
			if (st == "LEFT") {
				arr[i] = -1;
				p -= 1;
			} else if (st == "RIGHT") {
				arr[i] = 1;
				p += 1;
			} else if (st == "SAME") {
				string s1, s2;
				cin >> s1 >> s2;
				int x = stoi(s2);
				p += arr[x - 1];
				arr[i] = arr[x - 1];
			}
		}
		cout << p << endl;

	}

	return 0;

}
