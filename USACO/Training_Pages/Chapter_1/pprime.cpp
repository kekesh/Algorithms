/* ID: ekfrmd1
   LANG: C++
   TASK: pprime
*/
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)

using namespace std;

inline void init();
void sieve(ll bound);
bool is_palindrome(int num);
void setIO();

ifstream fin("pprime.in");
ofstream fout("pprime.out");

ll a, b;
bitset<50000005> primes;
vector<ll> palindromes;

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}




int createPalindrome(int input, int b, bool isOdd) {
  int n = input;
  int palin = input;

  if (isOdd) {
    n /= b;
  }

  while (n > 0) {
    palin = palin * b + (n % b);
    n /= b;
  }
  return palin;
}

void generatePalindromes(ll lower, ll upper) {
  int number;

  for (int j = 0; j < 2; j++) {
    int i = 1;
    while ((number = createPalindrome(i, 10, j % 2)) < upper) {
      if (number >= lower) {
        palindromes.push_back(number);
      }
      i++;
    }
  }
}

int main() {
  setIO();
  init();
  generatePalindromes(a, b + 1);
  sort(palindromes.begin(), palindromes.end());
  sieve(b);

  for (int i = 0; i < palindromes.size(); i++) {
    if ((palindromes.at(i) & 1) && primes[palindromes.at(i) / 2] == 0) {
      fout << palindromes.at(i) << endl;
    }
  }

  return 0;
}

inline void init() { fin >> a >> b; }

/* O(n log log n) bit sieve */
/* Skip all even numbers. */
void sieve(ll bound) {
  for (int i = 3; i * i < bound; i += 2) {
    if (primes[i / 2] == 0)
      for (int j = i * i; j < bound; j += i * 2) {
        primes[j / 2] = 1;
      }
  }
}