class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;
        vector<int> nums;
        int n = s.size();
        nums.emplace_back(s[0] - '0');

        function<void(int)> dfs = [&](int depth) {

            if(depth == n)
            {
                if(nums.size() == 4)
                {
                    ans.emplace_back(to_string(nums[0]) + '.' + to_string(nums[1]) + '.' + to_string(nums[2]) + '.' + to_string(nums[3]));
                }
                return;
            }
            if(nums.size() > 4)
                return ;

            nums.emplace_back(s[depth] - '0');
            dfs(depth + 1);
            nums.pop_back();

            int& cur = nums.back();
            if(cur != 0 && 10 * cur + s[depth] - '0' <= 255)
            {
                cur = 10 * cur + s[depth] - '0';
                dfs(depth + 1);
            }

        };

        dfs(1);
        return ans;
    }
};