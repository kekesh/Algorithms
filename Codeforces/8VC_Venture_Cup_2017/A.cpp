#include <assert.h>
#include <math.h>
#include <string.h>
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

void setIO();

bool prime[1000001];
ll N;

void sieve() {
	FOR(i, 2, sqrt(1000*N)+1) {
		if (prime[i]) {
			for (int j = i*i; j <= 1000*N; j += i) {
				prime[j] = false;
			}
		}
	}
	FOR(m, 1, 1000) {
		if (!prime[N*m + 1]) {
			cout << m << endl;
			exit(0);
		}
	}

}

int main() {
  setIO();
  cin >> N;
  memset(prime, true, sizeof(prime));
  sieve();
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
