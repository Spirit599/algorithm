class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        int n = vals.size();
        vector<int> edgess[n];

        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(vals[edge[1]]);
            edgess[edge[1]].emplace_back(vals[edge[0]]);
        }

        int ans = vals[0];

        for(int i = 0; i < n; ++i)
        {
            int val = vals[i];
            vector<int> path = edgess[i];
            if(k != 0)
            {
                nth_element(path.begin(), path.begin() + min(k - 1, (int)path.size()), path.end(), greater<int>());
                
                int m = path.size();
                m = min(m, k);
                for(int j = 0; j < m; ++j)
                {
                    if(path[j] > 0)
                        val += path[j];
                }
            }
            ans = max(ans, val);
        }

        return ans;

    }
};