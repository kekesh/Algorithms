/*
  ID: ekfrmd1
  LANG: C++11
  TASK: castle
*/

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>

#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void init();
void solve();
void setIO();
bool is_neighbor(int row1, int col1, int row2, int col2);
void flood_fill(ll curr);
void find_components();
void get_max_merged();

ifstream fin("castle.in");
ofstream fout("castle.out");

ll N, M;
ll walls[52][52];
ll components[52][52];
ll room_sizes[2520];

ll num_components = 0;

int main() {
  setIO();
  init();
  fin.close();
  find_components();

  F0R(i, N) {
    F0R(j, M) { cout << components[i][j] << " "; }
    cout << "\n";
  }
  ll max_size = -1;
  cout << "printing max array!\n";
  F0R(i, num_components) {
    cout << "i = " << i << ", size = " << room_sizes[i] << "; ";
    max_size = MAX(max_size, room_sizes[i]);
  }
  cout << "\n";
  fout << max_size << endl;
  // cout << "Max size: " << max_size << endl;
  get_max_merged();
}

ll curr_max = -1;
ll wall_row = -1, wall_col = -1;
char wall_loc;

void get_max_merged() {
  F0R(row, N) {
    F0Rd(col, M) {
      cout << "Checking row " << row << " and col " << col << endl;
      /* Check the direct right. */
      if (col != M - 1 && components[row][col] != components[row][col + 1]) {
        ll candidate1 = room_sizes[components[row][col] - 1] +
                        room_sizes[components[row][col + 1] - 1];

        if (candidate1 >= curr_max) {
          /* A new candidate for max has been found. */
          if (candidate1 == curr_max && wall_col < col) {
            continue; /* What we have is already better. */
          }
          if (candidate1 == curr_max && wall_col == col && wall_row > row) {
            continue; /* What we have is better. */
          }

          if (wall_col != col || wall_row != row) {
            /* Does the wall we're at have an east wall? This is better. */
            if (walls[row][col] == 4 || walls[row][col] == 5 ||
                walls[row][col] == 6 || walls[row][col] == 7 ||
                walls[row][col] == 12 || walls[row][col] == 13 ||
                walls[row][col] == 14 || walls[row][col] == 15) {
              wall_row = row;
              wall_col = col;
              curr_max = candidate1;
              wall_loc = 'E';
              cout << "New candidate (E) at: " << wall_row << ", " << wall_col
                   << endl;
            } else {
              wall_row = row;
              wall_col = col + 1;
              curr_max = candidate1;
              wall_loc = 'W';
            }
          }
        }
      }

      /* Check to the south. */
      if (row != N - 1 && components[row][col] != components[row + 1][col]) {
        ll candidate2 = room_sizes[components[row + 1][col] - 1] +
                        room_sizes[components[row][col] - 1];

        if (candidate2 >= curr_max) {
          /* candidate2 is potentially the best. */
          /* Does the current location have a south wall? */
          if (candidate2 == curr_max && wall_col < col) {
            continue;
          }

          if (candidate2 == curr_max && wall_col == col && wall_row > row) {
            continue; /* What we have is better. */
          }

          if (walls[row][col] >= 8 && walls[row][col] <= 15) {
            wall_row = row;
            wall_col = col;
            wall_loc = 'S';
            curr_max = candidate2;
            cout << "New candidate at: " << wall_row << ", " << wall_col
                 << endl;
          }

          /* Does the next row have a north wall? This is better. */
          if (walls[row + 1][col] == 2 || walls[row + 1][col] == 3 ||
              walls[row + 1][col] == 6 || walls[row + 1][col] == 7 ||
              walls[row + 1][col] == 10 || walls[row + 1][col] == 11 ||
              walls[row + 1][col] == 14 || walls[row + 1][col] == 15) {
            wall_row = row + 1;
            wall_col = col;
            wall_loc = 'N';
            curr_max = candidate2;
            cout << "New candidate! at: " << wall_row << ", " << wall_col
                 << endl;
          }
        }
        /* If wall_row < row, we've already got a better solution. */
      }
    }
  }

  fout << curr_max << endl;
  fout << (wall_row + 1) << " " << (wall_col + 1) << " " << wall_loc << endl;
}

void find_components() {
  /* For each node i, we check if i has already been assigned
     a component. */
  F0R(i, N) {
    F0R(j, M) {
      if (components[i][j] == 0) {
        num_components++;
        components[i][j] = -2;
        flood_fill(num_components);
      }
    }
  }
  fout << num_components << endl;
  // cout << num_components << endl;
}

void flood_fill(ll curr) {
  ll num_visited = 0;

  do {
    num_visited = 0;
    F0R(i, N) {
      F0R(j, M) {
        if (components[i][j] == -2) {
          num_visited++;
          room_sizes[curr - 1]++;
          components[i][j] = curr;

          /* Process all neighbors. */
          if (is_neighbor(i, j, i + 1, j) && components[i + 1][j] == 0) {
            components[i + 1][j] = -2;
          }

          if (is_neighbor(i, j, i, j + 1) && components[i][j + 1] == 0) {
            components[i][j + 1] = -2;
          }

          if (is_neighbor(i, j, i - 1, j) && components[i - 1][j] == 0) {
            components[i - 1][j] = -2;
          }

          if (is_neighbor(i, j, i, j - 1) && components[i][j - 1] == 0) {
            components[i][j - 1] = -2;
          }
        }
      }
    }
  } while (num_visited != 0);
}


void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> M >> N;
  F0R(i, N) {
    F0R(j, M) {
      fin >> walls[i][j];
      
    }
  }
}

bool is_neighbor(int row1, int col1, int row2, int col2) {
  if (!(row1 >= 0 && col1 >= 0) || !(row2 >= 0 && col2 >= 0)) {
    return false;
  }

  if (!(col1 <= M - 1 && col2 <= M - 1) || !(row1 <= N - 1 && row2 <= N - 1)) {
    return false;
  }

  /* Case 1: (i1, j1) is directly to the right of (i2, j2). */
  if (row1 - row2 == 0 && col1 - col2 == 1) {
    // cout << "In here" << endl;
    if (walls[row1][col1] & 1 || walls[row2][col2] == 4 ||
        walls[row2][col2] == 5 || walls[row2][col2] == 6 ||
        walls[row2][col2] == 7 || walls[row2][col2] == 12 ||
        walls[row2][col2] == 13 || walls[row2][col2] == 15) {
      return false;
    }
    return true;
  }

  /* Case 2: (i1, j1) is directly to the left of (i2, j2) */
  if (row1 - row2 == 0 && col1 - col2 == -1) {
    return is_neighbor(row2, col2, row1, col1);
  }

  /* Case 3: (i1, j1) is directly below (i2, j2) */
  if (row1 - row2 == 1 && col1 - col2 == 0) {
    if (walls[row1][col1] == 2 || walls[row1][col1] == 3 ||
        walls[row1][col1] == 6 || walls[row1][col1] == 7 ||
        walls[row1][col1] == 10 || walls[row1][col1] == 15) {
      return false;
    }

    if (8 <= walls[row2][col2] && walls[row2][col2] <= 15) {
      return false;
    }

    return true;
  }

  /* Case 4: (i1, j1) is directly below (i2, j2). */
  if (row1 - row2 == -1 && col1 - col2 == 0) {
    return is_neighbor(row2, col2, row1, col1);
  }

  /* This covers all four disjoint cases. If we get here, our
     two points aren't neighbors. */
  return false;
}