class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        
        unordered_map<int, int> memo;

        for(int num : nums)
        {
            ++memo[num];
        }

        int ans = 0;
        for(auto& kav : memo)
        {
            nums[ans] = kav.first;
            ++ans;
        }

        return ans;
    }
};