class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        
        vector<int> ans;
        for(int i = 2; i * i <= num; ++i)
        {
            while(num % i == 0)
            {
                num = num / i;
                ans.emplace_back(i);
            }
            // if(num == 1)
            //     break;
        }
        if(num != 1)
            ans.emplace_back(num);

        return ans;
    }
};