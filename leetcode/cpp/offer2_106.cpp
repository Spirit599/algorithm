// 剑指 Offer II 106. 二分图

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        int flags[n];
        memset(flags, -1, sizeof(flags));

        for(int i = 0; i < n; ++i)
        {
            if(flags[i] != -1)
                continue;
            int curFlag = 0;
            flags[i] = 0;
            queue<int> que;
            que.push(i);
            // printf("i = %d\n", i);
            while(!que.empty())
            {
                curFlag = (curFlag + 1) % 2;
                int k = que.size();
                while(k--)
                {
                    int cur = que.front();
                    // printf("%d\n", cur);
                    que.pop();
                    for(int next : graph[cur])
                    {
                        if(flags[next] == -1)
                        {
                            flags[next] = curFlag;
                            que.push(next);
                        }
                        else if(flags[next] != curFlag)
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};