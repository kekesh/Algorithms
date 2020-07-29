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
typedef vector<int> vi;




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
const int MOD2 = 1e8;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);


ll N, M;
bool possible[201][201][201];
int rgb[3];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		string s;
		cin >> s;
		F0R(i, (int) s.size()) {
				if (s[i] == 'R') rgb[0]++;
				else if (s[i] == 'G') rgb[1]++;
				else rgb[2]++;
		}

		possible[rgb[0]][rgb[1]][rgb[2]] = true;


		for (int sum = N; sum >= 0; sum--) {
//				cout << "Sum = " << sum << endl;
				for (int r = 0; r <= sum; r++) {
						for (int g = 0; g <= sum; g++) {
								int b = sum - (r + g);
								if (b >= 0 && possible[r][g][b]) {
										//cout << "(r, g, b) = (" << r << "," << g << "," << b << ")" << endl;
										if (r > 0 && g > 0) possible[r - 1][g - 1][b + 1] |= possible[r][g][b];
										if (r > 0 && b > 0) possible[r - 1][g + 1][b - 1] |= possible[r][g][b];
										if (b > 0 && g > 0) possible[r + 1][g - 1][b - 1] |= possible[r][g][b];
										
										if (r >= 2) {
												possible[r - 1][g][b] |= possible[r][g][b];
										}
										if (b >= 2) {
												possible[r][g][b - 1] |= possible[r][g][b];
										}
										if (g >= 2) {
												possible[r][g - 1][b] |= possible[r][g][b];
										}
								}
						}
				}
		}
		string ans = "";
		if (possible[0][0][1]) ans += "B";
		if (possible[0][1][0]) ans += "G";
		if (possible[1][0][0]) ans += "R";
		cout << ans << endl;
}
