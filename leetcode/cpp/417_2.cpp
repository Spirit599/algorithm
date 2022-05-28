class Solution {
private:
    int x;
    int y;
    int cur_status;
    int flag[205][205];
    bool visit[205][205];
    const int PACIFIC = 1 << 0;
    const int ATLANTIC = 1 << 1;
public:

    bool dfs(int cur_i, int cur_j, vector<vector<int>>& heights)
    {
        bool ret = false;
        //printf("%d %d\n",y,x);
 
            
        cur_status |= flag[cur_i][cur_j];
        //printf("%d %d %d\n", cur_status, cur_i, cur_j);
        if((cur_status & ATLANTIC) && (cur_status & PACIFIC))
        {
            return true;
        }

        int dires[5] = {-1, 0, 1, 0, -1};
        for(int k = 0; k < 4; ++k)
        {
            int i = cur_i + dires[k];
            int j = cur_j + dires[k + 1];
            if(i >= 0 && i < y && j >= 0 && j < x && 
                heights[i][j] <= heights[cur_i][cur_j] && !ret && !visit[i][j])
            {
                visit[i][j] = true;
                if(dfs(i, j, heights))
                    ret = true;
                visit[i][j] = false;
            }
        }
        

        return ret;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> ans;
        y = heights.size();
        x = heights[0].size();
        memset(visit, 0, sizeof(visit));

        for(int i = 0; i < x; ++i)
        {
            flag[0][i] |= PACIFIC;
            flag[y - 1][i] |= ATLANTIC;
        }
        for(int i = 0; i < y; ++i)
        {
            flag[i][0] |= PACIFIC;
            flag[i][x - 1] |= ATLANTIC;
        }
        for(int i = 0; i < y; ++i)
        {
            for(int j = 0; j < x; ++j)
            {
                cur_status = 0;
                //memset(visit, 0, sizeof(visit));
                visit[i][j] = true;

                if(dfs(i ,j, heights))
                {
                    ans.push_back({i, j});
                }
            }   
        }
        //dfs(0,0,4,heights);

        return ans;

    }
};