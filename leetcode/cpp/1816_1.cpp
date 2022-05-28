class Solution {
public:
    string truncateSentence(string s, int k) {

        string ans;
        int i = 0;
        int n = s.size();
        while(i < n)
        {
            if(s[i] == ' ')
            {
                --k;
                if(!k)
                    break;
            }
            ans.push_back(s[i]);
            ++i;
        }

        return ans;
    }
};