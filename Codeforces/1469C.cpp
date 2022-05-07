#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<long long>;

int main() {
	/* For a permutation P of {1, 2, ..., n}, call an index 1 <= i <= n a "fixed point" if P[i] = i.
	 * 
	 * Let dp[i][j] be the number of permutations of {1, ..., i} with exactly j fixed points. 
	 * Under this notation, we wish to compute \sum_{i = n - k}^{n} dp[n][i].
	 * 
	 * We compute the values of dp[][] using dynamic programming.
	 * 
	 * There are two cases to consider: 
	 *
	 * dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1 - j) + dp[i - 1][j + 1] * (j + 1).
	 *
	 * Base Case: 
	 * dp[i][0] (i.e., "derangements")
	 * dp[i][0] = dp[i - 1][0] * (i - 1) + dp[i - 2][0] * (i - 1)
	 */ 

	ll n, k;
	cin >> n >> k;
	vector<vl> dp(n + 1, vl(n + 1));
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[1][1] = 1;

	ll s = 0;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = (i - 1) * dp[i - 2][0] + (i - 1) * dp[i - 1][0];
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1 - j);
			if (j + 1 <= i - 1) dp[i][j] += dp[i - 1][j + 1] * (j + 1);
		}
	}

	for (int i = n - k; i <= n; ++i) {
		s += dp[n][i];
	}
	cout << s << endl;
}
