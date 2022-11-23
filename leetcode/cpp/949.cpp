class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {

        int n = 4;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        vector<int> clock;
        string ans;

        function<void(int)> dfs = [&](int depth) {

            if(depth == 4)
            {
                int hour = 10 * clock[0] + clock[1];
                int min = 10 * clock[2] + clock[3];
                if(hour < 24 && min < 60)
                {
                    
                    string tmp = to_string(clock[0]) + to_string(clock[1]) + ":" + to_string(clock[2]) + to_string(clock[3]);
                    ans = max(ans, tmp);
                }
                return ;
            }

            for(int i = 0; i < n; ++i)
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    clock.emplace_back(arr[i]);
                    dfs(depth + 1);
                    clock.pop_back();
                    vis[i] = false;
                }
            }
        };

        dfs(0);
        return ans;
    }
};