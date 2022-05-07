#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class UF {
	private:
		vector<long long> parent, rank;
		vector<long long> mini, maxi, cnt;
	
	public:
		UF(const int n) {
			parent.resize(n + 1);
			rank.resize(n + 1);
			maxi.resize(n + 1);
			mini.resize(n + 1);
			cnt.resize(n + 1, 1);

			iota(maxi.begin(), maxi.end(), 0);
			iota(parent.begin(), parent.end(), 0);
			iota(mini.begin(), mini.end(), 0);
		}
		
		int findSet(const int u) {
			return (parent[u] == u ? u : parent[u] = findSet(parent[u]));
		}

		bool inSameSet(const int u, const int v) {
			return findSet(u) == findSet(v);
		}

		void unionSet(const int u, const int v) {
			int p1 = findSet(u), p2 = findSet(v);

			if (p1 == p2) return;

			if (rank[p1] > rank[p2]) {
				parent[p2] = p1;

				mini[p1] = min(mini[p2], mini[p1]);
				maxi[p1] = max(maxi[p2], maxi[p1]);
				cnt[p1] += cnt[p2];
			} else {
				parent[p1] = p2;
				rank[p2] += (rank[p1] == rank[p2]);
				mini[p2] = min(mini[p2], mini[p1]);
				maxi[p2] = max(maxi[p2], maxi[p1]);
				cnt[p2] += cnt[p1];
			}
		}

		void query(int v) {
			int u = findSet(v);
			printf("%lld %lld %lld\n", mini[u], maxi[u], cnt[u]);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	scanf("%lld %lld", &n, &m);
	char query[10];
	UF a(n);
	for (long long q = 0, u, v; q < m; ++q) {
		scanf("%s", query);
		if (query[0] == 'u') {
			scanf("%lld%lld", &u, &v);
			a.unionSet(u, v);
		} else {
			scanf("%lld", &u);
			a.query(u);
		}
	}
}
