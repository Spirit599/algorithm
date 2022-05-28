class Solution {
public:
    int findTheWinner(int n, int k) {

        int out = 0;
        bool visit[n];
        memset(visit, 0, sizeof(visit));

        int i = -1;
        while(out != n - 1)
        {
            int step = 0;
            while(step != k)
            {
                ++i;
                if(i == n)
                    i = 0;

                if(!visit[i])
                    ++step;
            }
            visit[i] = true;
            ++out;
        }

        for (int i = 0; i < n; ++i)
        {
            if(!visit[i])
            {
                return i + 1;
            }
        }

        return 0;
    }
};