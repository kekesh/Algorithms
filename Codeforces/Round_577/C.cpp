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

void init();
void solve();
void setIO();

ifstream fin("pprime.in");
ofstream fout("pprime.out");

ll n, k;
vector<ll> arr(200005);

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

int main() {
  setIO();
  init();
  solve();
  return 0;
}

void init() {
  cin >> n >> k;
  F0R(i, n) { cin >> arr[i]; }
  sort(arr.begin(), arr.begin() + n);
}

void solve() {
  ll median = arr[n / 2];
  ll multiplicity = 0;
  ll last_index = n / 2;

  F0R(i, n) {
    if (arr[i] == median) {
      multiplicity++;
      if (i > last_index) {
        last_index = i;
      }
    }
  }

  if (n == 1) {
    cout << arr[0] + k << endl;
    exit(0);
  }
  ll geq = n - last_index - 1;

  multiplicity = min(multiplicity, (n / 2 + 1) - geq);
  ll j = last_index + 1;

  bool at_end = (j == n) ? true : false;

  while (k > 0) {
    if (!at_end && (k - multiplicity * (arr[j] - median) >= 0)) {
      k -= multiplicity * (arr[j] - median);
      median += (arr[j] - median);
      if (!at_end) {
        while (arr[j] == median) {
          multiplicity++;
          j++;
          geq--;
          last_index = j;
          at_end = (j == n) ? true : false;
        }
        multiplicity = min(multiplicity, (n / 2 + 1) - geq);
      }
    } else {
      median += (k / multiplicity);
      k = 0;
    }
  }
  cout << median << endl;
}