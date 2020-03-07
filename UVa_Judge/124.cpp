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

/* Print all topological orderings. */
map<int, int> freq;
int indeg[26];
int d;


/* kahn's topological sort algorithm w/ backtracking. */
void gen(string s, vector<vector<int>>& AdjList) {
	if (s.size() == d) {
		cout << s << endl;
	}

	F0R(i, 26) {
		if (freq[i] > 0 && indeg[i] == 0) {
			freq[i]--;

			F0R(j, AdjList[i].size()) {
				indeg[AdjList[i][j]]--;
			}
			gen(s + ((char) (i + 97)), AdjList);

			freq[i]++;
			F0R(j, AdjList[i].size()) {
				indeg[AdjList[i][j]]++;
			}
		}
	}
	// if we get here, then there are no more to process.
}

int main() {
	bool fst = true;
	string vars, constraints;
	while (getline(cin, vars)) {
		if (!fst) cout << endl;
		fst = false;
		vector<vector<int>> AdjList(26);
		memset(indeg, 0, sizeof(indeg));
		freq.clear();
		d = 0;
		istringstream iss(vars);
		char tmp;
		while (iss >> tmp) {
			freq[tmp - 'a']++;
			d++;
		}
		getline(cin, constraints);
		istringstream iss2(constraints);
		char fst, snd;
		while (iss2 >> fst >> snd) {
			AdjList[fst - 'a'].pb(snd - 'a');
			indeg[snd - 'a']++;
		}
		gen("", AdjList);


	}
	return 0;
}
