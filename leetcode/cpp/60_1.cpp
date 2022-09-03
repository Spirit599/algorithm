// 60. 排列序列

class Solution {
public:
    string getPermutation(int n, int k) {

        int factorial[10];
        factorial[1] = 1;
        for(int i = 2; i <= 9; ++i)
            factorial[i] = factorial[i - 1] * i;

        bool visit[10];
        memset(visit, 0, sizeof(visit));

        string ans;
        while(n)
        {
            int order = (k - 1) / (factorial[n - 1]) + 1;
            k = (k - 1) % (factorial[n - 1]) + 1;
            n--;
            int cur = 0;
            for(int i = 1; i <= 9; ++i)
            {
                if(!visit[i])
                {
                    ++cur;
                    if(cur == order)
                    {
                        visit[i] = true;
                        ans.push_back('0' + i);
                        break;
                    }
                }
            }
        }

        return ans;

    }
};