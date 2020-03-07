
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

typedef long long ll;

#define F0R(i, a) for (int i = 0; i < (a); i++)


ll T;

bool globalseen[50001];
bool localseen[50001];
int cnt;
void dfs(int u, const vector<ll>& Adj) {
 // cout << "DFS FROM " << u << endl;
  cnt++;
  globalseen[u] = localseen[u] = true;
  int v = Adj[u];
  if (!localseen[v]) dfs(v,Adj);
}

int j;
int main() {
  cin >> T;
  while (T--) {
   // memset(dp,-1,sizeof(dp));
    memset(globalseen,false,sizeof(globalseen));
    ll N;
    cin >> N;
    vector<ll> Adj(N);
    F0R(i, N) {
       ll from, to;
       cin >> from >> to;
       from--;
       to--;
       Adj[from] = to;
    }
    ll maxi = -1;
    ll len = -1;
    F0R(i, N) {
      //if (!seen[i]){
      if (!globalseen[i]) {
        cnt = 0;
        dfs(i,Adj);
        if (cnt > len) {
          len = cnt;
          maxi = i;
       // }
        }
         memset(localseen, false, sizeof(localseen));
      }
    }
   /* F0R(i,N){
      cout << "len(" << i << ") = " << dp[i] << endl;
    }*/

    cout << "Case " << ++j << ": " << maxi + 1 << endl;

  }
}
