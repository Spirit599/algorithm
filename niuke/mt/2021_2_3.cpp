#include <bits/stdc++.h>
using namespace std;



int main() {
    int m;
    cin >> m;

    int idx = 0;
    string from;
    string to;
    unordered_map<string, int> toIdx;
    vector<int> edges[10005];
    vector<pair<int, int>> paths;
    while(m--)
    {
        cin >> from >> to;
        if(toIdx.count(from) == 0)
            toIdx[from] = idx++;
        if(toIdx.count(to) == 0)
            toIdx[to] = idx++;

        edges[toIdx[from]].push_back(toIdx[to]);
        // paths.emplace_back(toIdx[from], toIdx[to]);
    }

    int n = idx;
    bool vis[n];
    memset(vis, 0, sizeof(vis));

    function<int(int)> dfs = [&](int cur) -> int {

        int ret = 0;
        if(vis[cur])
            ++ret;
        vis[cur] = true;
        while(edges[cur].size() != 0)
        {
            int next = edges[cur].back();
            edges[cur].pop_back();
            ret += dfs(next);
        }
        return ret;
    };

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        while(edges[i].size() != 0)
        {
            memset(vis, 0, sizeof(vis));
            ans += dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
    
}
// 64 位输出请用 printf("%lld")