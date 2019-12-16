/* Written by Ekesh Kumar, Nov 17, 2019 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>

using namespace std;

int R, C;

struct Robot {
  int x, y;
  char pos;
  bool lost;
  Robot() : x(0), y(0) {
    lost = (x < 0 || y < 0 || x > R || y > C);
  };
  Robot(int a, int b, char c) : x(a), y(b), pos(c) {
    lost = (x < 0 || y < 0 || x > R || y > C);
  };
};


int main(void) {

    cin >> R >> C;
    set<pair<int, int>> isok;
    int posx, posy;
    char orientation;
    string seq;
    while (cin >> posx >> posy >> orientation >> seq) {
      Robot robot(posx, posy, orientation);
      int lastop = -1;
      for (int i = 0; i < seq.size(); i++) {
        if (seq[i] == 'L') {
          if (robot.pos == 'N') robot.pos = 'W';
          else if (robot.pos == 'W') robot.pos = 'S';
          else if (robot.pos == 'S') robot.pos = 'E';
          else if (robot.pos == 'E') robot.pos = 'N';
        } else if (seq[i] == 'R') {
          if (robot.pos == 'N') robot.pos = 'E';
          else if (robot.pos == 'E') robot.pos = 'S';
          else if (robot.pos == 'S') robot.pos = 'W';
          else if (robot.pos == 'W') robot.pos = 'N';
        } else if (seq[i] == 'F') {
          if (robot.pos == 'N') { robot.y += 1; lastop = 1; }
          if (robot.pos == 'S') { robot.y -= 1; lastop = 2; }
          if (robot.pos == 'E') { lastop = 3; robot.x += 1; }
          if (robot.pos == 'W') { robot.x -= 1; lastop = 4; }
        }

        if (robot.x < 0 || robot.y < 0 || robot.x > R || robot.y > C) {
          if (lastop == 4) robot.x += 1;
            else if (lastop == 2) robot.y += 1;
            else if (lastop == 3) robot.x -= 1;
            else if (lastop == 1) robot.y -= 1;

          if (isok.count(make_pair(robot.x, robot.y)) < 1) {
            isok.insert(make_pair(robot.x, robot.y));
            robot.lost = true;
            break;
          }
        }
      }
      cout << robot.x << " " << robot.y << " " << robot.pos;
      if (robot.lost) {
        cout << " LOST";
      }
      cout << endl;
  }

  return 0;
}
