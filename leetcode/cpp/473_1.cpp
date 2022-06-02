//dfs
//可状压

class Solution {
private:
    int n;
    int square;
    int edges[4];
    bool ans = false;
public:
    void dfs(int depth, vector<int>& matchsticks)
    {
        if(ans == true)
            return ;

        if(depth == n)
        {
            ans = true;
            return ;
        }

        for(int i = 0; i < 4; ++i)
        {
            if(matchsticks[depth] + edges[i] <= square)
            {
                edges[i] += matchsticks[depth];
                dfs(depth + 1, matchsticks);
                edges[i] -= matchsticks[depth];
            }
        }
    }
    bool makesquare(vector<int>& matchsticks) {

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if(sum % 4 != 0)
            return false;

        sort(matchsticks.begin(), matchsticks.end(), greater());

        square = sum / 4;
        n = matchsticks.size();
        memset(edges, 0, sizeof(edges));

        dfs(0, matchsticks);  

        return ans;      
    }
};