class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int n = status.size();
        bool haveBox[n];
        memset(haveBox, 0, sizeof(haveBox));
        bool haveKey[n];
        memset(haveKey, 0, sizeof(haveKey));
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; ++i)
            haveKey[i] = (status[i] == 1);

        int ans = 0; 
        queue<int> que;
        for(int box : initialBoxes)
        {
            haveBox[box] = true;
            if(haveKey[box])
            {
                que.emplace(box);
                vis[box] = true;
                ans += candies[box];
            }
        }

        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for(int box : keys[cur])
            {
                haveKey[box] = true;
                if(!vis[box] && haveBox[box])
                {
                    que.emplace(box);
                    vis[box] = true;
                    ans += candies[box];
                }
            }

            for(int box : containedBoxes[cur])
            {
                haveBox[box] = true;
                if(!vis[box] && haveKey[box])
                {
                    que.emplace(box);
                    vis[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
};