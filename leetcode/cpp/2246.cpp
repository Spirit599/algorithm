class Solution {
public:
    int longestPath(vector<int>& parent, string s) {

        int root = -1;
        int n = parent.size();
        vector<int> edges[n];
        for(int i = 0; i < n; ++i)
        {
            if(parent[i] == -1)
            {
                root = i;
            }
            else
            {
                edges[parent[i]].push_back(i);
            }
        }

        int ans = 0;
        function<int(int)> dfs = [&](int curNode) -> int {
            

            int fisrtMax = 0;
            int secondMax = 0;
            for(int next : edges[curNode])
            {
                int ret = dfs(next);
                if(s[curNode] == s[next])
                    continue;
                if(ret > fisrtMax)
                {
                    secondMax = fisrtMax;
                    fisrtMax = ret;
                }
                else if(ret > secondMax)
                {
                    secondMax = ret;
                }
            }
            //printf("%d %d %d\n", curNode, fisrtMax, secondMax);
            ans = max(ans, fisrtMax + secondMax + 1);
            return fisrtMax + 1;
        };

        dfs(root);

        return ans;
    }
};