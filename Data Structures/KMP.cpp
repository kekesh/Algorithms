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

struct KMP {
	string pattern;
	int n;
	vector<int> pi;

	KMP(const string& s) {
		pattern = s;
		n = s.size();
		pi.resize(n);

		for (int i = 1; i < n; ++i) {
			int j = pi[i - 1];
			while (j > 0 && s[i] != s[j]) {
				j = pi[i - 1];
			}
			j += s[i] == s[j];
			pi[i] = j;
		}
	}	

	int query(const string& s) {
		int i = 0, j = 0;
		const int m = s.size();
		while (i < n) {
			if (s[i] == pattern[j]) {
				i++, j++;
			}
			if (j == m) {
				return i - j;
			}
			if (i < n && s[i] != pattern[j]) {
				j ? j = pi[j - 1] : i++;
			}
		}
		return -1;
	}
};
 
int main() {
	KMP k("ll");
	cout << k.query("hello") << endl;
}
