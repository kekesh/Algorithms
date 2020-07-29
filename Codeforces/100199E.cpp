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
typedef vector<ld> vld;
typedef vector<pair<ll, ll>> vpl;

int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

typedef int64_t ll;
typedef long long ll;
typedef pair<ll,ll> lll;
typedef pair<ll,int> lli;
typedef pair<int,int> ii;

#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a) {
    while ((int) a.size() > 1 && a.back() == 0) a.pop_back();
}

void Print(BigInt a) {
    Set(a);
    printf("%d", ((int) a.size() == 0) ? 0 : a.back());
    FORD(i,a.size()-2,0) printf("%09d", a[i]); EL;
}



BigInt Integer(string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) {ans.pb(0); return ans;}
    while (s.size()%9 != 0) s = '0'+s;
    for (int i=0;i<s.size();i+=9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(char c[]) {
    string s = "";
    FOR(i,0,strlen(c)-1) s = s + c[i];
    return Integer(s);
}

BigInt Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x) {
    return Integer((ll) x);
}




void operator >> (istream &in, BigInt &a) {
    string s;
    getline(cin, s);
    a = Integer(s);
}

void operator << (ostream &out, BigInt a) {
    Print(a);
}




bool operator < (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FORD(i,a.size()-1,0)
        if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}

bool operator > (BigInt a, BigInt b) {
    return (b < a);
}

bool operator == (BigInt a, BigInt b) {
    return (!(a < b) && !(b < a));
}

bool operator <= (BigInt a, BigInt b) {
    return (a < b || a == b);
}

bool operator >= (BigInt a, BigInt b) {
    return (b < a || b == a);
}

bool operator < (BigInt a, int b) {
    return (a < Integer(b));
}

bool operator > (BigInt a, int b) {
    return (a > Integer(b));
}

bool operator == (BigInt a, int b) {
    return (a == Integer(b));
}

bool operator >= (BigInt a, int b) {
    return (a >= Integer(b));
}

bool operator <= (BigInt a, int b) {
    return (a <= Integer(b));
}



BigInt max(BigInt a, BigInt b) {
    if (a > b) return a;
    return b;
}

BigInt min(BigInt a, BigInt b) {
    if (a < b) return a;
    return b;
}




BigInt operator + (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i,0,max(a.size(), b.size())-1) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.pb(carry%base);
        carry /= base;
    }
    if (carry) ans.pb(carry);
    Set(ans);
    return ans;
}

BigInt operator + (BigInt a, int b) {
    return a + Integer(b);
}

BigInt operator ++ (BigInt &a) { // ++a
    a = a + 1;
    return a;
}

void operator += (BigInt &a, BigInt b) {
    a = a + b;
}

void operator += (BigInt &a, int b) {
    a = a + b;
}




BigInt operator - (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i,0,a.size()-1) {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0) ans.pb(carry+base), carry = -1;
        else ans.pb(carry), carry = 0;
    }
    Set(ans);
    return ans;
}

BigInt operator - (BigInt a, int b) {
    return a - Integer(b);
}

void operator -- (BigInt &a) { // --a
    a = a - 1;
}

void operator -= (BigInt &a, BigInt b) {
    a = a + b;
}

void operator -= (BigInt &a, int b) {
    a = a - b;
}




BigInt operator * (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size()+b.size(), 0);
    FOR(i,0,a.size()-1) {
        ll carry = 0ll;
        for (int j=0;j<b.size() || carry > 0;j++) {
            ll s = ans[i+j] + carry + (ll)a[i]*(j<b.size()?(ll)b[j]:0ll);
            ans[i+j] = s%base;
            carry = s/base;
        }
    }
    Set(ans);
    return ans;
}

BigInt operator * (BigInt a, int b) {
    return a * Integer(b);
}

void operator *= (BigInt &a, BigInt b) {
    a = a * b;
}

void operator *= (BigInt &a, int b) {
    a = a * b;
}



BigInt operator / (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == Integer(0)) return Integer("-1");
    BigInt ans, cur;
    FORD(i,a.size()-1,0) {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L+R)>>1;
            if (b*Integer(mid) > cur) {
                x = mid;
                R = mid-1;
            }
            else
                L = mid+1;
        }
        cur = cur - Integer(x-1)*b;
        ans.insert(ans.begin(),x-1);
    }
    Set(ans);
    return ans;
}

