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

const ll bucket_size = 300;

struct Query {
		int idx, l, r;
		Query(int i, int left, int right) {
				idx = i;
				l = left;
				r = right;
		}

		inline pair<int, int> toPair() const {
				return make_pair(l / bucket_size, ((l / bucket_size) & 1) ? -r : +r);
		}
};

inline bool cmp(const Query& lhs, const Query& rhs) {
		return lhs.toPair() < rhs.toPair();
}

int freq[1000005];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, T;
		cin >> N >> T;
		vl A(N);
		for (int i = 0; i < N; i++) cin >> A[i];

		vector<Query> queries;
		for (int i = 0; i < T; i++) {
				ll left, right;
				cin >> left >> right;
				queries.push_back(Query(i, left, right));
		}
		sort(queries.begin(), queries.end(), cmp);

		int start = 0;
		int end = -1;
		vector<long long> answers(T);
		long long cost = 0;
		
		/* Mo's Algorithm */
		for (int i = 0; i < T; i++) {
				Query q = queries[i];
				q.l--;
				q.r--;
				while (end > q.r) {
						cost -= 1ll * freq[A[end]] * freq[A[end]] * A[end];
						freq[A[end]]--;
						cost += 1ll * freq[A[end]] * freq[A[end]] * A[end];
						end--;
				}
				while (end < q.r) {
						end++;
						cost -= 1ll * freq[A[end]] * freq[A[end]] * A[end];
						freq[A[end]]++;
						cost += 1ll * freq[A[end]] * freq[A[end]] * A[end];

				}
				
				while (start > q.l) {
						start--;
						cost -= 1ll * freq[A[start]] * freq[A[start]] * A[start];
						freq[A[start]]++;
						cost += 1ll * freq[A[start]] * freq[A[start]] * A[start];
				}

				while (start < q.l) {
						cost -= 1ll * freq[A[start]] * freq[A[start]] * A[start];
						freq[A[start]]--;
						cost += 1ll * freq[A[start]] * freq[A[start]] * A[start];
						start++;
				}
				answers[q.idx] = cost;
		}

		for (int i = 0; i < T; i++) {
				cout << answers[i] << endl;
		}
}
