#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    
    int n;
    cin >> n;
    
    vector<pii> edges[n + 1];
    int from;
    int to;
    int cost;
    for(int i = 0; i < n - 1; ++i)
    {
        cin>>from>>to>>cost;
        edges[from].emplace_back(to, cost);
        edges[to].emplace_back(from, cost);
    }

    int ans1 = 0;
    int maxx = 0;
    function<void(int, int, int)> dfs1 = [&](int fa, int cur, int cost) {

        ans1 += cost;
        maxx = max(maxx, cost);

        for(auto [next, c] : edges[cur])
        {
            if(fa == next)
                continue;
            dfs1(cur, next, cost + c);
        }
    };

    dfs1(-1, 1, 0);
    

    int ans2 = 0;

    function<void(int, int, int)> dfs2 = [&](int fa, int cur, int cost) {


        bool vis = false;
        for(auto [next, c] : edges[cur])
        {
            if(fa == next)
                continue;
            if(!vis)
            {
                vis = true;
                dfs2(cur, next, cost + c);
            }
            else
            {
                dfs2(cur, next, c);
            }
        }
        // cout<<cur<<" "<<cost<<endl;
        int edgeSize = edges[cur].size();
        if(edgeSize == 1)
            ans2 += 2 * cost;
    };
    dfs2(-1, 1, 0);

    cout<<ans1<<" "<<ans2 - maxx<<endl;

    return 0;
}
// 64 位输出请用 printf("%lld")