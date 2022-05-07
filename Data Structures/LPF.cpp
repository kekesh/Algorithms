#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;


// lpf sieve
template<int N>
class LPF {
	private:
		vector<long long> lpf;
	
	public:
		LPF() {
			lpf.resize(N + 1);
			iota(lpf.begin(), lpf.end(), 0);

			for (int i = 2; i <= N; ++i) {
				if (lpf[i] == i) {
					for (int j = i * i; j <= N; j += i) {
						if (lpf[j] == j) {
							lpf[j] = i;
						}
					}
				}
			}
		}

		long long operator[](size_t idx) {
			return lpf[idx];
		}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LPF<2001> lpf;
}
