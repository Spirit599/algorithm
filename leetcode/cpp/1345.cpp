class Solution {
public:
    int minJumps(vector<int>& arr) {

        unordered_map<int, vector<int>> occurIndex;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
            occurIndex[arr[i]].emplace_back(i);

        int vis[n];
        memset(vis, 0, sizeof(vis));
        queue<int> que;
        que.emplace(0);
        vis[0] = true;

        int clock = 0;
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int cur = que.front();
                if(cur == n - 1)
                    return clock;
                que.pop();
                if(cur + 1 < n && !vis[cur + 1])
                {
                    vis[cur + 1] = true;
                    que.emplace(cur + 1);
                }
                if(cur - 1 >= 0 && !vis[cur - 1])
                {
                    vis[cur - 1] = true;
                    que.emplace(cur - 1);
                }
                for(int next : occurIndex[arr[cur]])
                {
                    if(!vis[next])
                    {
                        vis[next] = true;
                        que.emplace(next);
                    }
                }
                occurIndex[arr[cur]].clear();
            }
            ++clock;
        }

        return -1;
        
    }
};