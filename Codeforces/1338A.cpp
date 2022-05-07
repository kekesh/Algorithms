#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		long long maxi = -1e10;
		long long maxi_diff = -1e10;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			maxi = max(maxi, a[i]);
			if (a[i] < maxi) {
				maxi_diff = max(maxi - a[i], maxi_diff);
			}
		}

		if (maxi_diff <= 0) {
			cout << 0 << endl;
			continue;
		}

		long long steps = 1;
		while (maxi_diff - (2 * (1LL << (steps - 1)) - 1) > 0) {
			steps++;
		}
		cout << steps << endl;
	}
}
