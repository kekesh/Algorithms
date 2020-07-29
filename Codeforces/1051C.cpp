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

ll N, A[101];


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		unordered_map<int, int> freq;
		F0R(i, N) cin >> A[i], freq[A[i]]++;
		ll ones = 0;
		ll splitters = 0;
		F0R(i, N) {
				if (freq[A[i]] == 1) {
						ones++;
				} else if (freq[A[i]] >= 3) {
						splitters++;
				}
		}

		if (ones & 1 && splitters == 0) {
				cout << "NO" << endl;
				return 0;
		}
		cout << "YES" << endl;

		if (ones & 1) {
				// we'll give a one more.
				bool split = false;
				bool a = true;

				F0R(i, N) {
						if (freq[A[i]] == 1) {
								if (a) cout << "A";
								else cout << "B";
								a = !a;
						} else if (freq[A[i]] > 2 && !split) {
								cout << "B";
								split = true;
						} else {
								cout << "A";
						}
				}
				cout << endl;
		} else {
				bool a = true;
				// split the ones perfectly.
				F0R(i, N) {
						if (freq[A[i]] == 1) {
								if (a) cout << "A";
								else cout << "B";
								a = !a;
						} else {
								cout << "A";
						}
				}
				cout << endl;
		}
}
