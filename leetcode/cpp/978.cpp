class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();
        if(n == 1)
            return 1;
        if(n == 2)
            return arr[0] == arr[1] ? 1 : 2;

        int cur = 0;
        int ans = 0;
        for(int i = 2; i < n; ++i)
        {
            if(1ll * (arr[i] - arr[i - 1]) * (arr[i - 1] - arr[i - 2]) < 0)
            {
                if(cur >= 3)
                    ++cur;
                else
                    cur = 3;
            }
            else if((arr[i] - arr[i - 1]) == 0 && (arr[i - 1] - arr[i - 2]) == 0)
            {
                cur = 1;
            }
            else
            {
                cur = 2;
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};