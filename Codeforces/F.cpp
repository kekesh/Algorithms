#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

bool can(string& s, string& p, vector<int>& sigma, int steps) {
	const int n = s.size();
	vector<bool> bad(n);
	for (int i = 0; i < steps; ++i) {
		bad[sigma[i] - 1] = true; 
	}
	string after_removal;
	for (int i = 0; i < n; ++i) {
		if (!bad[i]) after_removal += s[i];
	}

	const int m = after_removal.size();
	int j = 0;

	for (int i = 0; i < m; ++i) {
		if (j < p.size() && after_removal[i] == p[j]) {
			j++;
		}
	}
	return j == p.size();
}


int main() {
	string t, p;
	cin >> t >> p;
	const int n = t.size();
	vector<int> a(n);

	for (int i = 0; i < n; ++i) cin >> a[i];

	long long lo = 0, hi = n, ans = 0;

	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (can(t, p, a, mid)) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}
