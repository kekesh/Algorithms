#include <iostream>
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
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define pow(a, b) ceil(pow(a, b))
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

char grid[10][15];
bool visited[10][15];
int dr[] = { 1, 0, 0, -1 };
int dc[] = { 0, -1, 1, 0 };

int floodfill(int r, int c, char c1, char c2)
{
    if (r < 0 || c < 0 || r >= 10 || c >= 15)
        return 0;
    if (grid[r][c] != c1)
        return 0;
    visited[r][c] = true;
    int ans = 1;
    grid[r][c] = c2;
    F0R(i, 4)
    ans += floodfill(r + dr[i], c + dc[i], c1, c2);
    return ans;
}

void shiftdown()
{
    FOR(i, 1, 10)
    {
        F0R(j, 15)
        {
            if (grid[i][j] == '.' && grid[i - 1][j] != '.') {
                swap(grid[i][j], grid[i - 1][j]);
            }
        }
    }
}

void shiftallleft()
{
    bool anyempty = false;
    for (int col = 0; col < 14; col++) {
        bool isempty = true;
        for (int row = 0; row < 10; row++) {
            if (grid[row][col] != '.') {
                isempty = false;
                break;
            }
        }
        if (isempty) {
            for (int rowp = 0; rowp < 10; rowp++) {
                if (grid[rowp][col] != '.' || grid[rowp][col + 1] != '.')
                    anyempty = true;
                swap(grid[rowp][col], grid[rowp][col + 1]);
            }
        }
        if (anyempty)
            shiftallleft();
    }
}

int main()
{
    int T;
    cin >> T;
    getchar();
    int j = 0;
    while (T--) {
        cout << "Game " << ++j << ":" << endl;
        cout << endl;

        for (int i = 0; i < 10; i++) {
            cin >> grid[i];
        }
        bool isok = true;
        int j = 0;
        ll points = 0;
        ll ballsremaining = 0;
        while (isok) {
            memset(visited, false, sizeof(visited));

            // are we done yet?
            isok = false;
            int redc, bluec, greenc;
            redc = bluec = greenc = 0;

            F0R(i, 10)
            {
                F0R(j, 15)
                {
                    if (grid[i][j] == 'R')
                        redc++;
                    else if (grid[i][j] == 'G')
                        greenc++;
                    else if (grid[i][j] == 'B')
                        bluec++;
                }
            }
            isok = (redc > 1 || bluec > 1 || greenc > 1);
            if (!isok) {
                ballsremaining = redc + bluec + greenc;
                break;
            }

            int max_order = -1;
            int r, c;
            r = c = -1;

            for (int col = 0; col < 15; col++) {
                for (int row = 9; row >= 0; row--) {
                    if (!visited[row][col] && grid[row][col] != '.') {
                        char prev = grid[row][col];
                        int ff = floodfill(row, col, grid[row][col], '*');
                        floodfill(row, col, '*', prev); // put it back.
                        if (max_order < ff) {
                            max_order = ff;
                            r = row;
                            c = col;
                        }
                    }
                }
            }

            if (max_order < 2) {
                ballsremaining = redc + bluec + greenc;
                break;
            }

            cout << "Move " << ++j << " at (" << 10 - r << "," << c + 1 << "): removed " << max_order << " balls of color " << grid[r][c] << ", got " << (max_order - 2) * (max_order - 2) << " points." << endl;
            points += (max_order - 2) * (max_order - 2);

            floodfill(r, c, grid[r][c], '.');

            F0R(i, 10)
            shiftdown();
            shiftallleft();
        }
        if (ballsremaining == 0)
            points += 1000;
        cout << "Final score: " << points << ", with " << ballsremaining << " balls remaining." << endl;

        if (T)
            cout << endl;
    }
}
