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

ll N, K;
vector<ll> nums;
vector<ll> differences;

void init();
void solve();
void setIO();

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        nums.push_back(x);
    }
    for (int i = 1; i < N; i++) {
        differences.push_back(nums.at(i) - nums.at(i - 1));
    }
    sort(differences.begin(), differences.end());
}

void solve() {
    ll answer = nums.at(nums.size() - 1) - nums.at(0);
    for (int i = 0; i < K - 1; i++) {
        answer -= differences.at(differences.size() - 1);
        differences.erase(differences.begin() + differences.size() - 1);
    } 
    cout << answer << endl;
}

/* A greedy algorithm. */
int main() {
  setIO();
  init();
  solve();
}
