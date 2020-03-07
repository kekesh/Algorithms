#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	long long T;

	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		cout << (m ^ (m >> 1)) << endl;
	}

	return 0;

}
