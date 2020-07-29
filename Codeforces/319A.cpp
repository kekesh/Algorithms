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
 
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ld> vld;
typedef vector<pair<ll, ll>> vpl;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

// Function to return the value of (str % k)  
long long getMod(string str, int n, int k)  
{  
  
    // pwrTwo[i] will store ((2^i) % k)  
    long long pwrTwo[n];  
    pwrTwo[0] = 1 % k;  
    for (int i = 1; i < n; i++)  
    {  
        pwrTwo[i] = pwrTwo[i - 1] * (2 % k);  
        pwrTwo[i] %= k;  
    }  
  
    // To store the result  
    long long res = 0;  
    int i = 0, j = n - 1;  
    while (i < n)  
    {  
  
        // If current bit is 1  
        if (str[j] == '1')  
        {  
  
            // Add the current power of 2  
            res += (pwrTwo[i]);  
            res %= k;  
        }  
        i++;  
        j--;  
    }  
    return res;  
}  

long long modpow(ll a, ll b) {
		long long res = 1;
		a %= MOD;

		while (b) {
				if (b & 1) {
						res = (res * a) % MOD;
				}
				a = (a * a) % MOD;
				b >>= 1;
		}
		return res;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		string s;
		cin >> s;
		long long len = s.size();
		long long n = getMod(s, len, MOD);
		long long ans = (n * modpow(2, len - 1)) % MOD;
		cout << ans << endl;
}
