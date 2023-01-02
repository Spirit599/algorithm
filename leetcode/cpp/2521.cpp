class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        
        unordered_set<int> memo;

        auto getBase = [&](int num) {

            for(int i = 2; i * i <= num; ++i)
            {
                if(num % i == 0)
                {
                    memo.emplace(i);
                    while(num % i == 0)
                    {
                        num /= i;
                    }
                }
            }

            if(num != 1)
                memo.emplace(num);
        };

        for(int num : nums)
        {
            getBase(num);
        }

        return memo.size();
    }
};