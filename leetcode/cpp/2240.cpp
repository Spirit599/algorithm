class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long long ans = 0;

        for(int i = 0; i * cost1 <= total; ++i)
        {
            int have = total - i * cost1;
            ans += have / cost2 + 1;
        }

        return ans;
    }
};