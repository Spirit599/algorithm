//回文


class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        
        int Palindrome_length = intLength - (intLength / 2);

        long long bits = 1;
        for(int i = 0; i < Palindrome_length - 1; ++i)
            bits = bits * 10;

        vector<long long> ans;
        vector<int> tmp_arr(intLength);

        for(int kk : queries)
        {
            long long bit = bits;
            --kk;

            if(kk / bit >= 9)
            {
                ans.push_back(-1);
                continue;
            }

            tmp_arr[0] = tmp_arr[intLength - 1] = (kk / bit) + 1;

            kk = kk - (kk / bit) * bit;
            bit = bit / 10;

            for(int i = 1; i < Palindrome_length; ++i)
            {
                tmp_arr[i] = tmp_arr[intLength - i - 1] = kk / bit;
                
                kk = kk - (kk / bit) * bit;
                bit = bit / 10;
            }

            long long anss = 0;
            for(int i : tmp_arr)
            {
                anss = 10 * anss + i;
            }
            ans.push_back(anss);
            // for(int i : tmp_arr)
            // {
            //     printf("%d ",i);
            // }
            // printf("\n");
        }

        return ans;
    }
};