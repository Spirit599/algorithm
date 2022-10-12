class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;

        if(n1 & 1)
        {
            for(int num : nums2)
                ans ^= num;
        }
        if(n2 & 1)
        {
            for(int num : nums1)
                ans ^= num;
        }

        return ans;
    }
};