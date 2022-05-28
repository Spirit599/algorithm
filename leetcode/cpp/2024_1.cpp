//滑动窗口


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int ans = 0;
        int T_num = 0;
        int F_num = 0;
        int start = -1;
        int end = -1;

        while(end != answerKey.size())
        {
            if(min(T_num, F_num) <= k)
            {
                ++end;
                if(end != answerKey.size())
                {
                    if(answerKey[end] == 'T')
                        ++T_num;
                    else
                        ++F_num;
                }
            }
            else
            {
                ++start;
                if(answerKey[start] == 'T')
                        --T_num;
                    else
                        --F_num;
            }

            ans = max(ans, end - start);
            //printf("%d %d\n",end, start);
        }

        return ans - 1;
    }
};