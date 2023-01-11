class Solution {
public:
    int maximumSwap(int num) {

        string str = to_string(num);
        int n = str.size();

        char rightMax[n];
        memset(rightMax, 0, sizeof(rightMax));
        rightMax[n - 1] = str[n - 1];

        for(int i = n - 2; i >= 0; --i)
        {
            rightMax[i] = max(rightMax[i + 1], str[i]);
        }

        for(int i = 0; i < n; ++i)
        {
            if(rightMax[i] != str[i])
            {
                for(int j = n - 1; j > i; --j)
                {
                    if(str[j] == rightMax[i])
                    {
                        swap(str[j], str[i]);
                        break;
                    }
                }
                break;
            }
        }



        return atoi(str.c_str());
    }
};