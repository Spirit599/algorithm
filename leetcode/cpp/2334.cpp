class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        

        int n = nums.size();
        int left[n];
        memset(left, -1, sizeof(left));
        int right[n];
        memset(right, -1, sizeof(right));

        vector<int> upStk;
        for(int i = 0; i < n; ++i)
        {
            while(!upStk.empty() && nums[upStk.back()] > nums[i])
            {
                right[upStk.back()] = i;
                upStk.pop_back();
            }

            if(!upStk.empty())
                left[i] = upStk.back();
            upStk.emplace_back(i);
        }


        for(int i = 0; i < n; ++i)
        {
            if(right[i] == -1)
                right[i] = n;

            int len = right[i] - left[i] - 1;
            if(nums[i] > threshold / len)
                return len;

            printf("%d %d\n", left[i], right[i]);
        }

        return -1;
    }
};
