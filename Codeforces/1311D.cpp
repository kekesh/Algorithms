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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		while (t--) {
				ll a, b, c;
				cin >> a >> b >> c;
				
				ll lo = 0, hi = 30005, ans = 1e18;

				ll A, B, C;
				A = B = C = -1;
				while (lo <= hi) {
						ll mid = (lo + hi)/2;

						int LB = MAX(1, a - mid);
						bool works = false;
						ll constructA, constructB, constructC;
						constructA = constructB = constructC = -1;
						for (int A = LB; A <= a + mid; A++) {
								for (int B = A; B <= b + mid; B += A) {
										if (abs(a - A) + abs(b - B) > mid) {
												continue;
										}
										int left = mid - abs(a - A) - abs(b - B);
										if (c % B <= left && c - left >= 0) {
												works = true;
												constructA = A, constructB = B, constructC = c - left;
//												cout << "A = " << A << " and B = " << B << " and C = " << c - left << endl;
												break;
										} else if (B - (c % B) <= left) {
												works = true;
												constructA = A, constructB = B, constructC = c + B - (c % B);
//												cout << "A = " << A << " and B = " << B << " and C = " << c + B - (c % B) << endl;
												break;
										}
								}
								if (works) break;
						}

						if (works) {
								ll ops = abs(a - constructA) + abs(b - constructB) + abs(c - constructC);
								ans = ops;
								hi = ops - 1;
								A = constructA, B = constructB, C = constructC;
						} else {
								lo = mid + 1;
						}
				}
				cout << ans << endl;
				cout << A << " " << B << " " << C << endl;
		}
}
