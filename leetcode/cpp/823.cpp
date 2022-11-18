const int MOD = 1e9 + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        int ans = 0;
        unordered_map<int, int> memo;
        int n = arr.size();

        for(int i = 0; i < n; ++i)
        {
            int cur = 1;
            for(int j = 0; j < i; ++j)
            {
                if(arr[i] % arr[j])
                    continue;
                int other = arr[i] / arr[j];
                auto it = memo.find(other);
                if(it == memo.end())
                    continue;
                int k = 1ll * it->second * memo[arr[j]] % MOD;
                cur = (cur + k) % MOD;
            }
            ans = (ans + cur) % MOD;
            memo[arr[i]] = cur;
        }

        return ans;
    }
};