#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool ispalin(string st) {
  for (int i = 0; i < st.size()/2; i++) {
    if (st[i] != st[st.size() - i - 1]) return false;
  }
  return true;
}

inline string formstring(string hrs, string mins) {
  string ret = "";
  if (hrs[0] == '0' && hrs[1] == '0' && mins[0] == '0') ret += mins[1];
  else if (hrs[0] == '0' && hrs[1] == '0') ret = mins;
  else if (hrs[0] == '0') ret += hrs[1] + mins;
  else ret += (hrs + mins);
  return ret;
}

int main() {
  long long N;
  cin >> N;
  while (N--) {
    string hrs, mins, input;
    cin >> input;

    hrs.push_back(input[0]);
    hrs.push_back(input[1]);
    mins.push_back(input[3]);
    mins.push_back(input[4]);

    do {
        int minint = stoi(mins);
        int hrsint = stoi(hrs);

        minint++;
        if (minint >= 60) {
          minint %= 60;
          hrsint++;
          if (hrsint >= 24) {
            hrsint %= 24;
          }
        }
        if (hrsint < 10) {
          hrs = "0" + to_string(hrsint);
        } else {
          hrs = to_string(hrsint);
        }
        if (minint < 10) {
          mins = "0" + to_string(minint);
        } else {
          mins = to_string(minint);
        }


    } while (!ispalin(formstring(hrs, mins)));
    // cout << "String: " << formstring(hrs, mins) << endl;
    cout << hrs << ":" << mins << endl;
  }
}

