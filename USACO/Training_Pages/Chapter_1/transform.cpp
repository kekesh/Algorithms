/* ID: ekfrmd1
   LANG: C++
   TASK: transform
*/
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

void init();
void solve();

ifstream fin("transform.in");
ofstream fout("transform.out");

int N;
char preim[20][20];
char postim[20][20];

/* template <class T>
void print(T input) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fout << input[i][j];
    }
    fout << "" << endl;
  }
}  */

void init() {
  char x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> x;
      preim[i][j] = x;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> x;
      postim[i][j] = x;
    }
  }
}

template <class T>
char** reflect(T preim) {
  char** reflection = new char*[N];
  for (int i = 0; i < N; i++) {
    reflection[i] = new char[N];
    for (int j = 0; j < N; j++) {
      reflection[i][j] = preim[i][j];
    }
  }

  int bound = (N - 1) / 2 + 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < bound; j++) {
      swap(reflection[i][j], reflection[i][N - j - 1]);
    }
  }

  return reflection;
}

template <class T>
char** rotate(T preim) {
  char** rotation = new char*[N];
  for (int i = 0; i < N; i++) {
    rotation[i] = new char[N];
    for (int j = 0; j < N; j++) {
      rotation[i][j] = preim[N - j - 1][i];
    }
  }

  return rotation;
}

template <class T>
bool check(T input) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (input[i][j] != postim[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  int ans = -1;

  if (check(rotate(preim))) {
    ans = 1;
  } else if (check(rotate(rotate(preim)))) {
    ans = 2;
  } else if (check(rotate(rotate(rotate(preim))))) {
    ans = 3;
  } else if (check(reflect(preim))) {
    ans = 4;
  } else if (check(rotate(reflect(preim)))) {
    ans = 5;
  } else if (check(rotate(rotate(reflect(preim))))) {
    ans = 5;
  } else if (check(rotate(rotate(rotate(reflect(preim)))))) {
    ans = 5;
  } else if (check(preim)) {
    ans = 6;
  } else {
    ans = 7;
  }
  fout << ans << endl;
}

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
  setIO();
  fin >> N;
  init();
  solve();
  return 0;
}
