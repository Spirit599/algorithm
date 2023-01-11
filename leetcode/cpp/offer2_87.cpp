class Solution {
public:
    vector<string> ans;
    int sLen;
    void dfs(vector<int>& nums, string& s, int depth)
    {
        int n = nums.size();
        if(n == 4 && depth == sLen)
        {
            ans.push_back(to_string(nums[0]) + '.' + to_string(nums[1]) + '.' + to_string(nums[2]) + '.' + to_string(nums[3]));
            return ;
        }
        if(n > 4 || depth == sLen)
            return ;
        nums.push_back(s[depth] - '0');
        dfs(nums, s, depth + 1);
        nums.pop_back();

        int& cur = nums[n - 1];
        if(cur != 0 && cur * 10 + s[depth] - '0' <= 255)
        {
            cur = cur * 10 + s[depth] - '0';
            dfs(nums, s, depth + 1);
        }


    }
    vector<string> restoreIpAddresses(string s) {

        if(s == "")
            return ans;

        vector<int> nums;
        nums.push_back(s[0] - '0');
        sLen = s.size();
        dfs(nums, s, 1);

        return ans;
    }
};