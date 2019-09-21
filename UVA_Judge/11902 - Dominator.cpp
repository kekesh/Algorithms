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
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define mp make_pair
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();

bool visited_all[101]; /* A vector<int> type; tells us visited or unvisited. */
bool visited[101];
int adj_mat[101][101];

ll T;
ll N;

void dfs(int u, int dominator) {
  visited[u] = true;
  F0R(j, N) {
    if (adj_mat[u][j] == 1 && visited[j] == false && u != dominator) {
      dfs(j, dominator);
    }
  }
}

void dfs_all(int u) {
  visited_all[u] = true;
  F0R(j, N) {
    if (adj_mat[u][j] == 1 && visited_all[j] == false) dfs_all(j);
  }
}

int main(void) {
  setIO();
  int caseNo = 0;
  cin >> T;
  while (T--) {
    caseNo++;
    cin >> N;
    F0R(i, N) {
      F0R(j, N) { cin >> adj_mat[i][j]; }
    }

    memset(visited_all, false, sizeof(visited_all));
    dfs_all(0);

    cout << "Case " << caseNo << ":" << endl;
    string divider = "+";
    F0R(i, 2 * N - 1) divider += "-";
    divider += "+";

    F0R(i, N) {
      cout << divider << endl;

      memset(visited, false, sizeof(visited));
      dfs(0, i);

      F0R(j, N) {
        if ((i == j || visited[j] == false) && visited_all[j] == true) {
          /* Can't get to it without that node. */
          cout << "|Y";
        } else {
          cout << "|N";
        }
      }
      cout << "|\n";
    }
    cout << divider << "\n";
  }
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
