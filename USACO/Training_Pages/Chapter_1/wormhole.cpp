/* ID: ekfrmd1
   LANG: C++
   TASK: wormhole
*/
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
void init_right_array();
void solve();
void setIO();
void generatePairings(int* items, int itemcount, int start);
bool is_cycle(int* perm);

ll N;
vector<pi> coords;
int next_on_right[15];
int permutation_array[15];
int perm[15];
int answer = 0;

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

int main() {
  setIO();
  init();
  fin.close();
  init_right_array();
  generatePairings(permutation_array, N, 0);
  fout << answer << endl; 
  fout.close();
  return 0;
}

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void init() {
  fin >> N;
  int x, y;
  F0R(i, N) {
    fin >> x >> y;
    coords.push_back(make_pair(x, y));
    next_on_right[i] = -1;
    perm[i] = permutation_array[i] = i;
  }
}

void init_right_array() {
  F0R(i, N) {
    //cout << "Finding next on right for i = " << i << endl;
    pi current = coords.at(i);
    int smallest_distance = 1e9;
    F0R(j, N) {
      if (j == i) {
        continue;
      }
      //cout << "Looking at point j = " << j << endl;
      pi var = coords.at(j);
      if (current.second == var.second && var.first > current.first) {
        /* var is to the right of our point. */
        // cout << "In the first conditional" << endl;
        if (var.first - current.first < smallest_distance) {
          //cout << "Found a new closest point: j = " << j << endl;
          /* We've found a new next_on_right. */
          smallest_distance = var.first - current.first;
          next_on_right[i] = j;
        }
      }
    }
  }
}

// The following code is from StackOverflow. Not mine.
void generatePairings(int* items, int itemcount, int start) {
  if (itemcount & 1) return;  // must be an even number of items

  // is this a complete pairing?
  if (start == itemcount) {
    int i;
    //cout << "Now looking at permutation array " << endl;
    if (is_cycle(items)) {
      answer++;
    }
  }

  // for the next pair, choose the first element in the list for the
  // first item in the pair (meaning we don't have to do anything
  // but leave it in place), and each of the remaining elements for
  // the second item:
  int j;
  for (j = start + 1; j < itemcount; j++) {
    // swap start+1 and j:
    int temp = items[start + 1];
    items[start + 1] = items[j];
    items[j] = temp;

    // recurse:
    generatePairings(items, itemcount, start + 2);

    // swap them back:
    temp = items[start + 1];
    items[start + 1] = items[j];
    items[j] = temp;
  }
}

bool is_cycle(int* perm) {
  for (int start = 0; start < N; start++) {
    int walker = start;

    //cout << "Walker starts at " << walker << endl;
    for (int j = 0; j < N; j++) {
      if (next_on_right[walker] == -1) {
        //cout << "No neighbor on right. Breaking!\n" << endl;
        break;
      }
      walker = next_on_right[walker];
      //cout << "Walker just walked to " << walker << endl;
     /* if (walker == start) {
        return true;
      }*/

      int index_of_walker = -1;
      for (int i = 0; i < N; i++) {
        //cout << "i = " << i << ", perm[i] = " << perm[i] << endl;
        if (perm[i] == walker) {
          index_of_walker = i;
          break;
        }
      }
      //cout << "index_of_walker = " << index_of_walker << endl;

      if (index_of_walker & 1 && perm[index_of_walker] == walker) {
        /* Odd case. */
        //cout << "We're in Case 1" << endl;
        walker = perm[index_of_walker - 1];
      } else if (index_of_walker & 1 && perm[index_of_walker] != walker) {
        //cout << "We're in Case 2" << endl;
        /* Even case. */
        walker = perm[index_of_walker];
      } else if (!(index_of_walker & 1) && perm[index_of_walker] == walker) {
        //cout << "We're in Case 3" << endl;
        walker = perm[index_of_walker + 1];
      } else if (!(index_of_walker & 1) && perm[index_of_walker] != walker) {
        // cout << "We're in Case 4" << endl;
        walker = perm[index_of_walker];
      }
      // cout << "Walker just teleported to " << walker << endl;

      if (walker == start) {
        // cout << "True!" << endl;
        return true;
      }
    }
  }

  return false;
}
