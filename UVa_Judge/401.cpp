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


bool check(char x, char y) {
	if ((x == 'A' && y == 'A') || (x == 'E' && y == '3') || (x == 'H' && y == 'H') || (x == 'I' && y == 'I') || (x == 'J' && y == 'L') || (x == 'L' && y == 'J') || (x == 'M' && y == 'M') || (x == 'O' && y == 'O') || (x == 'S' && y == '2') || (x == 'T' && y == 'T') || (x == 'U' && y == 'U') || (x == 'V' && y == 'V') || (x == 'W' && y == 'W') || (x == 'X' && y == 'X') || (x == 'Y' && y == 'Y') || (x == 'Z' && y == '5') || (x == '1' && y == '1') || (x == '2' && y == 'S') || (x == '3' && y == 'E') || (x == '5' && y == 'Z') || (x == '8' && y == '8')) {
	       return true;
	}
	return false;
}

bool ispalin(string st) {

	F0R(i, st.size()/2) {
		if (st[i] != st[st.size() - i - 1]) return false;
	}
	return true;

}

bool ismirrored(string st) {

	if (st.size() & 1) {
		char mid = st[st.size()/2];
		if (mid != 'A' && mid != 'H' && mid != 'I' && mid != 'T' && mid != 'M' && mid != 'O' && mid != 'V' && mid != 'X' && mid != 'W' && mid != 'Y' && mid != 'U' && mid != '1' && mid != '8') return false;
	}

	F0R(i, st.size()/2) {
		char x = st[i];
		char y = st[st.size() - i - 1];
		if (!check(x, y)) {
			return false;
		}
	}
	return true;
}


int main() {
	string st;
	while (cin >> st) {
		bool x = ispalin(st);
		bool y = ismirrored(st);
		if (x && y) {
		       cout << st << " -- is a mirrored palindrome." << endl;
		} else if (!x && y) {
	 		cout << st << " -- is a mirrored string." << endl;
		} else if (x && !y) {
			cout << st << " -- is a regular palindrome." << endl;
		} else {
			cout << st << " -- is not a palindrome." << endl;
		}
		cout << "\n";
	}

	return 0;
}
