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


int main() {
	ll T;
	cin >> T;
	int j = 0;
	while (T--) {
		ll M;
		cin >> M;
		getchar();

		float points = 0;
		int oudlers = 0;
		F0R(i, M) {
			string card;
			getline(cin, card);
			/* Determine point value */
			if (card == "fool") {
				points += 4.5;
				oudlers++;
			} else if (card == "twenty-one of trumps") {
				points += 4.5;
				oudlers++;
			} else if (card == "one of trumps") {
				points += 4.5;
				oudlers++;
			} else if (card.substr(0, 4) == "king") {
				points += 4.5;
			} else if (card.substr(0, 5) == "queen") {
				points += 3.5;
			} else if (card.substr(0, 6) == "knight") {
				points += 2.5;
			} else if (card.substr(0, 4) == "jack") {
				points += 1.5;
			} else {
				points += 0.5;
			}
		}
		int pts_needed = 56;
		if (oudlers == 1) pts_needed = 51;
		else if (oudlers == 2) pts_needed = 41;
		else if (oudlers == 3) pts_needed = 36;

		cout << "Hand #" << ++j << endl;
		if (points - pts_needed >= 0) {
			cout << "Game won by " << (points - pts_needed) << " point(s)." << endl;
		} else {
			cout << "Game lost by " << (pts_needed - points) << " point(s)." << endl;
		}

		if (T) cout << "\n";
	}
	return 0;
}
