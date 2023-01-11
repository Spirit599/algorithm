class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> edges[n + 1];
        time.insert(time.begin(), 0);

        int indegress[n + 1];
        memset(indegress, 0, sizeof(indegress));
        for(auto& relation : relations)
        {
            edges[relation[0]].emplace_back(relation[1]);
            ++indegress[relation[1]];
        }

        int startTime[n + 1];
        memset(startTime, 0, sizeof(startTime));

        queue<pair<int, int>> que;
        for(int i = 1; i <= n; ++i)
        {
            if(indegress[i] == 0)
                que.emplace(i, 0);
        }

        int ans = 0;

        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                auto [cur, curTime] = que.front();
                ans = max(ans, curTime + time[cur]);
                que.pop();

                for(int next : edges[cur])
                {
                    --indegress[next];
                    startTime[next] = max(startTime[next], curTime + time[cur]);
                    if(indegress[next] == 0)
                        que.emplace(next, startTime[next]);
                }
            }
        }

        return ans;
    }
};