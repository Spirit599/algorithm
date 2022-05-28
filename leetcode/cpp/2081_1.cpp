//进制
//dfs

class Solution {
private:
    long long ans = 0;
public:
    bool is_symm(long long n)
    {
        long long k = 0;
        long long n_copy = n;
        while(n)
        {
            k = 10 * k + n % 10;
            n = n / 10;
        }
        if(n_copy == k)
            return true;
        else
            return false;
    }
    void dfs(int cur[], int len, int depth, int k, int& n, int index)
    {
        if(n == 0)
            return ;

        if(depth >= len)
        {
            long long num = 0;
            for (int i = 0; i < len; ++i)
            {
                num = num * k + cur[i];
            }
            if(is_symm(num))
            {
                ans += num;
                n--;
            }
        }
        else
        {
            for (int i = index; i <= (len - 1) / 2; ++i)
            {
                for (int j = 0; j < k; ++j)
                {
                    if(i == 0 && j == 0)
                        continue;
                    int ci = cur[i];
                    int cli = cur[len - i - 1];
                    cur[i] = j;
                    cur[len - i - 1] = j;
                    //cout<<i<<endl;
                    dfs(cur, len, depth + 2, k, n, i + 1);
                    cur[i] = ci;
                    cur[len - i - 1] = cli;
                }
            }
        }
    }
    long long kMirror(int k, int n) {
        
        ans = 0;

        int len = 1;
        while(1)
        {

            int cur[len];
            //memset(cur, 0, sizeof(cur));
            dfs(cur, len, 0, k, n, 0);
            ++len;
            if(n == 0)
                break;
        }
        return ans;
    }
};