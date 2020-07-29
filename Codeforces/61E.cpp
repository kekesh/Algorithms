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

long long A[1000000];
long long ways[1000000];
int asdf;
unordered_map<int, int> c;

int main() {
		long long N;
		cin >> N;
		set<int> s;
		for (int i = 0; i < N; i++) {
				cin >> A[i];
				s.insert(A[i]);
		}
		asdf = 1;
		for (auto v : s) {
				c[v] = asdf++;
		}
		asdf--;
		FenwickTree ft1(asdf + 5);
		FenwickTree ft2(asdf + 5);

		for(int i = 0; i < N; i++) {
				ft1.update(c[A[i]], 1);
				// # elements before it that are greater than it.
				ways[i] += ft1.rangeQuery(c[A[i]] + 1, asdf);
		}

		long long ans = 0;
		for (int i = N - 1; i >= 0; i--) {
				ft2.update(c[A[i]], 1);
				ans += ways[i] * ft2.sum(c[A[i]] - 1);
		}

		cout << ans << endl;

}
