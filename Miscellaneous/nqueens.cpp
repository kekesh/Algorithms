/* A depth-first search solution to the n-queens problem.
   Solution by Ekesh Kumar.
*/

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
void init();
void setIO();
bool is_safe(int row, int col);
void solve();
void search(int col);

bool board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

int main() {
  search(0);
  return 0;
}

/* A depth-first recursive solution. */
void search(int col) {
  if (col >= 4) {
    exit(0);
  }

  for (int row = 0; row < 4; row++) {
    if (is_safe(row, col)) {
      board[row][col] = 1;
      if (col == 3 && board[row][col]) {
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
          }
          cout << "\n";
        }
      }
      search(col + 1);
      board[row][col] = 0; // Backtracking
    }
  }
}

/* Given an array, row, and column, this function returns whether
   or not a queen would be safe if she were placed there. */
bool is_safe(int row, int col) {
  for (int k = 0; k < 4; k++) {
    if (board[row][k]) return false;
  }
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;

  for (int i = row, j = col; j >= 0 && i < 4; i++, j--) {
    if (board[i][j]) return false;
  }
  return true;
}
