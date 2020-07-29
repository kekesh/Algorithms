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

typedef long long ll;

/* This implementation assumes one-based indexing. */
class FenwickTree2D {
		private:
				vector<vector<ll>> tree;
		public:
				/* Initialize a Fenwick Tree with a user-provided capacity. */
				FenwickTree2D(int R, int C) {
						assert(R >= 0 && C >= 0);
						tree.assign(R + 1, vector<ll>(C + 1, 0));
				}

				/* Quadratic-time construction. Provided matrix can't be empty. */
				FenwickTree2D(vector<vector<ll>>& A) {
						tree.assign(A.size() + 1, vector<ll>(A[0].size() + 1, 0));

						for (int i = 0; i < (int) A.size(); i++) {
								for (int j = 0; j < (int) A[0].size(); j++) {
										update(i + 1, j + 1, A[i][j]);
								}
						}
				}

				/* Update the element at position k by delta. */
				void update(int r, int c, long long delta) {
						for (int r_ = r; r_ < (int) tree.size(); r_ = r_ + (r_ & -r_)) {
								for (int c_ = c; c_ < (int) tree[0].size(); c_ = c_ + (c_ & -c_)) {
										tree[r_][c_] += delta;
								}
						}
				}

				/* Compute sum from (0, 0) to (r, c) inclusive. */
				long long sum(int r, int c) {
						long long s = 0;
						for (int r_ = r; r_ > 0; r_ = r_ - (r_ & (-r_))) {
								for (int c_ = c; c_ > 0; c_ = c_ - (c_ & (-c_))) {
										s += tree[r_][c_];
								}
						}
						return s;
				}

				/* Compute SUM[j, k] */
				long long rangeQuery(int r1, int c1, int r2, int c2) {
					return (sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1));
				}
};

int main() {

}
