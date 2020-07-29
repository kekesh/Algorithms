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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ld> vld;
typedef vector<pair<ll, ll>> vpl;

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
 
const int MOD = 998244353;  /* 1000000007 */;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ll n, m, k;

class Matrix {
		private:
				vector<vector<long double>> matrix;
				long long rows, cols;

				vector<Matrix> powers;
				bool preprocessed;

				void preprocess() {
						powers.resize(60);
						powers[0] = matrix;
						for (int i = 1; i < 60; i++) {
								powers[i] = powers[i - 1] * powers[i - 1];
						}
						preprocessed = true;
				}

		public:

				Matrix () {
						preprocessed = false;
						rows = cols = 0;
				}

				Matrix(long long _r, long long _c) : rows(_r), cols(_c), preprocessed(false) {
						matrix.resize(_r, vector<ld>(_c));
				}

				Matrix(const vector<vector<ld>>& other) {
						rows = other.size(), cols = other[0].size();
						matrix = other;
						preprocessed = false;
				}

				Matrix (const vector<ld>& other) {
						rows = 1, cols = other.size();
						vector<vector<ld>> res;
						res.push_back(other);
						matrix = res;
						preprocessed = false;
				}

				static Matrix Identity(const int N) {
						vector<vector<ld>> mat(N, vector<ld>(N));
						for (int i = 0; i < N; i++) {
								mat[i][i] = 1;
						}
						return Matrix(mat);
				}

				/* Operators start here. */
				vector<ld>& operator[](int row) {
						return matrix[row];
				}

				/* Standard mathematical operations. */
				Matrix operator+(Matrix& other) {
						assert(rows == other.rows && cols == other.cols);
						vector<vector<ld>> sum(rows, vector<ld>(cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										sum[i][j] = matrix[i][j] + other[i][j];
								}
						}
						return Matrix(sum);
				}

				Matrix& operator+=(Matrix& other) {
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										matrix[i][j] += other[i][j];
								}
						}
						return *this;
				}

				Matrix operator-(Matrix& other) {
						assert(rows == other.rows && cols == other.cols);
						vector<vector<ld>> sum(rows, vector<ld>(cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										sum[i][j] = matrix[i][j] - other[i][j];
								}
						}
						return *this;
				}

				Matrix& operator-=(Matrix& other) {
						assert(rows == other.rows && cols == other.cols);
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										matrix[i][j] -= other[i][j];
								}
						}
						return *this;
				}

				Matrix operator*(Matrix& other) {
						assert(cols == other.rows);
						vector<vector<ld>> product(rows, vector<ld>(other.cols, 0));
						/* https://tavianator.com/a-quick-trick-for-faster-naive-matrix-multiplication/ */
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < other.rows; j++) {
										for (int k = 0; k < other.cols; k++) {
												product[i][k] += 1ll * matrix[i][j] * other[j][k];
												if (product[i][k] >= 1ll * MOD * MOD) product[i][k] -= 1ll*MOD*MOD;
										}
								}
						}
						return Matrix(product);
				}

				Matrix& operator*=(Matrix& other) {
						assert(cols == other.rows);
						vector<vector<ld>> product(rows, vector<ld>(other.cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < other.rows; j++) {
										for (int k = 0; k < other.cols; k++) {
												product[i][k] += 1ll * matrix[i][j] * other[j][k];
										}
								}
						}
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										matrix[i][j] = product[i][j];
								}
						}
						return *this;
				}

				Matrix operator^(long long power) {
						Matrix result = Identity(this->rows);
						Matrix A(this->matrix);
						while (power > 0) {
								if (power & 1) {
										result *= A;
								}
								A *= A;
								power >>= 1;
						}
						return result;
				}

				friend ostream &operator<<(ostream &output, Matrix& mat) {
						for (int i = 0; i < mat.rows; i++) {
								for (int j = 0; j < mat.cols; j++) {
										output << mat[i][j] << " ";
								}
								if (i != mat.rows - 1) output << endl;
						}
						return output;
				}
};

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n, t;
		ld p;
		cin >> n >> p >> t;
		vector<vector<long double>> dp(n + 1, vector<long double>(t + 1));
		cout << fixed << setprecision(15);
/*		if (t <= n) {
				cout << p * t << endl;
				return 0;
		}
*/
		// dp[i][j] = prob of i people getting in it after j seconds.
		dp[0][0] = 1;
		for (int i = 0; i <= n; ++i) {
				for (int j = 1; j <= t; ++j) {
						if (i - 1 >= 0) dp[i][j] += dp[i - 1][j - 1] * p;
						if (i != n) dp[i][j] += dp[i][j - 1] * (1 - p);
						else dp[i][j] += dp[i][j - 1];

				}
		}

		ld ev = 0;
		for (int i = 1; i <= n; ++i) {
				ev += i * dp[i][t];
		}
		cout << ev << endl;


		// let p[i][j] = probability of having i people in the elevator after j tries.
		// p[0][0] = 1
		// p[i][j] = p[i - 1][j - 1] * p(success) + p[i][j - 1] * p(failure)

		// .
}

