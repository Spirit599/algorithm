class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {

        unordered_map<int, int> um;
        for(int num : nums)
        {
            ++um[num];
            if(um[num] == 2)
                return num;
        }

        return -1;
    }
};