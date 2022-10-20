class Solution {
public:
    int rob(vector<int>& nums) {

        int yes = nums[0];
        int no = 0;
        int n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            int nyes = max(yes, no + nums[i]);
            int nno = yes;
            yes = nyes;
            no = nno;
        }
        return max(yes, no);
    }
};