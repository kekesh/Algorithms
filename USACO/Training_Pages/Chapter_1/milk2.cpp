/* ID: ekfrmd1
   LANG: C++
   TASK: milk2
*/
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

void init();
void solve1();
void solve2();

ifstream fin("milk2.in");
ofstream fout("milk2.out");

int N;
set<pi> intervals;

int main() {
  fin >> N;
  init();
  solve1();
  solve2();
}

void init() {
  int x, y;
  for (int i = 0; i < N; i++) {
    fin >> x >> y;
    intervals.insert(make_pair(x, y));
  }
}

/* Gets longest run. */
void solve1() {
  if (N <= 0) {
    return;
  }

  int max, current, start, end;
  set<pi>::iterator itr = intervals.begin();
  start = (*itr).first, end = (*itr).second;
  current = max = (end - start);

  for (set<pi>::iterator it = next(intervals.begin(), 1); it != intervals.end();
       it++) {
    if ((*it).first <= end) {
      /* If we get here, we can merge the two intervals. */
      end = MAX(end, (*it).second);
      current = end - start;
      if (max < current) {
        max = current;
      }
    } else {
      /* We've hit a disjoint interval. */
      start = (*it).first;
      end = (*it).second;
      current = end - start;
    }
  }
  fout << max << " ";
}

void solve2() {
  if (N <= 0) {
    return;
  }
  set<pi>::iterator itr = intervals.begin();
  int max, current, start, end;
  start = 0;
  max = current = 0;
  end = (*itr).second;

  for (set<pi>::iterator it = next(intervals.begin(), 1); it != intervals.end();
       ++it) {
    if ((*it).first > end) {
      /* We've found a disjoint interval. */
      current = (*it).first - end;
      if (max < current) {
        max = current;
      }
      end = (*it).second;
    } else {
      /* Do nothing. */
      end = MAX(end, (*it).second);
    }
  }
  fout << max << endl;
}