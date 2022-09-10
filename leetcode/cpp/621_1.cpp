// 621. 任务调度器

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int memo[100];
        memset(memo, 0, sizeof(memo));

        for(char c : tasks)
            ++memo[c];

        int ans = 0;
        vector<int> nums;
        for(int i = 0; i < 100; ++i)
        {
            if(memo[i] != 0)
            {
                nums.push_back(memo[i]);
                ans += memo[i];
            }
        }

        auto pmax = max_element(nums.begin(), nums.end());
        int maxn = *pmax;

        nums.erase(pmax);

        int wait = n * (maxn - 1);
        for(int num : nums)
        {
            cout<<num<<endl;
            wait -= min(maxn - 1, num);
        }

        ans += max(wait, 0);
        return ans;
    }
};