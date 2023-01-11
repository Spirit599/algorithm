class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        
        string str = to_string(n);
        str.insert(str.begin(), '0');
        int strSize = str.size();

        int cnt = 0;
        int i = 0;
        for(; i < strSize; ++i)
        {
            cnt += str[i] - '0';
            if(cnt > target)
                break;
        }
        if(i == strSize)
            return 0;
        for(int j = i + 1; j < strSize; ++j)
            str[j] = '0';

        while(1)
        {
            setCurBitZero(i, cnt, str);
            if(cnt <= target)
                break;
        }

        long long after = 0;
        for(int i = 0; i < strSize; ++i)
            after = after * 10 + str[i] - '0';

        return after - n;
    }

    void setCurBitZero(int& i, int& cnt, string& str)
    {
        cnt -= (str[i] - '0' - 1);
        str[i] = '0';
        --i;
        ++str[i];
        while(str[i] == '0' + 10)
        {
            str[i] = '0';
            --i;
            ++str[i];
            cnt -= 9;
        }
    }

};