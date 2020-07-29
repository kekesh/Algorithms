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
typedef vector<int> vi;
typedef vector<ll> vl;
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
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, K;
		cin >> N >> K;
		vector<string> A(N);
		map<string, int> freq;
		F0R(i, N) cin >> A[i], freq[A[i]]++;


		long long ans = 0;
		for (int i = 0; i < N; i++) {
				string s1 = A[i];
				for (int j = i + 1; j < N; j++) {
						string s2 = A[j];

						string s3 = "";
						for (int k = 0; k < (int) s1.size(); k++) {
								if (s1[k] == s2[k]) s3 += s1[k];
								else {
										if (s1[k] != 'S' && s2[k] != 'S') s3 += 'S';
										else if (s1[k] != 'E' && s2[k] != 'E') s3 += 'E';
										else s3 += 'T';
								}
						}
						ans += freq[s3];
				}
		}
		cout << ans/3 << endl;
}
