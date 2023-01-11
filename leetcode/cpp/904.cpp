class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int ans = 0;
        unordered_map<int, int> memo;
        int n = fruits.size();

        int left = -1;
        for(int right = 0; right < n; ++right)
        {
            ++memo[fruits[right]];
            
            while(memo.size() > 2 && left < right)
            {
                ++left;
                if(--memo[fruits[left]] == 0)
                    memo.erase(fruits[left]);
            }

            ans = max(ans, right - left);
        }
        return ans;
    }
};