class Solution {
private:
    vector<int> ans;
    int max_score = 0;
public:
    void dfs(int score, int numArrows, vector<int>& aliceArrows, vector<int>& cur, int index)
    {
        //printf("score = %d\n",score);
        if(max_score < score)
        {
            //printf("%d\n",score);

            max_score = score;
            ans = cur;
        }

        for(int i = index; i < aliceArrows.size(); ++i)
        {
            if(numArrows >= aliceArrows[i])
            {
                cur[i] += aliceArrows[i];
                dfs(score + i, numArrows - aliceArrows[i], aliceArrows, cur, i + 1);
                cur[i] -= aliceArrows[i];
            }
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        for (int i = 0; i < aliceArrows.size(); ++i)
            ++aliceArrows[i];

        vector<int> cur(12);

        dfs(0, numArrows, aliceArrows, cur, 0);

        int sum = accumulate(ans.begin(), ans.end(), 0);
        int detal = numArrows - sum;
        ans[0] += detal;

        return ans;
    }
};