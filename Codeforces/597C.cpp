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
				vector<long long> tree;
		public:
				/* Initialize a Fenwick Tree with a user-provided capacity. */
				FenwickTree(int size) {
						assert(size >= 0);
						tree.resize(size + 1, 0);
						tree[0] = 0;
				}

				/* Linear-time construction. */
				FenwickTree(vector<long long>& A) {
						tree.resize(A.size() + 1, 0);

						for (int i = 1; i <= (int) A.size(); i++) {
								tree[i] = A[i - 1];
						}

						for (int i = 1; i <= (int) A.size(); i++) {
								int j = i + (i & -i);
								if (j < (int) tree.size()) {
										tree[j] = tree[j] + tree[i];
								}
						}
				}

				/* Update the element at position k by delta. */
				void update(int k, long long delta) {
						while (k < (int) tree.size()) {
								assert(k >= 0);
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
						for (int i = 1; i < (int) ft.tree.size(); i++) {
								output << ft.tree[i] << " ";
						}
						return output;
				}
};



ll N, K;
ll ways[100001][11];
ll A[100001];

int main() {
		// ways[i][j] = # ways to use first i elements to form a length j sequence ending at A[i].

		// ways[i][j] = sum over all k <= i ways[k][j - 1]  provided that A[k] < A[i].
		
		cin >> N >> K;
		K++;
		F0R(i, N) cin >> A[i + 1];

		vector<FenwickTree> fts(13, FenwickTree(N + 10));

		for (int i = 1; i <= N; i++) {
				fts[1].update(A[i], 1);
				for (int j = 2; j <= K; j++) {
						ll s = fts[j - 1].sum(A[i] - 1);
						fts[j].update(A[i], s);
						ways[i][j] += s;
				}
		}

		ll ans = fts[K].sum(N + 1);
		cout << ans << endl;
}
