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


vector<string> deck;

void constructDeck() {
	FOR(i, 2, 11) {
		deck.pb((to_string(i) + " of Clubs"));
	}
	deck.pb("Jack of Clubs");
	deck.pb("Queen of Clubs");
	deck.pb("King of Clubs");
	deck.pb("Ace of Clubs");
	FOR(i, 2, 11) {
		deck.pb((to_string(i) + " of Diamonds"));
	}
	deck.pb("Jack of Diamonds");
	deck.pb("Queen of Diamonds");
	deck.pb("King of Diamonds");
	deck.pb("Ace of Diamonds");
	FOR(i, 2, 11) {
		deck.pb((to_string(i) + " of Hearts"));
	}
	deck.pb("Jack of Hearts");
	deck.pb("Queen of Hearts");
	deck.pb("King of Hearts");
	deck.pb("Ace of Hearts");
	FOR(i, 2, 11) {
		deck.pb((to_string(i) + " of Spades"));
	}
	deck.pb("Jack of Spades");
	deck.pb("Queen of Spades");
	deck.pb("King of Spades");
	deck.pb("Ace of Spades");

}

vector<string> apply_function(vector<int> fn) {

	vector<string> ret(52);

	F0R(i, 52) {
		ret[i] = deck[fn[i] - 1];
	}

	return ret;

}

int main() {
	ll T;
	cin >> T;

	while (T--) {
		deck.clear();
		constructDeck();
		vector<vector<int>> functions(101, vector<int>(52));

		ll num_functions;
		cin >> num_functions;
		F0R(i, num_functions) {
			F0R(j, 52) {
				cin >> functions[i][j];
			}
		}
		getchar();
		string to_apply;
		while (getline(cin, to_apply)) {
			if (to_apply.empty()) break;
			else {
				deck = apply_function(functions[stoi(to_apply) - 1]);
			}
		}


		F0R(i, 52) {
			cout << deck[i] << endl;
		}
		if (T) cout << "\n";
	}

	return 0;
}
