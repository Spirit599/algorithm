class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {

        int ans = 3000;
        int n = fronts.size();
        unordered_set<int> memo;

        for(int i = 0; i < n; ++i)
        {
            if(fronts[i] == backs[i])
                memo.insert(fronts[i]);
        }
        for(int i = 0; i < n; ++i)
        {
            if(!memo.count(fronts[i]))
                ans = min(ans, fronts[i]);
            if(!memo.count(backs[i]))
                ans = min(ans, backs[i]);
        }
        return ans != 3000 ? ans : 0;
    }
};