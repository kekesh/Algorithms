#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;

typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);

// Start of code.
int scores[40];
char res[40];

int idx;

int main() {
	string nxt;
	while (getline(cin, nxt)) {
		if (nxt == "Game Over") break;
		istringstream iss(nxt);
		int i = 0;
		while (iss >> res[i]) {
			i++;
		}
		i--;
		ll sum = 0;
		ll turn = 9;
		while (i >= 0) {
			cout << "i = " << i << endl;
			char fst, snd;
			snd = res[i];
			cout << "snd = " << snd << endl;
			if (snd == 'X') {
				if (i == 9) cout << "Here when i = " << 9 << endl;
				scores[i] = 10;
				sum += 10 + scores[i + 1] + scores[i + 2];
			} else {
				i--;
				fst = res[i];
				if (fst == '1' && snd == '/') cout << "i = " << i <<  " and " << fst - '0' << endl;
				cout << "fst = " << fst << endl;
				if (snd == '/') {
					scores[i] = fst - '0';
					scores[i + 1] = 10 - scores[i];
					sum += 10 + scores[i + 2];
				} else {
					scores[i] = fst - '0';
					scores[i + 1] = snd - '0';
					sum += scores[i] + scores[i + 1];
				}
			}
			i--;
			cout << "sum is now " << sum << endl;
		}
		cout << "sum: " << sum << endl;
	}

	return 0;
}
