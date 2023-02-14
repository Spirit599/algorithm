class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        unordered_map<int, int> memo;
        for(int num : basket1)
            ++memo[num];
        for(int num : basket2)
            ++memo[num];
        int minn = INT_MAX;
        for(auto& [k, v] : memo)
        {
            if(v & 1)
                return -1;
            else
                v = v >> 1;
            minn = min(minn, k);
        }

        for(int num : basket1)
            --memo[num];
        vector<int> arr;
        for(auto [k, v] : memo)
        {
            if(v == 0)
                continue;
            if(v < 0)
                v = -v;
            for(int i = 0; i < v; ++i)
            {
                arr.emplace_back(k);
            }
        }

        int as = arr.size();
        sort(arr.begin(), arr.end());
        int half = as >> 1;
        long long ans = 0;
        for(int i = 0; i < half; ++i)
        {
            ans += min(arr[i], 2 * minn);
        }

        
        return ans;
    }
};