class Solution {
public:
    vector<int> maxCnt(vector<int>& v1, vector<int>& v2)
    {
        int n = v1.size();
        int s1 = 0;
        int s2 = 0;
        for(int i = 0; i < n; ++i)
        {
            s1 += v1[i];
            s2 += v2[i];
        }
        if(s1 < s2)
            return v2;
        else if(s1 > s2)
            return v1;

        return v1 > v2 ? v1 : v2;

    }
    string largestNumber(vector<int>& cost, int target) {

        int n = cost.size();
        vector<int> dp[target + 1];
        dp[0] = vector<int>(n);

        for(int i = 0; i < n; ++i)
        {
            for(int j = cost[i]; j <= target; ++j)
            {
                if(dp[j - cost[i]].size() != 0)
                {
                    vector<int> v1 = dp[j];
                    vector<int> v2 = dp[j - cost[i]];
                    ++v2[n - i - 1];
                    dp[j] = maxCnt(v1, v2);
                }
            }
        }


        if(dp[target].size() == 0)
            return "0";
        string ans;
        for(int i = 0; i < n; ++i)
        {
            if(dp[target][i] != 0)
                ans.append(dp[target][i], '0' + n - i);
        }
        return ans;
    }
};