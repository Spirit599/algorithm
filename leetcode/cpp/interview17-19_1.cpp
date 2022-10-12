// 消失的两个数字


class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int missSum = (n + 3) * (n + 2) / 2 - sum;
        //printf("missSum = %d\n", missSum);
        int split = missSum / 2;
        int splitSum = (split + 1) * split / 2;
        int oneSum = 0;
        for (int i = 0; i < n; ++i)
        {
            if(nums[i] <= split)
                oneSum += nums[i];
        }
        int one = splitSum - oneSum;
        return vector<int>({one, missSum - one});

    }
};