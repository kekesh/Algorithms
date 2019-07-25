/* ID: ekfrmd1
   LANG: C++
   TASK: namenum
*/
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string.h>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

void init();
void solve();
bool is_valid(vector<ll> digits, string word, int index);

ifstream fin1("namenum.in");
ifstream fin2("dict.txt");
ofstream fout("namenum.out");

ll N;
vector<ll> digits;

void init() {
  fin1 >> N;
  ll temp = N;
  while (temp != 0) {
    digits.insert(digits.begin(), temp % 10);
    temp /= 10;
  }

}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {
  string next_word;
  bool flag;
  bool at_least_one = false;
  while (fin2 >> next_word) {
    if (next_word.length() == digits.size()) {
      /* At the correct size */
      for (int i = 0; i < digits.size(); i++) {
          flag = is_valid(digits, next_word, i);
          if (flag == false) {
            break;
          }
      }
      if (flag == true) {
        at_least_one = true;
        fout << next_word << endl;
      }
    }
  }
  if (at_least_one == false) {
    fout << "NONE" << endl;
  }


}

bool is_valid(vector<ll> digits, string word, int index) {
  switch (digits.at(index)) {
    case 1: 
      return false;
    case 2:
      if (word[index] == 'A' || word[index] == 'B' || word[index] == 'C') {
        return true;
      }
      return false;
    case 3:
       if (word[index] == 'D' || word[index] == 'E' || word[index] == 'F') {
        return true;
      }
      return false;
    case 4:
     if (word[index] == 'G' || word[index] == 'H' || word[index] == 'I') {
        return true;
      }
      return false;
    case 5:
      if (word[index] == 'J' || word[index] == 'K' || word[index] == 'L') {
        return true;
      }
      return false;
    case 6:
      if (word[index] == 'M' || word[index] == 'N' || word[index] == 'O') {
        return true;
      }
      return false;
    case 7:
      if (word[index] == 'P' || word[index] == 'R' || word[index] == 'S') {
        return true;
      }
      return false;
    case 8:
      if (word[index] == 'T' || word[index] == 'U' || word[index] == 'V') {
        return true;
      }
      return false;
    case 9:
      if (word[index] == 'W' || word[index] == 'X' || word[index] == 'Y') {
        return true;
      }
      return false;
    default:
      return false;
  }
}

int main() {
  setIO();
  init();
  solve();
  return 0;
}
