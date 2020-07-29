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

/* This implementation assumes one-based indexing. */
class FenwickTree {
		private:
				int size;
				vector<long long> tree;
		public:
				/* Initialize a Fenwick Tree with a user-provided capacity. */
				FenwickTree(int size) {
						assert(size >= 0);
						this->size = size;
						tree.resize(size + 1, 0);
						tree[0] = 0;
				}

				/* Linear-time construction. */
				FenwickTree(vector<long long>& A) {
						tree.resize(A.size() + 1, 0);
						this->size = A.size() + 1;

						for (int i = 1; i <= (int) A.size(); i++) {
								tree[i] = A[i - 1];
						}

						for (int i = 1; i <= (int) A.size(); i++) {
								int j = i + (i & -i);
								if (j < this->size) {
										tree[j] = tree[j] + tree[i];
								}
						}
				}

				/* Update the element at position k by delta. */
				void update(int k, long long delta) {
						while (k < size) {
								tree[k] += delta;
								k += (k & -k);
						}
				}

				/* Compute SUM[1, k] */
				long long sum(int k) {
						long long s = 0;
						while (k > 0) {
								s += tree[k];
								k -= (k & -k);
						}
						return s;
				}

				/* Compute SUM[j, k] */
				long long rangeQuery(int j, int k) {
						return sum(k) - sum(j - 1);
				}

				friend ostream &operator<<(ostream &output, const FenwickTree &ft) {
						for (int i = 1; i < ft.size; i++) {
								output << ft.tree[i] << " ";
						}
						return output;
				}
};


ll A[100005];
ll ways[100005];
ll ways2[100005];
int main() {
		ll N;
		cin >> N;
		FenwickTree ft1(100005);
		FenwickTree ft2(100005);
		ll ans = 0;
		F0R(i, N) {
				cin >> A[i];
				ft1.update(A[i], 1);
				ways[i] += ft1.rangeQuery(A[i] + 1, 100000);
		}
		for (int i = N - 1; i >= 0; i--) {
				ft2.update(A[i], 1);
				ways2[i] += ft2.sum(A[i] - 1);
				ans += ways[i] * ways2[i];
		}

		cout << ans << endl;
}
