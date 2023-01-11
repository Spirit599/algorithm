class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; ++i)
        {
            long long key = ceil(success * 1.0 / spells[i]);
            if(key > 0x3f3f3f3f)
                printf("%d\n", key);
            auto it = lower_bound(potions.begin(), potions.end(), key);
            ans[i] = potions.end() - it;
        }
        return ans;
    }
};