class Solution {
public:
    long long chageToPaliWithoutLast(long long num) {

        string str(to_string(num));
        int n = str.size();
        for(int i = n - 2; i >= 0; --i)
            str.push_back(str[i]);

        return stoll(str);
    }
    long long chageToPali(long long num) {

        string str(to_string(num));
        int n = str.size();
        for(int i = n - 1; i >= 0; --i)
            str.push_back(str[i]);

        return stoll(str);
    }
    bool isPali(long long num) {

        string str(to_string(num));
        int n = str.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }
    int workForLen(int len, long long upLimit) {

        int ret = 0;
        long long sqrtUpLimit = sqrt(upLimit);
        if(len & 1)
        {
            int halfLen = (len + 1) >> 1;
            long long first = pow(10, halfLen - 1);
            long long end = pow(10, halfLen) - 1;
            while(first <= end)
            {
                long long pali = chageToPaliWithoutLast(first);
                if(pali > sqrtUpLimit)
                    break;

                if(isPali(pali * pali))
                {
                    ++ret;
                }
                ++first;
            }
        }
        else
        {
            int halfLen = len >> 1;
            long long first = pow(10, halfLen - 1);
            long long end = pow(10, halfLen) - 1;
            while(first <= end)
            {
                long long pali = chageToPali(first);
                if(pali > sqrtUpLimit)
                    break;
                double sqrtPali = sqrt(pali);
                if(isPali(pali * pali))
                {
                    ++ret;
                }
                ++first;
            }
        }
        return ret;
    }
    int oneToNum(string num) {

        int len = num.size();
        int ret = 0;
        for(int i = 1; i <= len; ++i)
        {
            ret += workForLen(i, stoll(num));
        }


        return ret;
    }
    int superpalindromesInRange(string left, string right) {



        return oneToNum(right) - oneToNum(to_string(stoll(left) - 1));
    }
};