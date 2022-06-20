// 18 · 子集 II

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     *          we will sort your return value in output
     */
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index, vector<int>& arr, int visit[])
    {
        ans.push_back(arr);

        int n = nums.size();
        for(int i = index; i < n; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])
                continue;

            arr.push_back(nums[i]);
            visit[i] = 1;
            dfs(nums, i + 1, arr, visit);
            visit[i] = 0;
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        
        vector<int> arr;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int visit[n];
        memset(visit, 0, sizeof(visit));

        dfs(nums, 0, arr, visit);

        return ans;
    }
};