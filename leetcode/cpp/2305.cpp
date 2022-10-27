class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        int ans = INT_MAX;
        int arr[k];
        memset(arr, 0, sizeof(arr));
        int n = cookies.size();
        sort(cookies.begin(), cookies.end(), greater<int>());

        function<void(int, int)> dfs = [&](int depth, int curMax) -> void {

            // printf("%d\n", depth);
            if(curMax > ans)
                return ;
            if(depth == n)
            {
                ans = min(ans, curMax);
                return;
            }
            for(int i = 0; i < k; ++i)
            {
                arr[i] += cookies[depth];
                dfs(depth + 1, max(curMax ,arr[i]));
                arr[i] -= cookies[depth];
            }
        };

        dfs(0, 0);
        return ans;
    }
};