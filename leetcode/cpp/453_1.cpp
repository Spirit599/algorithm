class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int minn = INT_MAX;
        for(auto i : nums)
            minn = min(minn, i);

        int ret = 0;
        for(auto i : nums)
            ret += i - minn;

        return ret;
    }
};