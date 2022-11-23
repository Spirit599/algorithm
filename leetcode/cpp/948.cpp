class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int k = 0;
        int ans = 0;
        int right = n - 1;
        for(int i = 0; i <= right; ++i)
        {
            // printf("%d %d %d\n", i,k,power);
            
            while(power < tokens[i] && i <= right)
            {
                if(k > 0)
                {
                    power += tokens[right];
                    --k;
                    --right;
                }
                else
                {
                    break;
                }
            }
            if(power - tokens[i] >= 0)
            {
                power -= tokens[i];
                ++k;
                ans = max(ans, k);
            }
        }

        
        return ans;
    }
};