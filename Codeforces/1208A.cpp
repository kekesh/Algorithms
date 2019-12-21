#include <iostream>

using namespace std;

long long solve(int a, int b, int n) {
	if (n % 3 == 0) return a;
	else if (n % 3 == 1) return b;
	else if (n % 3 == 2) return (a^b);
}


int main(void) {

	long long T;
	cin >> T;
	while (T--) {
		long long a, b, n;
		cin >> a >> b >> n;
		cout << solve(a, b, n) << endl;
	}

}
