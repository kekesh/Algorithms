#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
void init();
void solve();



ll N, a;
ll mi = 0, pl = 0, nl = 0;
ll sum = 0;

int main() {
    cin >> N;
    
    F0R(i, N) {
        ll a;
        cin >> a;
        if (a < 0 && a != -1) {
            mi++;
            sum += -a -1;
        }
        if (a == -1) mi++;
        if (a > 0 && a != -1) {
            pl++;
            sum += a - 1;
        }
        if ( a== 1) pl++;
        if ( a==0) {
            sum++;
            nl++;
        }
    }
    if (mi % 2 == 1) {

        if (nl > 0) ;
        else sum += 2;
    }

    cout << sum << endl;
    return 0;
    }

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}