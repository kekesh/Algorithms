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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ld> vld;
typedef vector<pair<ll, ll>> vpl;

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
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

int freq[10];
int cnt[10];
int delta[10];
long long fact[20];
ll C[30][30];
ll ans;


void process(int digits) {
		int res[10];
//		cout << "Processing!" << endl;
		for (int i = 0; i <= 9; ++i) {
				res[i] = cnt[i] + delta[i];
//				cout << res[i] << " ";
		}
//		cout << endl;

		ll s = 0;
		for (int i = 1; i <= 9; ++i) {
				s += res[i];
		}
		ll tmp = fact[s];
		for (int i = 1; i <= 9; ++i) {
				assert(fact[res[i]] != 0);
				tmp /= fact[res[i]];
		}
		// handle zeros.
		// stars and bars.

		digits -= res[0];

//		cout << "Adding " << tmp << " *  " << "(" << digits + res[0] - 1 << " choose " << digits - 1 << ")" << endl;
//		cout << digits + res[0] - 1 << " choose " << digits - 1 << " = " << C[digits + res[0] - 1][digits - 1] << endl;

		ans += tmp * C[digits + res[0] - 1][digits - 1];
//		cout << "Ans is now " << ans << endl;
}

void weak_compositions(int digits, int n, int idx = 0) {
		if (idx == 10) {
				if (n == 0) {
						process(digits);
				}
				return;
		}
		int bd = freq[idx];
		for (int i = 0; i <= bd; ++i) {
				int left = n - i;
				if (left >= 0) {
						delta[idx] = i;
						weak_compositions(digits, left, idx + 1);
				}
		}
}


int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);


		C[0][0] = 1;
		for (int i = 1; i <= 25; ++i) {
				for (int j = 0; j <= i; ++j) {
						if (j == 0) {
								C[i][j] = 1;
								continue;
						} else if (j == 1) {
								C[i][j] = i;
								continue;
						}

						C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
				}
		}
		
//		cout << "C(10, 2) = " << C[10][2] << endl;

		string s;
		cin >> s;

		int distinct = 0;
		for (int i = 0; i < (int) s.size(); ++i) {
				freq[s[i] - '0']++;
				distinct += (freq[s[i] - '0'] == 1);
		}

		for (int i = 0; i <= 9; ++i) {
				cnt[i] = freq[i] > 0;
				if (freq[i] > 0) freq[i]--;
		}

		ll bd = s.size() - distinct;

		fact[0] = fact[1] = 1;
		for (int k = 2; k <= 19; ++k) fact[k] = 1ll * fact[k - 1] * k;


		for (int i = 0; i <= bd; ++i) {
//				cout << "Another call" << endl;
				weak_compositions(i + distinct, i);
		}

		cout << ans << endl;
//		cout << "FINAL ANSWER: " << ans << endl;
		/*
		for (int i = 0; i <= 9; ++i) {
				cnt[i] = freq[i] > 0;
				cout << cnt[i] << " ";
		}
		cout << endl;

		int left = s.size() - distinct;
		// generate weak compositions of 0, 1, 2, ... left.
		assert(left <= 18);
		*/

}
