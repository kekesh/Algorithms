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
vector<ll> unsorted_nums;
multiset<ll> differences;

void init();
void solve();
void setIO();

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        nums.push_back(x);
        unsorted_nums.push_back(x);
    }
    
    sort(nums.begin(), nums.end());
    set<ll> dummy;
    for (int i = 1; i < N; i++) {
        cout << "Inserting " << nums.at(i) - nums.at(i - 1) << endl;
        differences.insert(nums.at(i) - nums.at(i - 1));
        dummy.insert(nums.at(i) - nums.at(i - 1));
    }

    if (dummy.size() > 2) {
        cout << "-1" << endl;
        exit(0);
    }

    ll diff = -1;
    
    for (multiset<ll>::iterator it = differences.begin(); it != differences.end(); ++it) {
        if (differences.count(*it) > 1) {
            diff = *it;
            break;
        }
    }
    cout << "Diff is " << diff << endl;
    ll to_remove = -1;
    for (int i = 1; i < N - 1; i++) {
        if (nums.at(i) - nums.at(i - 1) != diff) {
            to_remove = nums.at(i);
        }
    }
    
    if (to_remove == -1) {
        cout << "1" << endl;
        exit(0);
    }
    
    for (int i = 1; i <= N; i++) {
        if (unsorted_nums.at(i - 1) == to_remove) {
            cout << i << endl;
            exit(0);
        }
    }
}



/* A greedy algorithm. */
int main() {
  setIO();
  init();
}
