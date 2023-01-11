const int MOD = 10e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int left[n];
        memset(left, -1, sizeof(left));
        int right[n];
        for(int i = 0; i < n; ++i)
            right[i] = n;

        stack<int> sta;
        for(int i = 0; i < n; ++i)
        {
            while(!sta.empty() && arr[sta.top()] >= arr[i])
            {
                right[sta.top()] = i;
                sta.pop();
            }
            if(!sta.empty())
                left[i] = sta.top();
            sta.push(i);
        }
        // for(int i = 0; i < n; ++i)
        //     printf("%d ", left[i]);
        // printf("\n");
        // for(int i = 0; i < n; ++i)
        //     printf("%d ", right[i]);
        // printf("\n");

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            // int dif = right[i] - left[i];
            // int cnt = (dif + 1) * dif / 2;
            int l = i - left[i];
            int r = right[i] - i;
            // printf("%d %d\n", l,r);
            ans = (ans + 1ll * l * r * arr[i]) % MOD;
        }

        return ans;
    }
};