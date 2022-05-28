#include <bits/stdc++.h>
 
using namespace std;
using LL = long long;
const int MOD = 998244353;
 
void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> all(n + 1), low(n + 1);
    all[0] = low[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= min(k, i); j ++ )
        {
            all[i] = (all[i] + all[i - j]) % MOD;
            cout<<i<<" "<<all[i]<<endl; 
        }
        for (int j = 1; j <= min(d - 1, i); j ++ )
            low[i] = (low[i] + low[i - j]) % MOD;       
    }
    int ans = (all[n] - low[n]) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t -- )
        solve();
    return 0;
}