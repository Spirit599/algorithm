class Solution {
public:
    /**
     * @param encodeString: an encode string
     * @return: a reversed decoded string
     */
    string reverseAsciiEncodedString(string &encodeString) {
        
        string ans;

        int cnt = 0;
        char cc = 0;
        for(char c : encodeString)
        {
            ++cnt;
            cc = 10 * cc + c - '0';

            if((cnt & 1) == 0)
            {
                ans.push_back(cc);
                cc = 0;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};