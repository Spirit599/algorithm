class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        
        unordered_map<int, int> memo1;
        unordered_map<int, int> memo2;

        for(int num : nums1)
            ++memo1[num];
        for(int num : nums2)
            ++memo2[num];

        vector<int> ans;

        for(auto& kav : memo1)
        {
            int n1 = kav.second;
            int n2 = 0;
            if(memo2.count(kav.first) == 1)
                n2 = memo2[kav.first];

            for(int i = 0; i < min(n1, n2); i++)
                ans.emplace_back(kav.first);
        }

        return ans;
    }
};