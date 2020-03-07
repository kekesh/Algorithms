#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>


typedef long long ll;

using namespace std;


vector<string> split(const string &s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}


int main() {

  ll N;
  bool isfirst = true;
  while (cin >> N) {
    if (!isfirst) cout << "\n";
    isfirst = false;
    string people[15];
    unordered_map<string, int> money_map;

    for (int i = 0; i < N; i++) {
      cin >> people[i];
      money_map[people[i]] = 0;
    }

    for (int i = 0; i < N; i++) {
      string giver;
      int amount, num_receiving;
      cin >> giver >> amount >> num_receiving;

      if (num_receiving != 0) {
        money_map[giver] += (amount % num_receiving);
        money_map[giver] -= amount;
        amount -= (amount % num_receiving);
      }
      for (int j = 0; j < num_receiving; j++) {
        string receiving;
        cin >> receiving;
        if (num_receiving != 0) { money_map[receiving] += amount/num_receiving; }
      }
    }

    for (int i = 0; i < N; i++) {
      cout << people[i] << " " << money_map[people[i]] << endl;
    }

  }


}
