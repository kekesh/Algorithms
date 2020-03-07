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


string guess;
int s, w;
int cnt;


pair<int, int> count(string code, string guess) {
	int sz = code.size();
	int strong, weak;
	strong = weak = 0;
	bool takencode[11];
	bool takenguess[11];
	memset(takencode, false, sizeof(takencode));
	memset(takenguess, false, sizeof(takenguess));

	F0R(i, sz) {
		if (code[i] == guess[i]) {
			takencode[i] = takenguess[i] = true;
			strong++;
		}
	}

	F0R(i, sz) {
		F0R(j, sz) {
			if (!takencode[i] && !takenguess[j] && code[i] == guess[j]) {
				takencode[i] = takenguess[j] = true;
				weak++;
			}
		}
	}

	return make_pair(strong, weak);


}

void gen(int length, int depth, string st) {
	if (depth == length) {
		pi res = count(st, guess);
		if (res.first == s && res.second == w) {
			cnt++;

		}
		return;
	}

	FOR(i, 1, 10) {
		gen(length, depth + 1, st + to_string(i));
	}
}

int main(void) {

	ll T;
	cin >> T;
	while (T--) {
		cin >> guess >> s >> w;
		cnt = 0;
		gen(guess.size(), 0, "");
		cout << cnt << endl;
	}

	return 0;
}
