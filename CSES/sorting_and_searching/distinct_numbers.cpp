#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<long long> s;
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << endl;
}
