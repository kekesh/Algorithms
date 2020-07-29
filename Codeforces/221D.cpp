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

ll bucket_size;

struct Query {
		int idx, l, r;
		Query(int i, int left, int right) {
				idx = i;
				l = left;
				r = right;
		}

		bool operator<(const Query& other) const {
				return make_pair(l/bucket_size, r) < make_pair(other.l/bucket_size, other.r);
		}
};


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		ll N, Q;
		cin >> N >> Q;
		vl A(N);
		for (int i = 0; i < N; i++) cin >> A[i];

		vector<Query> queries;
		for (int i = 0; i < Q; i++) {
				ll li, ri;
				cin >> li >> ri;
				queries.push_back(Query(i, li, ri));
		}
		bucket_size = ceil(sqrt(N));
		sort(queries.begin(), queries.end());

		int start = 0;
		int end = -1;
		unordered_map<int, int> freq;
		vector<int> answers(Q);

		int ans = 0;

		/* Mo's Algorithm. */
		for (int i = 0; i < Q; i++) {
				Query q = queries[i];
				q.l--;
				q.r--;

				while (start > q.l) {
						start--;
						if (freq[A[start]] == A[start]) {
								ans--;
						}
						freq[A[start]]++;
						if (A[start] == freq[A[start]]) {
								ans++;
						}
				}

				while (end < q.r) {
						end++;
						if (A[end] == freq[A[end]]) {
								ans--;
						}
						freq[A[end]]++;
						if (A[end] == freq[A[end]]) {
								ans++;
						}
				}

				while (start < q.l) {
						if (freq[A[start]] == A[start]) {
								ans--;
						}
						freq[A[start]]--;
						if (freq[A[start]] == A[start]) {
								ans++;
						}
						start++;
				}

				while (end > q.r) {
						if (freq[A[end]] == A[end]) {
								ans--;
						}
						freq[A[end]]--;
						if (freq[A[end]] == A[end]) {
								ans++;
						}
						end--;
				}
				answers[q.idx] = ans;
		}

		for (int i = 0; i < Q; i++) {
				cout << answers[i] << endl;
		}
}
