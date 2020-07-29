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
		public:
				long long N, s;
				vector<long long> a, decomposition;

				/* O(N) */
				SQRTDecomposition(const vector<long long>& b) {
						N = (int) b.size();
						s = ceil(sqrt(N)); // ceil() is necessary

						a.resize(N);
						decomposition.resize(s, -INF);
						int block_idx = -1;
						for (int i = 0; i < N; i++) {
								a[i] = b[i];
								if (i % s == 0) {
										block_idx++;
								}
						}
				}

				void update(long long v) {
						for (int block_idx = 0; block_idx < s; block_idx++) {
								decomposition[block_idx] = max(decomposition[block_idx], v);
						}
				}
};

int main() {
	ll N, Q;
	cin >> N;
	vl A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	SQRTDecomposition s(A);
	while (Q--) {
			ll q, p, x;
			cin >> q;
			if (q == 1) {
					cin >> p >> x;
					int blockidx = (p - 1)/s.s;
					for (int i = blockidx * s.s; i < min(s.N, blockidx * s.s + s.s); i++) {
							s.a[i] = max(s.a[i], s.decomposition[blockidx]);
					}
					s.decomposition[blockidx] = -INF;
					s.a[p - 1] = x;
			} else {
					cin >> x;
					s.update(x);
			}
	}

	for (int i = 0; i < N; i++) {
			int blockidx = i/s.s;
			s.a[i] = max(s.a[i], s.decomposition[blockidx]);
			cout << s.a[i] << " ";
	}
	cout << endl;
}
