class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        unordered_set<int> memo;
        for(int num : nums)
            memo.insert(num);
        for(int i = 0; i <= 30; ++i)
        {
            if(memo.count(1 << i) == 0)
                return 1 << i;
        }
        return 0;
    }
};