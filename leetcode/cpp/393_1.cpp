class Solution {
public:
    bool between(int num,int up, int down)
    {
        return up >= num && num >= down;
    }
    bool validUtf8(vector<int>& data) {

        int four_11110_up = 247;
        int four_11110_down = 240;

        int three_1110_up = 339;
        int three_1110_down = 224;

        int two_110_up = 223;
        int two_110_down = 192;

        int one_10_up = 191;
        int one_10_down = 128;

        int zero_0_up = 127;
        int zero_0_down = 0;

        //int new_symbol = 1;
        int suffix = 0;

        for(int num : data)
        {
            if(suffix == 0)
            {
                if(between(num, four_11110_up, four_11110_down))
                {
                    suffix = 3;
                }
                else if(between(num, three_1110_up, three_1110_down))
                {
                    suffix = 2;
                }
                else if(between(num, two_110_up, two_110_down))
                {
                    suffix = 1;
                }
                else if(between(num, zero_0_up, zero_0_down))
                {
                    suffix = 0;
                }
                else
                {
                    return false;
                }
            }
            else if(suffix > 0)
            {
                if(between(num, one_10_up, one_10_down))
                {
                    --suffix;
                }
                else
                {
                    return false;
                }
            }
        }

        return suffix == 0;
    }
};