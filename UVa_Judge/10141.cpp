#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <fstream>
#include <algorithm>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))

typedef long long ll;

using namespace std;


struct Proposal {
  string name;
  double compliance;
  double price;
  Proposal(string a, double x, double y) : name(a), compliance(x), price(y) { }
};

bool compare_proposal(const Proposal& lhs, const Proposal& rhs) {

  if (abs(lhs.compliance - rhs.compliance) > 0.0005) {
    return lhs.compliance > rhs.compliance;
  } else {
    return lhs.price < rhs.price;
  }

  return true;
}


int main() {
  ll n, p;
  bool isfirst = true;
  int z = 0;
  while (cin >> n >> p) {
    if (!n && !p) break;
    if (!isfirst) cout << "\n";
    isfirst = false;
    string reqs[1005];
    getchar();


    for (int i = 0; i < n; i++) {
      string st;
      getline(cin, st);
      reqs[i] = st;
    }


    vector<Proposal> proposals;
    for (int i = 0; i < p; i++) {
      string prop;
      double price;
      double num_req_met;
      getline(cin, prop);
      cin >> price >> num_req_met;
      Proposal p(prop, num_req_met/n, price);
      proposals.push_back(p);
      string trash;
      getline(cin, trash);
      for (int j = 0; j < num_req_met; j++) {
        getline(cin, trash);
      }
    }

    sort(proposals.begin(), proposals.end(), compare_proposal);

    int X = proposals.size();

    cout << "RFP #" << ++z << endl;
    cout << proposals[0].name << endl;
  }
}
