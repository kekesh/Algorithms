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
 
using ll = long long;
using vl = vector<ll>;

const ll INF = 1e18 + 1;

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
						decomposition.resize(s, INF);
						int block_idx = -1;
						for (int i = 0; i < N; i++) {
								a[i] = b[i];
								if (i % s == 0) {
										block_idx++;
								}
								decomposition[block_idx] = min(decomposition[block_idx], a[i]);
						}
				}

				long long query(int l, int r) {
						long long mini = INF;

						/* checking l != 0 is an optimization; we can jump sqrt(n) elements. */
						while (l < r && l % s != 0 && l != 0) {
								mini = min(mini, a[l++]);
						}

						/* while we can jump sqrt elements... */
						while (l + s <= r) {
								mini = min(decomposition[l/s], mini);
								l += s;
						}

						/* last block. */
						while (l <= r) {
								mini = min(a[l++], mini);
						}
						return mini;
				}
};

int main() {
	ll N;
	cin >> N;
	vl A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	ll Q;
	cin >> Q;
	SQRTDecomposition s(A);
	while (Q--) {
			ll L, R;
			cin >> L >> R;
			cout << s.query(L, R) << endl;
	}
}
