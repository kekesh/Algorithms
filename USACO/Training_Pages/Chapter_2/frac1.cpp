/*
  ID: ekfrmd1
  LANG: C++11
  TASK: frac1
*/

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>

#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void init();
void solve();
void setIO();
inline void init();
int gcd(int a, int b);

ifstream fin("frac1.in");
ofstream fout("frac1.out");

ll N;

struct Fraction {
  double numerator;
  double denominator;

 public:
  Fraction(double num, double den) {
    numerator = num;
    denominator = den;
  }

  inline bool operator<(const Fraction& a) {
    return (numerator / denominator < a.numerator / a.denominator);
  }

  inline friend bool operator==(Fraction a, Fraction b) {
    double x = (a.numerator / (gcd(a.numerator, a.denominator))) /
               (a.denominator / gcd(a.numerator, a.denominator));

    double y = (b.numerator / (gcd(b.numerator, b.denominator))) /
               (b.denominator / (gcd(b.denominator, b.numerator)));
    return (x == y);
  }
};

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  setIO();
  init();
  fin.close();

  vector<Fraction> nums;

  F0R(den, N + 1) {
    F0R(num, den) {
      if (gcd(num, den) == 1) nums.push_back(Fraction(num, den));
    }
  }

  sort(nums.begin(), nums.end());

  F0R(i, nums.size()) {
    fout << nums.at(i).numerator << "/" << nums.at(i).denominator << endl;
  }
  fout << "1/1" << endl;
  fout.close();
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

inline void init() { fin >> N >> N; }