/* ID: ekfrmd1
   LANG: C++
   TASK: palsquare
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
vector<int> convert(int n);

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

ll B;
vector<int> base_rep;

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() { fin >> B; }

vector<int> convert(int n) {
  int count = 0;
  stack<int> temp;
  while (n != 0) {
    // cout << "Iterating!" << endl;
    int digit = n % B;
    // cout << "Digit is " << digit << endl;
    if (digit >= 10) {
      digit += 55;
    }
    count++;
    temp.push(digit);
    n /= B;
  }
  vector<int> ans;
  for (int i = 0; i < count; i++) {
    // cout << "Pushing in " << temp.top() << endl;
    ans.push_back(temp.top());
    temp.pop();
  }

  return ans;
}

template <typename T>
bool is_palindrome(vector<T> input) {
  for (int i = 0; i < input.size() / 2; i++) {
    if (input.at(i) != input.at(input.size() - i - 1)) {
      return false;
    }
  }
  return true;
}

template <class T>
void print_vec(vector<T> input, bool flag) {
  for (int i = 0; i < input.size(); i++) {
    if (input.at(i) >= 10) {
        fout << (char) input.at(i);
    } else {
        fout << input.at(i);
    }
  }
  fout << (flag ? " " : "");
  if (!flag) {
    fout << "" << endl;
  }
}

int main() {
  setIO();
  init();
  solve();
}

void solve() {
  for (int i = 1; i <= 300; i++) {
    int x = i;
    int xsqrd = i * i;
    vector<int> bxsqrd = convert(xsqrd);
    if (is_palindrome(bxsqrd)) {
      print_vec(convert(x), 1);
      print_vec(bxsqrd, 0);
    }
  }
} 
