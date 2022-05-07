#include <iostream>

using namespace std;

inline long long f(int t) {
	return 1ll * t * t + 2 * t + 3;
}

int main() {
	int t;
	cin >> t;
	long long res = f(f(f(t) + t) + f(f(t)));
	cout << res << endl;
}
