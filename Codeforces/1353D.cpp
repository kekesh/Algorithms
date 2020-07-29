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
typedef vector<ll> vl;

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

struct Interval {
		ll start, end;

		Interval(ll st, ll en) : start(st), end(en) { 
		
		}
};

bool cmp(const Interval& lhs, const Interval& rhs) {
		ll l1 = lhs.end - lhs.start + 1;
		ll l2 = rhs.end - rhs.start + 1;
		if (l1 == l2) {
				return lhs.start > rhs.start;
		}
		return l1 < l2;
}

ll N, M, T, K;


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> T;
		while (T--) {
				cin >> N;

				priority_queue<Interval, vector<Interval>, function<bool(Interval, Interval)>> pq(cmp);
				pq.push(Interval(1, N));
				vl A(N + 1, 0);
				ll cnt = 1;
				while (!pq.empty()) {
						Interval next = pq.top();
						pq.pop();
						ll mid = (next.start + next.end)/2;
						A[mid] = cnt++;
						if (next.start <= mid - 1 && mid - 1 > 0) {
								Interval left = Interval(next.start, mid - 1);
								pq.push(left);
						}
						if (next.end >= mid + 1) {
								Interval right = Interval(mid + 1, next.end);
								pq.push(right);
						}
				}

				for (int i = 1; i <= N; i++) cout << A[i] << " ";
				cout << endl;

		}
}
