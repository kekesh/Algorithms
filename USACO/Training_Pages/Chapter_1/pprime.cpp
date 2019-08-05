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
// A C++ program to generate palindromic numbers
// less than n.
#include <iostream>
using namespace std;

// A utility for creating palindrome
int createPalindrome(int input, int b, bool isOdd) {
  int n = input;
  int palin = input;

  if (isOdd) {
    n /= b;
  }

  // cout << "n = " << n << " , palin = " << palin << endl;
  // of number to itself
  while (n > 0) {
    palin = palin * b + (n % b);
    // cout << "palin is now " << palin << endl;
    n /= b;
    // cout << "n is now " << n << endl;
  }

  return palin;
}

// Function to print decimal palindromic number
void generatePalindromes(ll lower, ll upper) {
  int number;

  // Run two times for odd and even length palindromes
  for (int j = 0; j < 2; j++) {
    int i = 1;
    while ((number = createPalindrome(i, 10, j % 2)) < upper) {
      // cout << "Pushing back " << number << endl;
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
  // cout << "a = " << a << " and b = " << b << endl;
  generatePalindromes(a, b + 1);

  // cout << "Done" << endl;
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

/* O(n log log n) sieve */
/* Skip all even numbers. */
void sieve(ll bound) {
  for (int i = 3; i * i < bound; i += 2) {
    if (primes[i / 2] == 0)
      for (int j = i * i; j < bound; j += i * 2) {
        primes[j / 2] = 1;
      }
  }
  // cout << "done" << endl;
}

bool is_palindrome(int num) {
  string num_str = to_string(num);

  F0R(i, num_str.length() / 2) {
    if (num_str[i] != num_str[num_str.length() - i - 1]) {
      return false;
    }
  }
  return true;
}