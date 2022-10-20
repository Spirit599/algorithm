class Solution {
public:
    vector<int> edgess[20005];
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {

        for(auto& edge : edges)
        {
            edgess[edge[0]].push_back(edge[1]);
            edgess[edge[1]].push_back(edge[0]);
        }

        int target = -1;
        function<int(int,int)> dfs = [&](int cur, int fa) -> int {
            int sum = nums[cur];
            for(int next : edgess[cur])
            {
                if(next != fa)
                {
                    int ret = dfs(next, cur);
                    if(ret < 0)
                        return -1;
                    sum += ret;
                }
            }
            if(sum > target)
                return -1;
            else if(sum < target)
                return sum;
            else
                return 0;
        };

        int all = accumulate(nums.begin(), nums.end(), 0);
        int maxx = *max_element(nums.begin(), nums.end());
        
        for(int i = all / maxx; i >= 1; --i)
        {
            if(all % i == 0)
            {
                target = all / i;
                if(dfs(0, -1) == 0)
                    return i - 1;
            }
        }

        return 0;
    }
};