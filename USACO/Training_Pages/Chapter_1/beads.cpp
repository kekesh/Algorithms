/* 
    USER: ekfrmd
    LANG: C++
    PROB: beads
*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <fstream>
using namespace std;
typedef long long ll;

int right_count(char beads[], int index);
int left_count(char beads[], int index);

char beads[351];
int N;

int main()
{
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    fin >> N;
    bool all_blue = true;
    bool all_red = true;
    for (int i = 0; i < N; i++)
    {
        char c;
        fin >> c;
        if (c == 'r')
        {
            all_blue = false;
        }
        if (c == 'b')
        {
            all_red = false;
        }
        beads[i] = c;
    }

    if (all_blue || all_red)
    {
        fout << N << endl;
    }
    else
    {

        int answer = 1;

        for (int i = 0; i < N; i++)
        {
            answer = max(answer, left_count(beads, i) + right_count(beads, i + 1));
        }

        fout << answer << endl;
    }
    return 0;
}

int right_count(char beads[], int index)
{

    int count = 0;
    char to_count = beads[index];
    //printf("To_count is %c\n", to_count);
    int i = index;
    while (to_count == 'w')
    {
        i++;
        to_count = beads[i % N];
    }

    char current = beads[index];

    while (current == to_count || current == 'w')
    {
        count++;
        index = (index + 1) % N;
        current = beads[index];
    }

    //printf("Right Count: %d\n", count);
    return count;
}

int left_count(char beads[], int index)
{

    int count = 0;
    char to_count = beads[index];
    int i = index;
    while (to_count == 'w')
    {
        i = (i - 1 + N) % N;
        to_count = beads[i];
    }
    //printf("To_count is %c\n", to_count);

    char current = beads[index];

    while (current == to_count || current == 'w')
    {
        count++;
        index = (index - 1 + N) % N;
        //printf("Index is %d\n", index);
        current = beads[index];
    }

    //printf("Left Count: %d\n", count);
    return count;
}
