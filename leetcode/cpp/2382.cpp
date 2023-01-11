class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        
        int n = removeQueries.size();
        vector<long long> ans(n);

        vector<int> arr(nums);
        int m = nums.size();

        for(int i = 0; i < n; ++i)
            arr[removeQueries[i]] = 0;

        int fa[m];
        memset(fa, -1, sizeof(fa));

        long long score[m];
        score[0] = arr[0];
        long long maxx = arr[0];

        auto findFa = [&](int x) -> int
        {
            while(fa[x] != -1)
                x = fa[x];
            return x;
        };
        auto unionNode = [&](int x, int y)
        {
            int fx = findFa(x);
            int fy = findFa(y);
            if(fx == fy)
                return ;
            fa[fx] = fy;
            score[fy] += score[fx];
            maxx = max(maxx, score[fy]);
        };

        for(int i = 1; i < m; ++i)
        {
            score[i] = arr[i];
            maxx = max(maxx, score[i]);
            if(score[i] != 0 && score[i - 1] != 0)
                unionNode(i, i - 1);
        }
        
        for(int i = n - 1; i >= 0; --i)
        {
            ans[i] = maxx;
            int index = removeQueries[i];
            arr[index] = nums[index];
            score[index] = arr[index];
            maxx = max(maxx, score[index]);
            if(index > 0 && arr[index - 1] != 0)
                unionNode(index, index - 1);
            if(index < n - 1 && arr[index + 1] != 0)
                unionNode(index, index + 1);

            
            
        }

        return ans;

    }
};