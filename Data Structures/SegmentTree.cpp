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
 
const long long INF = 1e18;

class Checker {
		private:
				vector<long long> a;
		public:
				Checker(int n) {
						a.resize(n + 1);
				}

				Checker(const vector<long long>& b) {
						int n = b.size();
						a.resize(n + 1);
						for (int i = 1; i < n; i++) {
								a[i] = b[i - 1];
						}
				}

				void increment(int i, int j, int delta) {
						for (int k = i; k <= j; k++) a[k] += delta;
				}

				long long rmq(int i, int j) {
						long long best = 1e18;
						for (int k = i + 1; k <= j; k++) best = min(best, a[k]);
						return best;
				}
};

class SegmentTree {
		private:
				int n;
				vector<long long> lo, hi, mini, delta; /* Parallel arrays; stores range. */
		public:
				SegmentTree(int n) {
//						this->n = n;
						lo.resize(4*n + 1);
						hi.resize(4*n + 1);
						mini.resize(4*n + 1);
						delta.resize(4*n + 1); // lazy propagation.
						build(1, 0, n - 1);
				}

				void build(int idx, int a, int b) {
						lo[idx] = a, hi[idx] = b;

						if (a == b) {
								// leaf node
								return;
						}

						int m = a + (b - a)/2;
						build(2*idx, a, m);
						build(2*idx + 1, m + 1, b);
				}

				void increment(int a, int b, int val) {
						increment(1, a, b, val);
				}

				void increment(int idx, int a, int b, int val) {
						if (b < lo[idx] || a > hi[idx]) {
								return;
						}
						if (a <= lo[idx] && b >= hi[idx]) {
								delta[idx] += val;
								return;
						}

						// partial coverage
						prop(idx);
						increment(2*idx, a, b, val);
						increment(2*idx + 1, a, b, val);
						update(idx);
				}

				/* Lazy propagation. */
				void prop(int idx) {
						delta[2*idx] += delta[idx];
						delta[2*idx + 1] += delta[idx];
						delta[idx] = 0;
				}

				void update(int idx) {
						mini[idx] = min(mini[2*idx] + delta[2*idx], mini[2*idx + 1] + delta[2*idx + 1]);
				}

				long long rmq(int a, int b){
						return rmq(1, a, b);
				}

				long long rmq(int idx, int a, int b) {
						if (b < lo[idx] || hi[idx] < a) {
								return INF;
						}

						if (a <= lo[idx] && hi[idx] <= b) {
								return mini[idx] + delta[idx];
						}

						prop(idx);
						long long miniLeft = rmq(2*idx, a, b);
						long long miniRight = rmq(2*idx + 1, a, b);
						update(idx);

						return min(miniLeft, miniRight);
				}

				
};

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int N;

		cin >> N;
		SegmentTree s(N);
		for (int i = 0; i < N; i++) {
				int x;
				cin >> x;
				s.increment(i, i, x);
		}
		long long Q;
		cin >> Q;
		string dummy;
		getline(cin, dummy);

		while (Q--) {
				string query;
				getline(cin, query);
				istringstream iss(query);
				int q[3];
				int j = 0;
				while (iss >> q[j]) {
						j++;
				}

				if (j == 2) {
						// rmq
						if (q[1] < q[0]) {
								// circular
								cout << min(s.rmq(q[0], N - 1), s.rmq(0, q[1])) << endl;
						} else {
								cout << s.rmq(q[0], q[1]) << endl;
						}
				} else {
						// update
						if (q[1] < q[0]) {
								// circular
								s.increment(q[0], N - 1, q[2]);
								s.increment(0, q[1], q[2]);
						} else {
								s.increment(q[0], q[1], q[2]);
						}
				}
		}

		return 0;
}
