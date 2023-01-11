class Solution {
public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int xr[n], in[n], out[n], clock = 0;
        function<void(int, int)> dfs = [&](int x, int fa) {
            in[x] = ++clock;
            xr[x] = nums[x];
            for (int y : g[x])
                if (y != fa) {
                    dfs(y, x);
                    xr[x] ^= xr[y];
                }
            out[x] = clock;
        };
        dfs(0, -1);

        int ans = INT_MAX;
        for (int i = 2, x, y, z; i < n; ++i)
            for (int j = 1; j < i; ++j) {
                if (in[i] < in[j] && in[j] <= out[i]) x = xr[j], y = xr[i] ^ x, z = xr[0] ^ xr[i]; // i 是 j 的祖先节点
                else if (in[j] < in[i] && in[i] <= out[j]) x = xr[i], y = xr[j] ^ x, z = xr[0] ^ xr[j]; // j 是 i 的祖先节点
                else x = xr[i], y = xr[j], z = xr[0] ^ x ^ y; // 删除的两条边分别属于两颗不相交的子树
                ans = min(ans, max(max(x, y), z) - min(min(x, y), z));
                if (ans == 0) return 0; // 提前退出
            }
        return ans;
    }
};