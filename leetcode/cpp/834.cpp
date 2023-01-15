// 树形DP
// 换根

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<int> ans(n);
        int sonNum[n];
        vector<int> edgess[n];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1]);
            edgess[edge[1]].emplace_back(edge[0]);
        }

        function<pair<int, int>(int, int)> dfs = [&](int fa, int cur) -> pair<int, int> {

            pair<int, int> ret = make_pair(0, 1);
            for(int next : edgess[cur])
            {
                if(fa != next)
                {
                    pair<int, int> tmp = dfs(cur, next);
                    ret.first += tmp.first + tmp.second;
                    ret.second += tmp.second;
                }
            }
            sonNum[cur] = ret.second;
            return ret;
        };

        function<void(int, int)> dfs1 = [&](int fa, int cur) {

            if(cur != 0)
                ans[cur] = (ans[fa] + n - 2 * sonNum[cur]);
            for(int next : edgess[cur])
            {
                if(fa != next)
                {
                    dfs1(cur, next);
                }
            }
        };

        ans[0] = dfs(-1, 0).first;

        dfs1(0, 0);


        return ans;
    }
};