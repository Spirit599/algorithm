class Solution {
public:
    int nextGreaterElement(int n) {

        string str = to_string(n);
        int strSize = str.size();

        int idx1 = strSize - 2;
        for(; idx1 >= 0; --idx1)
        {
            if(str[idx1] < str[idx1 + 1])
                break;
        }
        if(idx1 == -1)
            return -1;
        int idx2 = strSize - 1;
        for(; idx2 >= 0; --idx2)
        {
            if(str[idx2] > str[idx1])
                break;
        }

        swap(str[idx1], str[idx2]);
        reverse(str.begin() + idx1 + 1, str.end());
        long long ans = atoll(str.c_str());

        if(ans <= INT_MAX)
            return ans;
        else
            return -1;
    }
};