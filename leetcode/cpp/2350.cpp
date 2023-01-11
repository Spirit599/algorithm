class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        int ans = 1;
        int mark[k + 1];
        memset(mark, 0, sizeof(mark));
        int left = k;

        for(int v : rolls)
        {
            if(mark[v] < ans)
            {
                mark[v] = ans;
                if(--left == 0)
                {
                    left = k;
                    ++ans;
                }
            }
        }

        return ans;
    }
};