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
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);


ll N, Q;
bool possible[2][200005][7];
char grid[2][200005];

bool isbar(char x) {
		return (x == '1' || x == '2');
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> Q;
		while (Q--) {
				cin >> N;
				cin >> grid[0] >> grid[1];
				
				F0R(i, N) {
						for (int j = 1; j <= 6; j++) {
								possible[0][i][j] = false;
								possible[1][i][j] = false;
						}
				}
				possible[0][0][2] = isbar(grid[0][0]);
				possible[0][0][4] = !isbar(grid[0][0]);


				possible[1][0][1] |= ((possible[0][0][1] || possible[0][0][4]) && isbar(grid[1][0]));
				possible[1][0][5] |= ((possible[0][0][1] || possible[0][0][4]) && !isbar(grid[1][0]));
				possible[1][0][6] |= ((possible[0][0][4]) && !isbar(grid[1][0]));

				for (int col = 1; col < N; col++) {
//						for (int i = 1; i <= 2; i++) {

							possible[0][col][2] |= ((possible[0][col - 1][2] || possible[0][col - 1][3]) && isbar(grid[0][col]));
							possible[0][col][4] |= ((possible[0][col - 1][2] || possible[0][col - 1][3]) && !isbar(grid[0][col]));
							possible[0][col][5] |= ((possible[0][col - 1][2] || possible[0][col - 1][3]) && !isbar(grid[0][col]));
							possible[1][col][2] |= ((possible[1][col - 1][2] || possible[1][col - 1][6]) && isbar(grid[1][col]));
							possible[1][col][5] |= ((possible[1][col - 1][2] || possible[1][col - 1][6]) && !isbar(grid[1][col]));

							bool a = ((possible[1][col][1] || possible[1][col][5]) && isbar(grid[0][col]));
							bool b = ((possible[1][col][5] || possible[1][col][1]) && !isbar(grid[0][col]));
							bool c = ((possible[0][col][1] || possible[0][col][4]) && isbar(grid[1][col]));
							bool d = ((possible[0][col][1] || possible[0][col][4]) && !isbar(grid[1][col]));
							possible[1][col][6] |= ((possible[0][col][1] || possible[0][col][4]) && !isbar(grid[1][col]));
							possible[0][col][1] = a; 
							possible[0][col][3] = b;
							possible[1][col][1] = c;
							possible[1][col][6] = d;
//						}
				}
//				cout << possible[1][N - 1][6] << endl;
//				cout << possible[1][N - 1][2] << endl;


				if (possible[1][N - 1][6] || possible[1][N-1][2]) cout << "YES" << endl;
				else cout << "NO" << endl;
		}
}
