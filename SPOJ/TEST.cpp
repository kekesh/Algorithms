#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int x = 0;

    while (x != 42) {
      cin >> x;
      if (x != 42) {
	printf("%d\n", x);
      } 
    }

    return 0;
}
