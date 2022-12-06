class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        vector<int> ans;
        
        for(int num : nums)
        {
            ans.emplace_back(num);
            while(ans.size() >= 2)
            {
                int last = ans[ans.size() - 1];
                int preLast = ans[ans.size() - 2];
                int numGcd = gcd(last, preLast);
                if(numGcd == 1)
                    break;
                ans.pop_back();
                ans.back() *= last / numGcd; 
            }
        }
        return ans;
    }
};