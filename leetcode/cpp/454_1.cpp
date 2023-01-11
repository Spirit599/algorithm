class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int ,int> memo;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();
        int n4 = nums4.size();
        int ans = 0;
        for(int i = 0; i < n1; ++i)
        {
            for(int j = 0; j < n2; ++j)
            {
                int sum = nums1[i] + nums2[j];
                auto it = memo.find(sum);
                if(it != memo.end())
                    ++(it->second);
                else
                    memo[sum] = 1;
            }
        }

        for(int i = 0; i < n3; ++i)
        {
            for(int j = 0; j < n4; ++j)
            {
                int sum = nums3[i] + nums4[j];
                auto it = memo.find(-sum);
                if(it != memo.end())
                    ans += it->second;
            }
        }

        return ans;
    }
};