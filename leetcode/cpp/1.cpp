class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
       
       set<int> ans;
       for (int i = 0; i < digits.size(); ++i)
        {
            for (int j = i + 1; j < digits.size(); ++j)
            {
                for (int k = j + 1; k < digits.size(); ++k)
                {
                    if(digits[i] % 2 == 0)
                    {
                        if(digits[k] != 0)
                            ans.insert(digits[k] * 100 + digits[j] * 10 + digits[i]);
                        if(digits[j] != 0)
                            ans.insert(digits[j] * 100 + digits[k] * 10 + digits[i]);
                    }
                    if(digits[j] % 2 == 0)
                    {
                        if(digits[i] != 0)
                            ans.insert(digits[i] * 100 + digits[k] * 10 + digits[j]);
                        if(digits[k] != 0)
                            ans.insert(digits[k] * 100 + digits[i] * 10 + digits[j]);
                    }
                    if(digits[k] % 2 == 0)
                    {
                        if(digits[i] != 0)
                            ans.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                        if(digits[j] != 0)
                            ans.insert(digits[j] * 100 + digits[i] * 10 + digits[k]);
                    }
                }
            }
        }

        return {ans.begin(), ans.end()}; 
    }
};