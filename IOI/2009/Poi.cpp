#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Contestant {
  int score;
  int problems_solved;
  int id_number;

  Contestant(int x, int y, int z) : score(x), problems_solved(y), id_number(z) {}
};

bool contestant_sorter(Contestant const & lhs, Contestant const & rhs) {
    if (lhs.score != rhs.score) {
      return lhs.score >= rhs.score;
    }
    if (lhs.problems_solved != rhs.problems_solved) {
      return lhs.problems_solved >= rhs.problems_solved;
    }
    return rhs.id_number >= lhs.id_number;
  }


int main() {
  ll N, T, P;
  cin >> N >> T >> P;

  vector<vector<int>> scores(N+1, vector<int>(T + 1, 0));

  int point_value[T + 1];

  for (int i = 0; i < T; i++) {
    point_value[i] = N;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < T; j++) {
      cin >> scores[i][j];
      if (scores[i][j] == 1) {
        point_value[j] -= 1;
      }
    }
  }


  vector<Contestant> rankings;

  int target = 0;
  for (int i = 1; i <= N; i++) {
    int score = 0;
    int problems_solved = 0;
    for (int j = 0; j < T; j++) {
      if (scores[i - 1][j] == 1) {
        score += point_value[j];
        problems_solved++;
      }
    }
    Contestant p(score, problems_solved, i);

    rankings.push_back(p);
  }

  sort(rankings.begin(), rankings.end(), &contestant_sorter);

  // could binary search if TLE.
  for (int i = 1; i <= rankings.size(); i++) {
    if (rankings[i - 1].id_number == P) {
      cout << rankings[i - 1].score << " " << i << endl;
      exit(0);
    }
  }


}
