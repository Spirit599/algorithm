class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index, vector<int>& anss, int n, bool visited[]) {

        printf("index = %d\n", index);
        if(n == index)
        {
            ans.push_back(anss);
            return ;
        }

        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                visited[i] = true;
                anss[index] = nums[i];
                dfs(nums, index + 1, anss, n, visited);
                visited[i] = false;
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        vector<int> anss(n);
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        dfs(nums, 0, anss, n, visited);
        return ans;
    }
};