class Solution {
public:
    int minJump(vector<int>& jump) {

        int n = jump.size();
        int maxGet = 0;
        queue<int> que;
        que.emplace(0);
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        vis[0] = true;
        int depth = 0;

        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int cur = que.front();
                que.pop();

                int next = cur + jump[cur];
                if(next >= n)
                    return depth + 1;
                else
                {
                    if(!vis[next])
                    {
                        vis[next] = true;
                        que.emplace(next);

                    }
                }
                
                for(int i = maxGet + 1; i < cur; ++i)
                {
                    if(!vis[i])
                    {
                        vis[i] = true;
                        que.emplace(i);
                    }
                }
                maxGet = max(maxGet, cur);
            }
            
            ++depth;
        }

        return -1;
    }
};