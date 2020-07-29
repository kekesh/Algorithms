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
 
/* An implementation of a Fenwick Tree (Binary Indexed Tree) by Ekesh Kumar. */
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

int main() {
		vector<long long> A = {1, 2, 3};
		FenwickTree ft(A);
		cout << ft.sum(3) << endl;
		cout << ft.sum(2) << endl;
		cout << ft.rangeQuery(1, 3) << endl;
		cout << ft.rangeQuery(1, 2) << endl;
		cout << ft.rangeQuery(2, 3) << endl;
		cout << ft.rangeQuery(1, 1) << endl;
		cout << "Printing FT" << endl;
		cout << ft << endl;
}
