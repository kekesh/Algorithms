#include <iostream>
#include <vector>

using namespace std;

void merge(vector<long long>& a, int l, int m, int r) {
	int i = l, j = m + 1, k = 0;

	vector<long long> C(r - l + 1);
	while (i <= m && j <= r) {
		C[k++] = (a[i] <= a[j] ? a[i++] : a[j++]);
	}

	while (i <= m) C[k++] = a[i++];
	while (j <= r) C[k++] = a[j++];

	for (int i = l; i <= r; ++i) {
		a[i] = C[i - l];
	}

}



void mergesort(vector<long long>& a, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge(a, l, m, r);
	}
}


int main() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mergesort(a, 0, a.size() - 1);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << endl;
	}
}
