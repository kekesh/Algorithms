#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <bitset>
#include <unordered_map>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main() {
  // N = # Parking Spaces, M = # Cars.
  ll N, M;
  cin >> N >> M;

  ll rates[110];
  ll weights[2015];
  bool taken[110];


  for (int i = 1; i <= N; i++) {
    cin >> rates[i];
    taken[i] = false;
  }
  for (int i = 1; i <= M; i++) {
    cin >> weights[i];
  }


  /* A parking function. Maps Car # -> Parking Spot */
  unordered_map<int, int> parking_fn;
  int next_available_spot = 1;
  queue<int> parking_q;
  ll cost = 0;
  for (int i = 1; i <= 2*M; i++) {
    ll x;
    cin >> x;
    if (x > 0) {
      if (next_available_spot > N) {
        parking_q.push(x);
      } else {
        parking_fn[x] = next_available_spot; // Map car # to parked spot.
        taken[next_available_spot] = true;
        cost += weights[x] * rates[next_available_spot];
        next_available_spot++;

        while (taken[next_available_spot] && next_available_spot <= N) {
          next_available_spot++;
        }

      }
    } else if (x < 0 && parking_fn.count(-x) > 0) {
      x = abs(x);
      taken[parking_fn[x]] = false;
      next_available_spot = MIN(next_available_spot, parking_fn[x]);
      parking_fn.erase(x);

      if (parking_q.size() > 0) {
        int y = parking_q.front();
        parking_q.pop();
        parking_fn[y] = next_available_spot;
        taken[next_available_spot] = true;
        cost += weights[y] * rates[next_available_spot];
        next_available_spot++;

        while (taken[next_available_spot] && next_available_spot <= N) {
          next_available_spot++;
        }
      }
    }
  }
  cout << cost << endl;
}
