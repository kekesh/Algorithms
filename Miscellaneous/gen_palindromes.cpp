/* A quick algorithm to generate palindromes up to a specified limit. */

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> palindromes;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void gen_palindromes(ll limit);
ll util_palindromes(ll num, ll base, ll is_odd);

int main() {
  gen_palindromes(1000);
  F0R(i, palindromes.size()) { cout << palindromes.at(i) << " "; }
  cout << "\n";
  return 0;
}

void gen_palindromes(ll limit) {
  ll num = 0;
  ll i = 1;
  palindromes.push_back(0);
  while ((num = util_palindromes(i, 10, 1)) < limit) {
    palindromes.push_back(num);
    i++;
  }
  i = 1;
  while ((num = util_palindromes(i, 10, 0)) < limit) {
    palindromes.push_back(num);

    i++;
  }
  sort(palindromes.begin(), palindromes.end());
}

ll util_palindromes(ll num, ll base, ll is_odd) {
  ll palindrome = num;
  ll to_append = num;

  if (is_odd) {
    to_append /= base;
  }

  while (to_append > 0) {
    palindrome = palindrome * base + (to_append % base);
    to_append /= 10;
  }

  return palindrome;
}
