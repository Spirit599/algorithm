class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        
        
        long long ans = 0;
        int n = nums.size();
        vector<int> oddNums;
        vector<int> oddTarget;
        vector<int> evenNums;
        vector<int> evenTarget;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] & 1)
                oddNums.push_back(nums[i]);
            else
                evenNums.push_back(nums[i]);
            if(target[i] & 1)
                oddTarget.push_back(target[i]);
            else
                evenTarget.push_back(target[i]);
        }
        sort(oddNums.begin(), oddNums.end());
        sort(oddTarget.begin(), oddTarget.end());
        sort(evenNums.begin(), evenNums.end());
        sort(evenTarget.begin(), evenTarget.end());


        int n1 = oddNums.size();
        for(int i = 0; i < n1; ++i)
        {
            int dif = oddNums[i] - oddTarget[i];
            if(dif > 0)
                ans += dif / 2;
        }
        int n2 = evenNums.size();
        for(int i = 0; i < n2; ++i)
        {
            int dif = evenNums[i] - evenTarget[i];
            if(dif > 0)
                ans += dif / 2;
        }
        return ans;
    }
};