//不需要额外的空间

class Solution {
public:
    string replaceSpaces(string S, int length) {

        int i = length - 1;
        int j = S.size() - 1;
        while(i >= 0)
        {

            if(S[i] != ' ')
            {
                S[j] = S[i];
                --j;
                --i;
            }
            else
            {
                S[j] = '0';
                S[j - 1] = '2';
                S[j - 2] = '%';
                --i;
                j = j - 3;
            }
        }
        return S.substr(j - i);
    }
};