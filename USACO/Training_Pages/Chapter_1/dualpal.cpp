/* ID: ekfrmd1
   LANG: C++
   TASK: dualpal
*/
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
typedef pair<int, int> pi;

void init();
void solve();
vector<int> convert(int n, int B);

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

ll N, S;

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() { fin >> N >> S; }

template <typename T>
bool is_palindrome(vector<T> input) {
  if (input.at(0) == 0 || input.at(input.size() - 1) == 0) {
    return false;
  }
  for (int i = 0; i < input.size() / 2; i++) {
    if (input.at(i) != input.at(input.size() - i - 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  setIO();
  init();
  solve();
}

void solve() {
  int count = 0, i = S + 1;
  while (count < N) {
    int palindrome_count = 0;
    for (int base = 2; base <= 10; base++) {
      vector<int> rep = convert(i, base);
      if (is_palindrome(rep)) {
        palindrome_count++;
        if (palindrome_count == 2) {
          break;
        }
      }
    }

    if (palindrome_count == 2) {
      count++;
      fout << i << endl;
    }

    i++;
  }
}

vector<int> convert(int n, int B) {
  int count = 0;
  stack<int> temp;
  while (n != 0) {
    int digit = n % B;
    if (digit >= 10) {
      digit += 55;
    }
    count++;
    temp.push(digit);
    n /= B;
  }
  vector<int> ans;
  for (int i = 0; i < count; i++) {
    ans.push_back(temp.top());
    temp.pop();
  }

  return ans;
}