/* ID: ekfrmd1
   LANG: C++
   TASK: crypt1
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

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

ll N;
set<ll> valid_nums;

void init() {
  fin >> N;
  for (int i = 0; i < N; i++) {
    ll x;
    fin >> x;
    valid_nums.insert(x);
  }
  fin.close();
}

vector<ll> num_to_vec(ll n) {
  // cout << "Here " << endl;
  ll temp = n;
  vector<ll> ans;
  int i = 0;
  while (temp != 0) {
    ans.push_back(temp % 10);
    temp /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

bool is_valid(vector<ll> num, int key) {
  if (key == 1) { /* For a */
    if (num.size() != 3) {
      return false;
    }
  }

  if (key == 2) { /* For b */
    if (num.size() != 2) {
      return false;
    }
  }

  if (key == 0) { /* For a*b */
    if (num.size() != 4) {
      return false;
    }
  }

  for (int i = 0; i < num.size(); i++) {
    if (valid_nums.count(num.at(i)) <= 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int answer = 0;
  for (int a = 100; a <= 999; a++) {
    for (int b = 10; b <= 99; b++) {
      if (is_valid(num_to_vec(a), 1) && is_valid(num_to_vec(b), 2) &&
          is_valid(num_to_vec(a * b), 0)) {
        /* Need to check the two partial products of a * b */
        if (is_valid(num_to_vec(a * (b % 10)), 1) &&
            is_valid(num_to_vec(a * (b / 10)), 1)) {
          /* Good. */
          answer++;
        }
      }
    }
  }
  fout << answer << endl;
  fout.close();
}

int main() {
  init();
  solve();
  return 0;
}
