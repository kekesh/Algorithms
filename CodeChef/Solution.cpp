#include <bits/stdc++.h>
 
#define int long long
#define mod 1000000007
#define endl "\n"

using namespace std;

ofstream fout("output.out");

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
 
    while(t--)
    {
        int n,k;
        cin >> n >> k;
 
        if(n == 0)
        {
            fout << (k*(k-1))%mod << endl;
            continue;
        }
 
        int ans = n*n;
        ans %= mod;
        ans += 2*(k/2)*n;
        ans %= mod;
        k = (k+1)/2;
        ans += k*(k-1);
        ans %= mod;
 
        fout << ans << endl;
    }
} 
