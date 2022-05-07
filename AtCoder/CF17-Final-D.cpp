#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	const long long INF = 1E18;
	long long n;
	cin >> n;
	vector<vector<long long>> a(n, vector<long long>(2));

	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	sort(a.begin(), a.end(), [](const vector<long long>& u, const vector<long long>& v) {
			return u[0] + u[1] < v[0] + v[1];
	});

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));

	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (dp[i - 1][j - 1] <= a[i - 1][0]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i - 1][1]);
			}
			if (dp[i][j] != INF) {
				answer = max(answer, j);
			}
		}
	}
	cout << answer << endl;
}
