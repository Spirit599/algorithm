const int MAX_MN = 150;

class Solution {
public:
    int m = 0;
    int n = 0;
    bool ok = false;
    bool ok1 = false;
    bool ok2 = false;
    set<pair<int, int>> can_get;

    void dfs(int cur_i, int cur_j, vector<vector<int>>& heights, bool visit[MAX_MN][MAX_MN])
    {
        cout<<cur_i<<" "<<cur_j<<" "<<m<<" "<<n<<endl;

        if(ok)
        {
            return ;
        }

        if(can_get.count({cur_i, cur_j}) == 1)
        {
            ok = true;
            return ;
        }

        if(cur_i == 0 || cur_j == 0)
            ok1 = true;

        if(cur_i == m - 1 || cur_j == n - 1)
            ok2 = true;

        if(ok1 && ok2)
        {
            ok =  true;
            return;
        }

        int dires[] = {-1, 0, 1, 0, -1};

        for (int k = 0; k < 4; ++k)
        {
            int i = cur_i + dires[k];
            int j = cur_j + dires[k + 1];
            if(i >= 0 && i < m && j >= 0 && j < n && !visit[i][j] && heights[i][j] <= heights[cur_i][cur_j])
            {
                visit[i][j] = true;
                dfs(i, j, heights, visit);
                visit[i][j] = false;
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        bool visit[MAX_MN][MAX_MN];


        vector<vector<int>> ans;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ok = false;
                ok1 = false;
                ok2 = false;
                memset(visit, 0, sizeof(visit));
                visit[i][j] = true;
                cout<<"--------"<<endl;
                dfs(i, j, heights, visit);
                if(ok)
                {
                    ans.push_back({i, j});
                    can_get.insert({i, j});
                }
            }
        }

        return ans;
    }
};