#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

typedef long long ll;

using namespace std;


int st_to_sum(string s) {
  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      sum += s[i] - 96;
    }
  }
  return sum;

}

int f(int n) {
  int sum = 0;
  while (n > 0) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}

int g(int n) {
  while (n >= 10) {
    n = f(n);
  }
  return n;
}



int main() {

  string s1, s2;

  while (getline(cin, s1), getline(cin, s2)) {

    for (int i = 0; i < s1.size(); i++) {
      if (isalpha(s1[i])) {
        s1[i] = tolower(s1[i]);
      }
    }

    for (int i = 0; i < s2.size(); i++) {
      if (isalpha(s2[i])) {
        s2[i] = tolower(s2[i]);
      }
    }


    int x = g(st_to_sum(s1));
    int y = g(st_to_sum(s2));

    float ans = 100;
    if (x > y) {
      ans = ((float)y/x)*100;
    } else {
      ans = ((float)x/y)*100;
    }

    printf("%.2f %%\n", ans);

  }
  return 0;
}
