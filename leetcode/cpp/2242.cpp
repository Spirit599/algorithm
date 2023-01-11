class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        
        int n = scores.size();
        vector<pair<int, int>> edgess[n];

        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(scores[edge[1]], edge[1]);
            edgess[edge[1]].emplace_back(scores[edge[0]], edge[0]);
        }

        for(int i = 0; i < n; ++i)
        {
            auto& vv = edgess[i];
            if(vv.size() > 3)
            {
                nth_element(vv.begin(), vv.begin() + 2, vv.end(), greater<>());
                vv.resize(3);
            }
        }

        int ans = -1;
        for(auto& edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            for(auto [scorea, a] : edgess[x])
            {
                for(auto [scoreb, b] : edgess[y])
                {
                    if(a != y && b != x && a != b)
                    {
                        ans = max(ans, scorea + scoreb + scores[x] + scores[y]);
                    }
                }
            }
        }

        return ans;
    }
};