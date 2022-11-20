bool checkPrime(int num, int n)
{
    if(num < n || num < 2)
        return false;

    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

class Solution {
public:
    int primePalindrome(int n) {

        string str = to_string(n);
        int strSize = str.size();
        int len;
        string tmp;

        function<int(int)> dfs = [&](int depth)
        {
            if(depth == (len + 1) / 2)
            {
                int num = atoi(tmp.c_str());
                // printf("%d\n", num);
                if(!checkPrime(num, n))
                    return -1;
                else
                    return num;
            }


            if(depth == 0)
            {
                for(int i = 1; i <= 9; ++i)
                {
                    tmp[depth] = i + '0';
                    tmp[len - depth - 1] = i + '0';
                    int ret = dfs(depth + 1);
                    if(ret != -1)
                        return ret;
                }
            }
            else
            {
                for(int i = 0; i <= 9; ++i)
                {
                    tmp[depth] = i + '0';
                    tmp[len - depth - 1] = i + '0';
                    int ret = dfs(depth + 1);
                    if(ret != -1)
                        return ret;
                }
            }

            return -1;

        };

        for(len = strSize; len <= 9; ++len)
        {
            tmp.resize(len);
            int ret = dfs(0);
            if(ret != -1)
                return ret;
        }

        return 0;
    }
};