#include <iostream>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> dp(2050, 1e9);
	dp[1] = 0;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i + i / j] = min(dp[i + i / j], 1 + dp[i]);
		}
	}

	long long t;
	scanf("%lld", &t);
	while (t--) {
		long long n, k;
		scanf("%lld %lld", &n, &k);

		vector<long long> b(n + 1), c(n + 1);
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			b[i] = dp[x];
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &c[i]);
		}

		k = min(12 * n, k);
		vector<vector<long long>> profit(n + 1, vector<long long>(k + 1));

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				long long v1 = (j - b[i] >= 0) ? (profit[i - 1][j - b[i]] + c[i]) : -1e9;
				long long v2 = profit[i - 1][j];
				profit[i][j] = max(v1, v2);
			}
		}
		printf("%lld\n", profit[n][k]);
	}
}
