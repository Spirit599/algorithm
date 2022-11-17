// 并查集

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        int fa[n + 1];
        memset(fa, -1, sizeof(fa));

        auto findFa = [&](int cur) -> int {

            while(fa[cur] != -1)
            {
                cur = fa[cur];
            }
            return cur;
        };

        for(auto& edge : edges)
        {
            int f1 = findFa(edge[0]);
            int f2 = findFa(edge[1]);
            if(f1 == f2)
                return edge;
            fa[f1] = f2;
        }
        return vector<int>();
    }
};