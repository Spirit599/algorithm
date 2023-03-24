#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> edges[n + 1];

    int x,y;
    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    vector<int> time1(n + 1);
    vector<int> time2(n + 1);

    function<void(int, int, int, vector<int>&)> dfs = [&](int fa, int cur, int curTime, vector<int>& time) -> void {

        time[cur] = curTime;
        for(int next : edges[cur])
        {
            if(next == fa)
                continue;
            dfs(cur, next, curTime + 1, time);
        }
    };

    dfs(-1, a, 0, time1);
    dfs(-1, b, 0, time2);
    int ans = 0;

    for(int i = 1; i <= n; ++i)
    {
        if(time1[i] >= time2[i])
            ans = max(ans, time1[i]);
        // else
        //     ans = max(ans, )
    }
    cout<<ans<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")