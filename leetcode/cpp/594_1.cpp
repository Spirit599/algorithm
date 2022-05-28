//map nlogn

class Solution {
public:
    int findLHS(vector<int>& nums) {

        map<int, int> memo;
        for(int num : nums)
            ++memo[num];

        int ans = 0;
        auto it2 = memo.begin();
        auto it1 = it2++;
        for (;it2 != memo.end(); ++it2,++it1)
        {
            if(it2->first - it1->first == 1)
            {
                ans = max(ans, it2->second + it1->second);
            }
        }

        return ans;
    }
};