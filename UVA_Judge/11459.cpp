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

int m[101];
int playerpos[1000001];

int main() {
	ll T;
	cin >> T;
	while (T--) {
		F0R(i, 100) m[i] = i;
		int num_players, b, dice_rolls;
		cin >> num_players >> b >> dice_rolls;
		F0R(i, num_players) playerpos[i] = 0;
		F0R(i, b) {
			ll from, to;
			cin >> from >> to;
			m[from - 1] = (to - 1);
		}


		ll curr_player = 0;
		bool gameover = false;
		F0R(i, dice_rolls) {
			ll roll;
			cin >> roll;
			if (!gameover) {
				playerpos[curr_player] += roll;
				if (playerpos[curr_player] >= 99) playerpos[curr_player] = 99;
				playerpos[curr_player] = m[playerpos[curr_player]];
				if (playerpos[curr_player] == 99) {
					gameover = true;
				}
				if (num_players != 0) curr_player = (curr_player + 1) % num_players;
			}
		}

		F0R(i, num_players) {
			cout << "Position of player " << (i + 1) << " is " << (playerpos[i] + 1) << "." << endl;
		}
	}
	return 0;
}
