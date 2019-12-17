#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <algorithm>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

typedef long long ll;

using namespace std;




int main() {

  int j = 0;

  string st;
  while (getline(cin, st), st != "") {
    ll N;
    cin >> N;
    cout << "Case " << ++j << ":" << endl;
    for (int i = 0; i < N; i++) {
      ll a, b;
      cin >> a >> b;

      char temp = st[MIN(a, b)];
      bool isok = true;
      for (int j = MIN(a, b); j <= MAX(a, b); j++) {
        if (st[MIN(a, b)] != st[j]) { isok = false; break; }
      }

      if (isok) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    getchar();


  }

  return 0;
}
