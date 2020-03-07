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
int dice[1000];
ll N;
int main() {

	ll roll;
	int i = 0;
	while (cin >> roll) {
		if (roll == 0) break;
		dice[i++] = roll;
	}
	while (cin >> N, N) {
		int playerpos[6];
		int lostturn[6];
		memset(playerpos, 0, sizeof(playerpos));
		memset(lostturn, false, sizeof(lostturn));
		unordered_map<int, int> m;
		unordered_set<int> lose;
		unordered_set<int> gain;
		ll from, to;

		F0R(i, 100) m[i] = i;
		while (cin >> from >> to) {
			if (from == 0 && to == 0) break;
			m[from] = to;
		}
		ll special;
		while (cin >> special, special != 0) {
			if (special < 0) lose.insert(-special);
			else gain.insert(special);
		}

		// Simulate dice game.
		bool gameover = false;
		int curr_player = 0;
		int roll = 0;
		while (!gameover) {
			if (lostturn[curr_player]) {
				lostturn[curr_player] = false;
				curr_player = (curr_player + 1) % N;
				continue;
			}
			playerpos[curr_player] += dice[roll++];

			if (playerpos[curr_player] == 100) {
				cout << curr_player + 1 << endl;
				gameover = true;
				break;
			}
			playerpos[curr_player] = m[playerpos[curr_player]];

			if (gain.find(playerpos[curr_player]) != gain.end()) {
				continue;
			}

			if (lose.find(playerpos[curr_player]) != lose.end()) {
				lostturn[curr_player] = true;
			}
			curr_player = (curr_player + 1) % N;

		}


	}


	return 0;
}
