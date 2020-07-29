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

const int MOD = 1e9 + 7;
 
class Matrix {
		private:
				vector<vector<long long>> matrix;
				long long rows, cols;
		public:
				Matrix() {

				}

				Matrix(long long _r, long long _c) : rows(_r), cols(_c) {
						matrix.resize(_r, vector<long long>(_c));
				}

				Matrix(const vector<vector<long long>>& other) {
						rows = other.size(), cols = other[0].size();
						matrix = other;
				}

				static Matrix Identity(const int N) {
						vector<vector<long long>> mat(N, vector<long long>(N));
						for (int i = 0; i < N; i++) {
								mat[i][i] = 1;
						}
						return Matrix(mat);
				}

				/* Operators start here. */
				vector<long long> operator[](int row) const {
						return matrix[row];
				}

				/* Standard mathematical operations. */
				Matrix operator+(const Matrix& other) const {
						//assert(rows == other.rows && cols == other.cols);
						vector<vector<long long>> sum(rows, vector<long long>(cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										sum[i][j] = matrix[i][j] + other[i][j];
								}
						}
						return Matrix(sum);
				}

				Matrix& operator+=(const Matrix& other) {
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										matrix[i][j] += other[i][j];
								}
						}
						return *this;
				}
				Matrix operator-(const Matrix& other) const {
						assert(rows == other.rows && cols == other.cols);
						vector<vector<long long>> sum(rows, vector<long long>(cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										sum[i][j] = matrix[i][j] - other[i][j];
								}
						}
						return *this;
				}
				Matrix& operator-=(const Matrix& other) {
						assert(rows == other.rows && cols == other.cols);
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										matrix[i][j] -= other[i][j];
								}
						}
						return *this;
				}
				Matrix operator*(const Matrix& other) const {
						//assert(cols == other.rows);
						vector<vector<long long>> product(rows, vector<long long>(other.cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < other.cols; j++) {
										for (int k = 0; k < cols; k++) {
												product[i][j] = (product[i][j] + 1ll * matrix[i][k] * other[k][j]) % MOD;
										}
								}
						}
						return Matrix(product);
				}
				Matrix& operator*=(const Matrix& other) {
						//assert(cols == other.rows);
						vector<vector<long long>> product(rows, vector<long long>(other.cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < other.cols; j++) {
										for (int k = 0; k < cols; k++) {
												product[i][j] = (product[i][j] + matrix[i][k] * other[k][j]) % MOD;
										}
								}
						}
						matrix = product;
						return *this;
				}

				friend ostream &operator<<(ostream &output, const Matrix& mat) {
						for (int i = 0; i < mat.rows; i++) {
								for (int j = 0; j < mat.cols; j++) {
										output << mat[i][j] << " ";
								}
								if (i != mat.rows - 1) output << endl;
						}
						return output;
				}
};

Matrix powers[55];

Matrix matPow(const Matrix& mat, int power) {
	Matrix result = Matrix::Identity(26);
	int ptr = 0;
	while (power > 0) {
			if (power & 1) {
					result *= powers[ptr];
			}
			ptr++;
			power /= 2;
	}
	return result;
}

void dp(const Matrix& mat) {
	powers[0] = mat;
	for (int i = 1; i < 55; i++) {
		powers[i] = powers[i - 1] * powers[i - 1];
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<long long>> m(26, vector<long long>(26, 0));
	for (int i = 0; i < 26; i++) {
		for (int j = 0 ;j < 26; j++) {
			cin >> m[i][j];
		}
	}
	Matrix mat(m);
	dp(mat);
	int T;
	cin >> T;
	while (T--) {

		char c;
		int L;
		cin >> c >> L;
		L--;
		Matrix res = matPow(mat, L);
		long long sum = 0;
		for (char src = 'a'; src <= 'z'; src++) {
			sum = (sum + res[src - 'a'][c - 'a']) % MOD;
		}

		cout << sum << endl;

	}

}
