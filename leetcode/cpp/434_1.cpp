class Solution {
public:
    int countSegments(string s) {
        int ret = 0;
        bool pre_is_blank = true;

        for(char c : s)
        {
            if(c != ' ')
            {
                if(pre_is_blank)
                {
                    ret++;
                    pre_is_blank = false;
                }
            }
            else
            {
                pre_is_blank = true;
            }
        }

        return ret;
    }
};