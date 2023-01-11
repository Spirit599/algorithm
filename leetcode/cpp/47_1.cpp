class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index, vector<int>& anss, int n, bool visited[]) {

        if(n == index)
        {
            ans.push_back(anss);
            return ;
        }

        for(int i = 0; i < n; ++i)
        {
            if(i - 1 >= 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            if(!visited[i])
            {
                visited[i] = true;
                anss[index] = nums[i];
                dfs(nums, index + 1, anss, n, visited);
                visited[i] = false;
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> anss(n);
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        dfs(nums, 0, anss, n, visited);
        return ans;
    }
};