BigInt operator / (BigInt a, int b) {
    Set(a);
    BigInt ans;
    ll cur = 0ll;
    FORD(i,a.size()-1,0) {
        cur = (cur*(ll)base + (ll)a[i]);
        ans.insert(ans.begin(),cur/b);
        cur %= b;
    }
    Set(ans);
    return ans;
}

void operator /= (BigInt &a, BigInt b) {
    a = a / b;
}

void operator /= (BigInt &a, int b) {
    a = a / b;
}



BigInt operator % (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == Integer(0)) return Integer("-1");
    BigInt ans;
    FORD(i,a.size()-1,0) {
        ans.insert(ans.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L+R)>>1;
            if (b*Integer(mid) > ans) {
                x = mid;
                R = mid-1;
            }
            else
                L = mid+1;
        }
        ans = ans - Integer(x-1)*b;
    }
    Set(ans);
    return ans;
}

int operator % (BigInt a, int b) {
    Set(a);
    if (b == 0) return -1;
    int ans = 0;
    FORD(i,a.size()-1,0)
        ans = (ans*(base%b) + a[i]%b)%b;
    return ans;
}

void operator %= (BigInt &a, BigInt b) {
    a = a % b;
}

void operator %= (BigInt &a, int b) {
    a = a % Integer(b);
}

BigInt gcd(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    while (b > Integer(0)) {
        BigInt r = a%b;
        a = b;
        b = r;
    }
    Set(a);
    return a;
}

BigInt lcm(BigInt a, BigInt b) {
    return (a*b/gcd(a,b));
}


BigInt sqrt(BigInt a) {
    BigInt x0 = a, x1 = (a+1)/2;
    while (x1 < x0) {
        x0 = x1;
        x1 = (x1+a/x1)/2;
    }
    return x0;
}


BigInt pow(BigInt a, BigInt b) {
    if (b == Integer(0)) return Integer(1);
    BigInt tmp = pow(a, b/2);
    if (b%2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}


BigInt pow(BigInt a, int b) {
    return pow(a,(Integer(b)));
}


int log(int n, BigInt a) { // log_n(a)
    Set(a);
    int ans = 0;
    while (a > Integer(1)) {
        ans++;
        a /= n;
    }
    return ans;
}

bool check(int x, int y, ll sz) {
		bitset<32> a(x), b(y);
		int last = -1;
		for (int i = 32, j = 0; j < sz; i--, j++) {
				if ((a[j] ^ b[j]) == 0) {
						if (last == a[j] % 2) {
								return false;
						}
						last = a[j] % 2;
				} else {
						last = -1;
				}
		}
		return true;
}

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

				Matrix operator^(BigInt power) {
						Matrix result = Identity(this->rows);
						Matrix A(this->matrix);
						while (power > 0) {
								if (power % 2 == 1) {
										result *= A;
								}
								A *= A;
								power /= 2;
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


ifstream fin("nice.in");
ofstream fout("nice.out");

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll m, p;
		string n;
		fin >> n >> m >> p;
		MOD = p;

		/* There are 2^m distinct states. */
		ll sz = (1ll << m);
		vector<vector<long long>> A(sz, vector<long long>(sz));

		for (int i = 0; i < sz; i++) {
				for (int j = i; j < sz; j++) {
						if (check(i, j, m)) {
								A[i][j] = A[j][i] = 1;
//								cout << "(" << bitset<8>(i) << " and " << bitset<8>(j) << ") are ok." << endl;
						} else {
//								cout << "(" << bitset<8>(i) << " and " << bitset<8>(j) << ") are not ok." << endl;
						}
				}
		}
		BigInt power = Integer(n);
		Matrix mat(A);
//		cout << mat << endl;
		mat = mat ^ (power - 1);

		long long s = 0;

		// [i][j] = # ways to go from i to j
		for (int i = 0; i < sz; i++) {
				for (int j = 0 ; j < sz; j++) {
						s = (s + mat[i][j]) % MOD;
				}
		}
		fout << s << endl;
		fout.close();
}
