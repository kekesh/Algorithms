#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1e18;

bool check(vector<long long>& a, long long mid, long long k) {
	// can we form mid groups of size k each?
	
	const int n = a.size();
	long long depth_left = k, group_sz = mid;
	for (const auto u : a) {
		long long v = min(u, mid);
		if (v < group_sz) {
			group_sz -= v;
		} else {
			// v >= group_sz
			v -= group_sz;
			depth_left--;
			if (!depth_left) break;
			group_sz = mid - v;
		}
	}
	return depth_left == 0;
}

int main() {
	long long k, n;
	cin >> k >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	long long lo = 0, hi = 1e18, ans = 0;
	assert(!check(a, hi + 1, k));
	while (lo <= hi) {
		long long mid = lo + (hi - lo) / 2;
		if (check(a, mid, k)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}
