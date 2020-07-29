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

bool chosen[4];
int cnt;
/*void search(vector<int>& arr, vector<int>& original) {
		if ((int) arr.size() == 4) {
				cnt++;
				for (int i = 0; i < 4; i++) cout << arr[i] << " ";
				ll s = 0;
				s += arr[0] * 
		} else {
				for (int i = 0; i < 4; i++) {
						if (chosen[i]) continue;
						chosen[i] = true;
						arr.push_back(original[i]);
						search(arr, original);	
						chosen[i] = false;
						arr.pop_back();
				}
		}
}
*/

bool taken[4];
bool recurse[4];
vector<int> ans;
void search(const vector<int>& coeff, const vector<int>& arr, vector<int>& taken, ll need) {
		if (taken.size() == 4) {
				// process
				ll sum = 0;
/*				for (int i = 0 ; i < 4; i++ ){
						cout << taken[i] << " ";
				}
				cout << endl;
				*/


				for (int i = 0; i < 4; i++) {
						sum += coeff[i] * taken[i];
				}
				if (sum % 7 == need) {
//						cout << "found something. " << endl;
						ans = taken;
						return;
				}
		} else {
				for (int i = 0; i < 4; i++) {
						if (recurse[i]) continue;
						recurse[i] = true;
						taken.push_back(arr[i]);
						search(coeff, arr, taken, need);
						recurse[i] = false;
						taken.pop_back();
				}
		}
}


int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		string s;
		cin >> s;
		ll sum = 0;

		vector<int> coefficients = {1, 3, 2, 6, 4, 5}; // powers of 3 mod 7
		int j = 0;
		string rest;
		for (int i = (int) s.size() - 1; i >= 0; i--) {
				if (s[i] == '1' && !taken[0]) {
						taken[0] = true;
						continue;
				} else if (s[i] == '6' && !taken[1]) {
						taken[1] = true;
						continue;
				} else if (s[i] == '8' && !taken[2]) {
						taken[2] = true;
						continue;
				} else if (s[i] == '9' && !taken[3]) {
						taken[3] = true;
						continue;
				}
				rest += s[i];
				sum = (sum + coefficients[j] * (s[i] - '0')) % 7;
//				cout << "sum += " << coefficients[j] << " * " << s[i] << endl;
				j = (j + 1) % 6;
		}


		vector<int> have(4);
		vector<int> original = {1, 6, 8, 9};
		vector<int> empty;
		ll need = (7 - sum) % 7;
		for (int i = 0; i < 4; i++, j = (j + 1) % 6) {
				have[i] = coefficients[j];
		}
//		cout << "searching" << endl;
		search(have, original, empty, need);
//		cout << "searched!" << endl;
		reverse(ans.begin(), ans.end());

		for (int i = 0; i < 4; i++) {
				cout << ans[i];
		}
		reverse(rest.begin(), rest.end());

		cout << rest << endl;
}
