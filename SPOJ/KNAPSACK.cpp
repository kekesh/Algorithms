#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long S, N;
	cin >> S >> N;

	vector<long long> w(N), r(N);

	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> r[i];
	}

	vector<vector<long long>> dp(N + 1, vector<long long>(S + 1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= S; ++j) {
			long long take = (j - w[i - 1] >= 0 ? dp[i - 1][j - w[i - 1]] + r[i - 1] : -1e9);
			long long dont = dp[i - 1][j];
			dp[i][j] = max(take, dont);
		}
	}
	cout << dp[N][S] << endl;
}
