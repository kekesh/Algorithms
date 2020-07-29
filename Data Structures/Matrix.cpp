#include <assert.h>
#include <bits/stdc++.h>
#include <thread>
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
						matrix.resize(_r, vector<long long>(_c));
				}

				Matrix(const vector<vector<long long>>& other) {
						rows = other.size(), cols = other[0].size();
						matrix = other;
						preprocessed = false;
				}

				Matrix (const vector<long long>& other) {
						rows = 1, cols = other.size();
						vector<vector<long long>> res;
						res.push_back(other);
						matrix = res;
						preprocessed = false;
				}

				static Matrix Identity(const int N) {
						vector<vector<long long>> mat(N, vector<long long>(N));
						for (int i = 0; i < N; i++) {
								mat[i][i] = 1;
						}
						return Matrix(mat);
				}

				/* Operators start here. */
				vector<long long>& operator[](int row) {
						return matrix[row];
				}

				/* Standard mathematical operations. */
				Matrix operator+(Matrix& other) {
						assert(rows == other.rows && cols == other.cols);
						vector<vector<long long>> sum(rows, vector<long long>(cols, 0));
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
						vector<vector<long long>> sum(rows, vector<long long>(cols, 0));
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
						vector<vector<long long>> product(rows, vector<long long>(other.cols, 0));
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
						vector<vector<long long>> product(rows, vector<long long>(other.cols, 0));
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < other.rows; j++) {
										for (int k = 0; k < other.cols; k++) {
												product[i][k] += 1ll * matrix[i][j] * other[j][k];
												if (product[i][k] >= 1ll * MOD * MOD) product[i][k] -= 1ll*MOD*MOD;
										}
								}
						}
						for (int i = 0; i < rows; i++) {
								for (int j = 0; j < cols; j++) {
										matrix[i][j] = product[i][j] % MOD;
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
		Matrix companion({{0, 1}, {1, 1}});
		vector<vector<long long>> base_case = {{0}, {1}};
		Matrix bc(base_case);
		long long T;
		cin >> T;
		while (T--) {
				long long n;
				cin >> n;
				Matrix res = (companion ^ n) * bc;
				cout << res[0][0] << endl;
		}
}
