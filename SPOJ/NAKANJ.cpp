#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const vector<vector<int>> delta = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, 
																	 {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string from, to;
		cin >> from >> to;

		queue<pair<int, int>> q;
		unordered_map<string, int> d;
		pair<int, int> end = {to[0] - 'a', to[1] - '1'};
		string end_hash = to_string(end.first) + "," + to_string(end.second);
		d[to_string(from[0] - 'a') + "," + to_string(from[1] - '1')] = 0;

		q.push({from[0] - 'a', from[1] - '1'});
		while (!q.empty()) {
			auto curr = q.front(); q.pop();
			string curr_hash = to_string(curr.first) + "," + to_string(curr.second);
			if (curr.first == end.first && curr.second == end.second) break;

			for (int i = 0; i < 8; ++i) {
				pair<int, int> neighbor = {curr.first + delta[i][0], curr.second + delta[i][1]};
				if (neighbor.first < 0 || neighbor.second < 0 || neighbor.first >= 8 || neighbor.second >= 8) continue;
				string hash = to_string(neighbor.first) + "," + to_string(neighbor.second);

				if (d.find(hash) != d.end()) { continue; }
				d[hash] = d[curr_hash] + 1;
				q.push(make_pair(neighbor.first, neighbor.second));
			}
		}
		cout << d[end_hash] << endl;
	}
}
