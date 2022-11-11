// 二进制枚举

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        function<void(int, vector<int>&)> dfs = [&](int cur, vector<int>& arr) {

            if(cur == n)
            {
                if(arr.size() >= 2)
                    ans.push_back(arr);
                return ;
            }

            if(arr.empty() || arr.back() != nums[cur])
                dfs(cur + 1, arr);

            if(arr.empty() || arr.back() <= nums[cur])
            {
                arr.push_back(nums[cur]);
                dfs(cur + 1, arr);
                arr.pop_back();
            }

        };

        vector<int> arr;
        dfs(0, arr);
        return ans;
    }
};