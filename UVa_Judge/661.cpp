#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <fstream>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

typedef long long ll;

using namespace std;




int main() {
  ll n, m, c;
  int j = 0;
  bool isfirst = true;
  while (cin >> n >> m >> c) {
    if (!isfirst) cout << "\n";

    if (!n && !m && !c) break;

    isfirst = false;

    int consumptions[30];
    bool states[30];
    memset(states, false, sizeof(states));
    for (int i = 0; i < n; i++) {
      cin >> consumptions[i];
    }

    ll maxi = 0;
    ll curr = 0;

    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      states[x - 1] = !states[x - 1];
      if (states[x-1]) {
        curr += consumptions[x-1];
        maxi = MAX(maxi, curr);
      } else {
        curr -= consumptions[x-1];
      }
    }


    cout << "Sequence " << ++j << endl;
    if (maxi > c) {
      cout << "Fuse was blown." << endl;
    } else {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << maxi << " amperes." << endl;
    }


  }
}
