class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int slots[40];
        memset(slots, 0, sizeof(slots));

        for(int num : candidates)
        {
            int cur = 0;
            while(num)
            {
                if(num & 1)
                    ++slots[cur];
                num = num >> 1;
                ++cur;
            }
        }
        int ans = 0;
        for(int i = 0; i < 35; ++i)
        {
            ans = max(ans, slots[i]);
        }
        return ans;
    }
};