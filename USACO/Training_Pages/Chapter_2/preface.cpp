/*
  ID: ekfrmd1
  LANG: C++11
  TASK: preface
*/

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
inline void init();
void intToRoman(int num);

ifstream fin("preface.in");
ofstream fout("preface.out");

ll N;
int numerals[8];
char mapping[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

inline void init() { fin >> N; }

void intToRoman(int num) {
  string m[] = {"", "M", "MM", "MMM"};
  string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  
  string thousands = m[num / 1000];
  string hundereds = c[(num % 1000) / 100];
  string tens = x[(num % 100) / 10];
  string ones = i[num % 10];

  string ans = thousands + hundereds + tens + ones;

  F0R(i, ans.length()) {
    if (ans[i] == 'I')
      numerals[0]++;
    else if (ans[i] == 'V')
      numerals[1]++;
    else if (ans[i] == 'X')
      numerals[2]++;
    else if (ans[i] == 'L')
      numerals[3]++;
    else if (ans[i] == 'C')
      numerals[4]++;
    else if (ans[i] == 'D')
      numerals[5]++;
    else if (ans[i] == 'M')
      numerals[6]++;
  }
}

int main() {
  init();
  FOR(i, 1, N + 1) { intToRoman(i); }
  F0R(i, 8) {
    if (numerals[i] != 0) {
      fout << mapping[i] << " " << numerals[i] << endl;
    }
  }
  return 0;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}
