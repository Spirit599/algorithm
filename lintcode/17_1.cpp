// 17 · 子集 I

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     *          we will sort your return value in output
     */
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index, vector<int>& arr)
    {
        ans.push_back(arr);

        int n = nums.size();
        for(int i = index; i < n; ++i)
        {
            arr.push_back(nums[i]);
            dfs(nums, i + 1, arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        
        vector<int> arr;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, arr);

        return ans;
    }
};