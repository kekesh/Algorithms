#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


bool is_palindrome(string s1) {
  for (int i = 0; i <= s1.size()/2; i++) {
    if (s1[i] != s1[s1.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {

  string st;
  while (cin >> st) {
    unordered_set<string> seen;

    int cnt = 0;
    for (int i = 0; i < st.size(); i++) {
      for (int j = 1; j <= st.size() - i; j++) {
        if (is_palindrome(st.substr(i, j)) && !seen.count(st.substr(i, j))) {
          seen.insert(st.substr(i, j));
          cnt++;
        }
      }
    }
    cout << "The string '" << st << "' contains " << cnt << " palindromes." << endl;
  }
}


