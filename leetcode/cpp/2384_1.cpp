//哈希
//回文

class Solution {
public:
    string largestPalindromic(string num) {
        
        int arr[10];
        memset(arr, 0, sizeof(arr));

        string ans;
        bool odd;
        char mid = 0;

        for(char c : num)
        {
            ++arr[c - '0'];
        }

        for(int i = 9; i >= 0; --i)
        {
            
            if(i == 0 && ans.size() == 0)
                break;

            if(arr[i] & 1)
            {
                if(mid == 0)
                    mid = '0' + i;

                ans.append(arr[i] >> 1, '0' + i);
            }
            else
            {
                ans.append(arr[i] >> 1, '0' + i);
            }
            
        }

        string copy = ans;
        reverse(copy.begin(), copy.end());

        if(mid)
            ans.push_back(mid);
        ans = ans + copy;

        if(ans == "")
            ans = "0";

        return ans;
    }
};