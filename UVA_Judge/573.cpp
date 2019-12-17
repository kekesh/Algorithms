#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

typedef long long ll;

using namespace std;


// annoying edge cases. read carefully.

int main() {
  double H, U, D, F;

  while (cin >> H >> U >> D >> F) {
    if (H == 0) break;

    double delta = U * F/100;

    bool isok = true;
    double hite = 0;

    int day = 0;
    while ((hite > -0.0005 && hite <= H+0.0005) || isok) {
      day++;
      isok = false;
      hite += U;
      U = MAX(U - delta, 0);
      if (hite >= H+0.0005) break;
      else hite = hite - D;
    }
    if (hite <= -0.0005) {
      cout << "failure on day " << day << endl;
    } else {
      cout << "success on day " << day << endl;
    }

  }
}
