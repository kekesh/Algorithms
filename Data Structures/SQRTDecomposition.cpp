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
 
/* Consider using a constant value for bucket size. */
class SQRTDecomposition {
		private:
				long long N, s;
				vector<long long> a, decomposition;
		public:
				/* O(N) */
				SQRTDecomposition(const vector<long long>& b) {
						N = (int) b.size();
						s = ceil(sqrt(N));

						a.resize(N);
						decomposition.resize(s);
						int block_idx = -1;
						for (int i = 0; i < N; i++) {
								a[i] = b[i];
								if (i % s == 0) {
										block_idx++;
								}
								decomposition[block_idx] += a[i];
						}
				}

				/* Set a[idx] to val. O(1). */
				void update(int idx, int val) {
						decomposition[idx / s] += val - a[idx];
						a[idx] = val;
				}

				long long query(int l, int r) {
						long long sum = 0;

						/* checking l != 0 is an optimization; we can jump sqrt(n) elements. */
						while (l < r && l % s != 0 && l != 0) {
								sum += a[l++];
						}

						/* while we can jump sqrt elements... */
						while (l + s <= r) {
								sum += decomposition[l/s];
								l += s;
						}

						/* last block. */
						while (l <= r) {
								sum += a[l++];
						}
						return sum;
				}
};

int main() {
		vector<long long> input = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
		SQRTDecomposition s(input);

		cout << "query(3, 8): " << s.query(3, 8) << endl; // 26.
		cout << "query(1, 6): " << s.query(1, 6) << endl; // 21.
		s.update(8, 0);
		cout << "query(8, 8): " << s.query(8, 8) << endl; // 0.
}
