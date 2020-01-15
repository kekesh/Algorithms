#include <iostream>

using namespace std;

int N;
int grid[10][10];

void solve(int start) {

  int sum = 0;

  for (int c = start; c < N - start; c++) {
    sum += grid[start][c];
    sum += grid[r][start];
  }
  for (int r = N - start - 1; r >= start; r--) {
    sum += grid[r][N - start - 1];
    sum += grid[N - start - 1][c];
  }

  // Double counted
  sum -= grid[start][start];
  sum -= grid[N - start - 1][N - start - 1];
  sum -= grid[N - start - 1][start];
  sum -= grid[start][N - start - 1];

  cout << sum;
}

int main() {
  bool fst = true;
  int j = 0;
  while (cin >> N, N != 0) {
    if (!fst) cout << endl;
    fst = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> grid[i][j];
      }
    }
    int x = (N + 1)/2;
    cout << "Case " << ++j << ": ";
    for (int i = 0; i < x; i++) {
        if (N & 1 && i == x - 1) {
          cout << grid[x - 1][x - 1];
          break;
        } else {
          solve(i);
          if (i != x - 1) cout << " ";
        }
    }
  }
}

