class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int allSum = 0;
        int curFi = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            allSum += nums[i];
            curFi += i * nums[i];
        }

        int ans = curFi;
        printf("%d\n", curFi);

        for(int i = 1; i < n; ++i)
        {
            curFi = curFi + n * nums[i - 1] - allSum;
            // printf("%d\n", curF);
            ans = max(ans, curFi);
        }

        return ans;
    }
};