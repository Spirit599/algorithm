class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        set<int> ans;
        for(int n1 : nums1)
        {
            for(int n2 : nums2)
            {
                if(n1 == n2)
                {
                    ans.emplace(n1);
                }
            }
        }

        for(int n3 : nums3)
        {
            for(int n2 : nums2)
            {
                if(n3 == n2)
                {
                    ans.emplace(n3);
                }
            }
        }

        for(int n1 : nums1)
        {
            for(int n3 : nums3)
            {
                if(n1 == n3)
                {
                    ans.emplace(n1);
                }
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};