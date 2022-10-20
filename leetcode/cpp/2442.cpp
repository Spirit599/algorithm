class Solution {
public:
    int reverse(int num) {
        int k = 0;
        while(num) {
            k = 10 * k + num % 10;
            num = num / 10;
        }
        return k;
    }
    int countDistinctIntegers(vector<int>& nums) {
        
        unordered_set<int> memo;
        for(int num : nums)
        {
            memo.insert(num);
            memo.insert(reverse(num));
        }
        return memo.size();
    }
};