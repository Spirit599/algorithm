class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = queries.size();
        vector<int> ans(n);
        int evenSum = 0;
        for(int num : nums)
        {
            if((num & 1) == 0)
                evenSum += num;
        }

        for(int i = 0; i < n; ++i)
        {
            int dif = queries[i][0];
            int idx = queries[i][1];

            if((nums[idx] & 1 ) == 0)
                evenSum -= nums[idx];
            nums[idx] += dif;
            if((nums[idx] & 1 ) == 0)
                evenSum += nums[idx];
            ans[i] = evenSum;
        }

        return ans;
    }
};