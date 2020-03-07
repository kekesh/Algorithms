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


stack<string> mergestacks(stack<string> playerStack, vector<string> middleStack) {

	stack<string> tmp;

	while (


}

int main() {

	stack<string> player, dealer;

	F0R(i, 52) {
		string nxt;
		cin >> nxt;
		if (i & 1) {
			cout << "Giving " << nxt << " to dealer." << endl;
			dealer.push(nxt);
		}
		else {
			cout << "Giving " << nxt << " to player. " << endl;
			player.push(nxt);
		}
	}
	/* Cards have been dealt. */
	bool playernext = true;
	int num_to_play = 1;
	int getting_cards = -1;
	vector<string> playedCards;
	while (!player.empty() && !dealer.empty()) {
		string cardplayed = "";
		bool flag = true;
		if (playernext) {
			F0R(i, num_to_play) {
				cardplayed = player.top();
				player.pop();
				playedCards.pb(cardPlayed);
				if (cardplayed[1] == 'A') {
					getting_cards = 1;
					num_to_play = 4;
					flag = false;
					break;
				} else if (cardplayed[1] == 'K') {
					getting_cards = 1;
					num_to_play = 3;
					flag = false;
					break;
				} else if (cardplayed[1] == 'Q') {
					getting_cards = 1;
					num_to_play = 2;
					flag = false;
					break;
				} else if (cardplayed[1] == 'J') {
					getting_cards = 1;
					num_to_play = 1;
					flag = false;
					break;
				}
			}
			if (flag) num_to_play = 1;
		} else {
			F0R(i, num_to_play) {
				cardplayed = dealer.top();
				dealer.pop();
				playedCards.pb(cardPlayed);
				if (cardplayed[1] == 'A') {
					getting_cards = 2;
					num_to_play = 4;
					flag = false;
					break;
				} else if (cardplayed[1] == 'K') {
					getting_cards = 2;
					num_to_play = 3;
					flag = false;
					break;
				} else if (cardplayed[1] == 'Q') {
					getting_cards = 2;
					num_to_play = 2;
					flag = false;
					break;
				} else if (cardplayed[1] == 'J') {
					getting_cards = 2;
					num_to_play = 1;
					flag = false;
					break;
				}
			}
			if (flag) num_to_play = 1;
		}

		if (flag && getting_cards == 1) {

			getting_cards = -1;
		} else if (flag && getting_cards == 2) {

			getting_cards = -1;
		}
		playernext = !playernext;
	}


	return 0;
}
