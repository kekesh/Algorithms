#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll N;
set<ll> nums;

void init();
void solve();
void setIO();

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

bool isPowerOfTwo(int x) { return x && (!(x & (x - 1))); }

void init() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    nums.insert(x);
  }
}

int main() {
  setIO();
  init();

}
void solve() {


}