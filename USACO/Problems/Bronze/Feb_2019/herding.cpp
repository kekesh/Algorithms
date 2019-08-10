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

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

inline void init();
void solve();
void setIO();
bool is_valid();

ifstream fin("herding.in");
ofstream fout("herding.out");

vector<ll> nums(3);

int main() {
  setIO();
  init();
  fin.close();
  sort(nums.begin(), nums.end());
  solve();
  fout.close();
  return 0;
}

void solve() {
  /* Minimum. */
  if (is_valid()) {
    fout << "0" << endl;
  } else if (nums[2] - nums[1] == 2 || nums[1] - nums[0] == 2) {
    fout << "1" << endl;
  } else {
    fout << "2" << endl;
  }

  /* Maximum. */
  fout << max(nums[2] - nums[1], nums[1] - nums[0]) - 1 << endl;
}

bool is_valid() {
  return ((nums[2] - nums[1]) == (nums[1] - nums[0]) &&
          (nums[1] - nums[0] == 1));
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

inline void init() { fin >> nums[0] >> nums[1] >> nums[2]; }