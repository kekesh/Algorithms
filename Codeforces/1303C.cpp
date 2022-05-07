#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>>& AdjList, vector<int>& vis, int u, string& path) {
	vis[u] = true;
	path += string(1, static_cast<char>(u + 'a'));
	for (int i = 0; i < AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (!vis[v]) {
			dfs(AdjList, vis, v, path);
		} 
	}
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		if (s.size() == 1) {
			cout << "YES" << endl;
			for (int i = 0; i < 26; ++i) {
				auto c = static_cast<char>(i + 'a');
				if (c != s[0]) cout << c;
			}
			cout << s << endl;
			continue;
		}

		const int n = s.size();
		vector<vector<int>> AdjList(26);
		unordered_set<string> edges;
		bool bad = false;

		for (int i = 1; i < n && !bad; ++i) {
			string edge1 = string(1, s[i - 1]) + "," + string(1, s[i]);
			string edge2 = string(1, s[i]) + "," + string(1, s[i - 1]);
			if (edges.find(edge1) != edges.end()) {
				continue;
			}
			edges.insert(edge1);
			edges.insert(edge2);

			AdjList[s[i - 1] - 'a'].push_back(s[i] - 'a');
			AdjList[s[i] - 'a'].push_back(s[i - 1] - 'a');
			bad |= AdjList[s[i - 1] - 'a'].size() > 2;
			bad |= AdjList[s[i] - 'a'].size() > 2;
		}

		int src = -1;
		for (int i = 0; i < 26; ++i) {
			if (AdjList[i].size() == 1) {
				src = i;
				break;
			}
		}

		if (bad || src == -1) {
			cout << "NO" << endl;
			continue;
		}
		string path;
		vector<int> vis(26); 
		dfs(AdjList, vis, src, path);

		for (int i = 0; i < 26; ++i) {
			if (!AdjList[i].size()) {
				path += string(1, static_cast<char>('a' + i));
			}
		}

		cout << "YES" << endl;
		cout << path << endl;
	}
}
