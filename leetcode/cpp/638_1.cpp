//dfs 深度优先
//礼包 捆绑
//可重复选 注意要有index，i从index开始

class Solution {
private:
    int ans = 0x7fffffff;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {


        int n = price.size();
        for (int i = 0; i < n; ++i)
        {
            vector<int> special_single(n + 1);
            special_single[n] = price[i];
            special_single[i] = 1;
            special.push_back(special_single);
        }

        dfs(special, needs, 0, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& special, vector<int>& needs, int cost, int index)
    {
        if(cost > ans)
            return ;

        int leave = 0;
        for(auto i : needs)
            leave += i;

        if(leave == 0)
        {
            cout<<cost<<endl;
            ans = min(ans, cost);
        }

        int n = special.size();
        for (int i = index; i < n; ++i)
        {
            int m = needs.size();
            int ok = true;
            for (int j = 0; j < m; ++j)
            {
                if(special[i][j] > needs[j])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                index = i;
                for (int j = 0; j < m; ++j)
                {
                    needs[j] = needs[j] - special[i][j];
                }
                dfs(special, needs, cost + special[i][m], index);
                for (int j = 0; j < m; ++j)
                {
                    needs[j] = needs[j] + special[i][j];
                }

            }
        }
    }
};