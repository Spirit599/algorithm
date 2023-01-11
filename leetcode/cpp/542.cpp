class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int dires[] = {-1, 0, 1, 0, -1};

        
        queue<pair<int, int>> que;
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


        int depth = 1;
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(int d = 0; d < 4; ++d)
                {
                    int i = x + dires[d];
                    int j = y + dires[d + 1];
                    if(i < 0 || i >= m || j < 0 || j >= n || ans[i][j] != -1)
                        continue;
                    ans[i][j] = depth;
                    que.push(make_pair(i, j));
                }

            }
            ++depth;
        }


        return ans;

    }
};