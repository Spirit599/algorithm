// 剑指 Offer II 107. 矩阵中的距离

typedef pair<int, int> pii;

int dires[] = {-1, 0, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pii> que;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(mat[i][j] == 0)
                {
                    que.push(make_pair(i, j));
                    ans[i][j] = 0;
                }
            }
        }

        int depth = 0;
        while(!que.empty())
        {
            ++depth;
            int k = que.size();
            while(k--)
            {
                pii cur = que.front();
                //printf("%d %d | ", cur.first, cur.second);
                que.pop();
                for(int l = 0; l < 4; ++l)
                {
                    int i = cur.first + dires[l];
                    int j = cur.second + dires[l + 1];
                    if(i < 0 || i >= m || j < 0 || j >= n || ans[i][j] != -1)
                        continue;

                    que.push(make_pair(i, j));
                    ans[i][j] = depth;
                    
                }
            }
        }

        return ans;
    }
};