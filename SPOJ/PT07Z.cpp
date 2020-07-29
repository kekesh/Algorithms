#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>
 
using namespace std;

typedef long long ll;

int bfs(const vector<vector<int>>& AdjList, bool second = false, int src = 0) {
		queue<int> q;
		q.push(src);
		vector<int> d((int) AdjList.size(), 2000000000);
		d[src] = 0;

		int furthest = -1;
		int largest = -1;

		while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int i = 0; i < (int) AdjList[u].size(); i++) {
						int v = AdjList[u][i];
						if (d[v] == 2000000000) {
								d[v] = d[u] + 1;
								if (largest < d[v]) {
										furthest = v;
										largest = d[v];
								}
								q.push(v);
						}
				}
		}

		return second ? largest : bfs(AdjList, true, furthest);
}


int main() {
		ll N;
		cin >> N;
		vector<vector<int>> AdjList(N);
		for (int i = 0; i < N - 1; i++) {
				ll u, v;
				cin >> u >> v;
				AdjList[u - 1].push_back(v - 1);
				AdjList[v - 1].push_back(u - 1);
		}
		cout << bfs(AdjList) << endl;
}


