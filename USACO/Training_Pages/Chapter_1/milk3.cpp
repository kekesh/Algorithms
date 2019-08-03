/* ID: ekfrmd1
   LANG: C++
   TASK: milk3
*/
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef struct cup {
  ll water;
  ll storage;
} Cup;

bool seen[25][25][25];

void setIO();
void init();
int solve();
void record();
void print();
int pour(Cup *from, Cup *to);

ifstream fin("milk3.in");
ofstream fout("milk3.out");

Cup A, B, C;
set<ll> answers;

int counts = 0;

void print() {
  /* cout << "A: Storage: " << A.storage << " Water: " << A.water << endl;
   cout << "B: Storage: " << B.storage << " Water: " << B.water << endl;
   cout << "C: Storage: " << C.storage << " Water: " << C.water << endl;
   cout << "\n"; */
  multiset<ll>::iterator it = answers.begin();
  while (it != answers.end()) {
    fout << *it;
    it++;
    if (it != answers.end()) {
      fout << " ";
    }
  }
  fout << "\n";
}

int main() {
  init();
  fin.close();
  solve();
  print();
  fout.close();
}

void init() {
  fin >> A.storage >> B.storage >> C.storage;
  C.water = C.storage;
}

/* A recursive depth-first search algorithm with pruning. 
   This solution has O(n^3) space complexity; however, it could
   have been solved with O(n^2) space complexity by noting that
   states are completely determined by any two of (A, B, C). */
   
int solve() {
  if (seen[A.water][B.water][C.water]) {
    return 0;
  } else if (A.water == 0) {
    counts++;
    answers.insert(C.water);
  }
  seen[A.water][B.water][C.water] = 1;

  ll a_water = A.water, b_water = B.water, c_water = C.water;
  pour(&A, &B);
  solve();
  A.water = a_water, B.water = b_water, C.water = c_water;  // Backtrack
  pour(&A, &C);
  solve();
  A.water = a_water, B.water = b_water, C.water = c_water;  // Backtrack
  pour(&B, &A);
  solve();
  A.water = a_water, B.water = b_water, C.water = c_water;  // Backtrack
  pour(&B, &C);
  solve();
  A.water = a_water, B.water = b_water, C.water = c_water;  // Backtrack
  pour(&C, &A);
  solve();
  A.water = a_water, B.water = b_water, C.water = c_water;  // Backtrack
  pour(&C, &B);
  solve();
  A.water = a_water, B.water = b_water, C.water = c_water;  // Backtrack
}

/* Returns 1 upon success; 0 otherwise. */
int pour(Cup *from, Cup *to) {
  if (to == from || from->water == 0 || to->water == to->storage) {
    return 0;
  }

  while (from->water > 0 && to->water < to->storage) {
    from->water--;
    to->water++;
  }

  return 1;
}