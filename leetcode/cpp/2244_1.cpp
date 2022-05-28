class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int, int> memo;
        for(int num : tasks)
            ++memo[num];

        int ans = 0;

        for(const auto& kav : memo)
        {
            if(kav.second == 1)
                return -1;

            ans += ceil(kav.second / 3.0);
        }

        return ans;
    }
};