class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int vis[40];
        memset(vis, 0, sizeof(vis));
        int n2 = 0;
        while(num2)
        {
            if(num2 & 1)
                ++n2;
            num2 = num2 >> 1;
        }
        int k = 0;
        while(num1)
        {
            if(num1 & 1)
            {
                vis[k] = 1;
            }
            ++k;
            num1 = num1 >> 1;
        }

        // printf("%d\n", n2);
        for(int i = 39; i >= 0 && n2; --i)
        {
            if(vis[i] == 1)
            {
                --n2;
                // printf("i = %d\n", i);
                vis[i] = 2;
            }
        }
        for(int i = 0; i < 39 && n2; ++i)
        {
            if(vis[i] == 0)
            {
                --n2;
                vis[i] = 3;
            }
        }
        int ans = 0;
        for(int i = 0; i < 39; ++i)
        {
            if(vis[i] >= 2)
                ans += pow(2, i);
        }
        return ans;

    }
};