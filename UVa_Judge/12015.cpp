#include <assert.h>
#include <math.h>
#include <queue>
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
	int j = 0;
	while (T--) {

		queue<string> urls;
		int maxi = -1;
		F0R(i, 10) {
			string url;
			int V;
			cin >> url >> V;
			if (V > maxi) {
				maxi = V;
				while (!urls.empty()) {
					urls.pop();
				}
				urls.push(url);
			} else if (V == maxi) {
				urls.push(url);
			}
		}
		cout << "Case #" << ++j << ":" << endl;
		while (!urls.empty()) {
			string st = urls.front();
			cout << st << endl;
			urls.pop();
		}


	}

	return 0;

}
