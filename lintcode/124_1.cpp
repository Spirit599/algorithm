class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        unordered_set<int> memo(num.begin(), num.end());

        int ans = 0;

        while(!memo.empty())
        {
            int cur = *(memo.begin());
            memo.erase(cur);

            int cnt = 1;

            int cur_up = cur + 1;
            auto it = memo.find(cur_up);
            while(it != memo.end())
            {
                ++cnt;
                ++cur_up;
                memo.erase(it);

                it = memo.find(cur_up);
            }

            int cur_down = cur - 1;
            auto it1 = memo.find(cur_down);
            while(it1 != memo.end())
            {
                ++cnt;
                --cur_down;
                memo.erase(it1);

                it1 = memo.find(cur_down);
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};